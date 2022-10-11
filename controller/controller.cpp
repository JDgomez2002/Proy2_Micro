#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <vector>
#include <pthread.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "./calculus.cpp"

using namespace std;

pthread_mutex_t mutexTime;
pthread_cond_t condTime;
typedef void *(*THREADFUNCPTR)(void *);

class Controller
{
private:
    int time = 0;
    bool noOneFinished = true;

public:
    vector<Pit> pits;
    vector<Car> cars;
    data::programData initial_values;
    int distance;

    void *task_cars(void *arg)
    {
        Car *p = (Car *)arg;
        while (p->getGlobalDistance() > p->getDistance())
        {
            int randomNum = rand() % 10 + 1;
            p->setSpeed(randomNum);
            p->setDistance();
            cout << "car" << p->getId() << " is running and distance: " << p->getDistance() << endl;
            pthread_cond_wait(&condTime, &mutexTime);
        }
        noOneFinished = false;
        cout << "Car" << p->getId() << " has finish the race." << endl;
        return nullptr;
    }

    void *task_clock(void *arg)
    {
        while (noOneFinished == true)
        {
            time++;
            pthread_cond_signal(&condTime);
            Sleep(20);
        }
        return nullptr;
    }

    void async_cars()
    {
        pthread_t threads_cars[initial_values.carsAmount];
        for (int i = 0; i < initial_values.carsAmount; i++)
        {
            pthread_create(&threads_cars[i], nullptr, (THREADFUNCPTR)&task_cars, &cars.at(i));
        }
        for (int i = 0; i < initial_values.carsAmount; i++)
        {
            pthread_join(threads_cars[i], nullptr);
        }
    }

    void start_race()
    {
        pthread_t thread_clock;
        pthread_create(&thread_clock, nullptr, (THREADFUNCPTR)&task_clock, nullptr);
        async_cars();
        pthread_join(thread_clock, nullptr);
    }

    void distribute()
    {
        int *ptr;
        int arr[initial_values.pitsAmount];
        ptr = calculus::distribution(arr, initial_values.pitsAmount, initial_values.carsAmount);

        int inheritCarsGlobalID = 0;
        for (int i = 0; i < initial_values.pitsAmount; i++)
        {
            vector<Car> inheritCars;
            for (int e = 0; e < ptr[i]; e++)
            {
                inheritCars.push_back(cars[inheritCarsGlobalID]);
                inheritCarsGlobalID++;
            }
            pits.push_back(Pit(i, inheritCars));
        }
    };

    void generate_cars()
    {
        for (int i = 0; i < initial_values.carsAmount; i++)
            cars.push_back(Car(i, initial_values.distance));
    };

    void initializer()
    {
        generate_cars();
        distribute();
        start_race();
    };

    Controller(data::programData initial_values)
    {
        this->initial_values = initial_values;
        distance = initial_values.distance;
        initializer();
    };
};
