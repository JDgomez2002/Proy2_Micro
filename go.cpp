#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <pthread.h>
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "view/format.cpp"
#include "model/car.cpp"
#include "mode/pit.cpp"

void get_user_input();
void objects_initialization();
void print_results();

pthread_cond_t *conditional_variables;
pthread_mutex_t *repair_mutex;
pthread_mutex_t finish_mutex;

int race_distance;
int num_cars;
int num_pits;
bool someone_finish = false;

Format format("-------------------------------------------------------------------------------");

struct car_object
{
    int id;
    int distance;
    bool need_repair;
    bool finish_race;
};
vector<car_object> cars;
vector<int> finish_list;

struct pit_object
{
    vector<car_object> inherit_cars;
};

vector<pit_object> pits;

bool true_false()
{
    int probability = 4;
    int count = 0;
    for (int i = 0; i < probability; i++)
    {
        int rand_int = rand() % 2 + 1;
        count = count + rand_int;
    }
    if (probability * 2 == count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int *distribution(int arr[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        arr[i] = n / m;
        if (i + 1 - m == 0)
        {
            arr[i] = n - n / m * (i);
        }
    }
    return arr;
}

void *task_pit(void *arg)
{
    pit_object *pit = (pit_object *)arg;

    while (pit->inherit_cars.size() != 0)
    {
        for (auto i = pit->inherit_cars.begin(); i != pit->inherit_cars.end(); ++i)
        {
            if (i.finish_race == true)
            {
                pit->inherit_cars.erase(i);
                i--;
            }
        }
        for (int i = 0; i < pit->inherit_cars.size(); i++)
        {
            if (pit->inherit_cars[i].need_repair == true)
            {
                pthread_mutex_lock(&repair_mutex[pit->inherit_cars[i].id]);
                sleep(100);
                pit->inherit_cars[i].need_repair = false;
                pthread_mutex_unlock(&repair_mutex[pit->inherit_cars[i].id]);
                pthread_cond_signal(&conditional_variables[pit->inherit_cars[i].id])
            }
        }
    }
    return nullptr;
}

void *task_car(void *arg)
{
    car_object *car = (car_object *)arg;
    while (race_distance > car->distance)
    {
        int rand_int = rand() % 70 + 60;
        car->distance = car->distance + rand_int;
        car->need_repair = true_false();
        while (car->need_repair == true)
        {
            std::cout << "car " << car->id << " need repair";
            pthread_cond_wait(&conditional_variables[car->id], &repair_mutex[car->id]);
        }
        sleep(30);
    }
    car->finish_race = true;
    pthread_mutex_lock(&finish_mutex);
    finish_list.push_back(car->id);
    pthread_mutex_unlock(&finish_mutex);

    return nullptr;
}

int main()
{
    std::cout << format.divide({"Welcome to the Nascar Race Simulator!", "This is our second project for our Microprocessor Programming course, thanks for using the program!"});

    get_user_input();

    objects_initialization();

    conditional_variables = new pthread_cond_t[num_cars];
    repair_mutex = new pthread_mutex_t[num_cars];

    pthread_t threads_cars[num_cars];
    pthread_t threads_pits[num_pits];

    for (int i = 0; i < num_cars; i++)
    {
        pthread_create(&threads_cars[i], nullptr, &task_car, &cars.at(i));
    }

    for (int i = 0; i < num_pits; i++)
    {
        pthread_create(&threads_pits[i], nullptr, &task_pit, &cars.at(i));
    }

    for (int i = 0; i < num_cars; i++)
    {
        pthread_join(&threads_cars[i], nullptr);
    }

    for (int i = 0; i < num_pits; i++)
    {
        pthread_join(&threads_pits[i], nullptr);
    }

    print_results();

    std::cout << format.divide({"End of race. ", "See you soon!", "Team: Abner, Adrian, Samuel, Jose."});
}

void print_results()
{
    for (int i = 0; i < finish_list.size(); i++)
    {
        std::cout << finish_list[i] << std::endl;
    }
}

void get_user_input()
{
    std::cout << "Race distance (km):\n>>" << std::endl;
    std::cin >> race_distance;
    race_distance = race_distance * 1000;
    std::cout << "Number of cars:\n>>" << std::endl;
    std::cin >> num_cars;
    do
    {
        std::cout << "Number of pits:\n>>" << std::endl;
        std::cin >> num_pits;
    } while (num_pits > num_cars);
}

void objects_initialization()
{
    // creating cars with id
    for (int i = 0; i < num_cars; i++)
    {
        car_object this_car;
        this_car.id = i;
        cars.push_back(this_car);
    }

    // creating pits with cars list;
    int *ptr;
    int e_i = 0;
    int arr[num_pits];
    ptr = distribution(arr, num_pits, num_cars);
    for (int i = 0; i < num_pits; i++)
    {
        vector<car_object> cars_list;
        for (int e = 0; e < ptr[i]; e++)
        {
            cars_list.push_back(cars[e_i])
                e_i++;
        }
        pit_object this_pit;
        this_pit.inherit_cars = cars_list;
        pits.push_back(this_pit);
    }
}
