#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

pthread_mutex_t pits_mutex;
pthread_cond_t condition_variable;

int race_distance;
int num_cars;
int num_pits;

struct car_object
{
    int id;
    int pit_id;
    int distance;
    int need_repair;
};
vector<car_object> cars;

struct pit_object
{
    int id;
    vector<car_object> inherit_cars;
};

vector<pit_object> pits;

void display_welcome_message();
void get_user_input();
void initialization();
void display_farewell_message();

Format format("-------------------------------------------------------------------------------");

int main()
{
    display_welcome_message();
    get_user_input();
    display_farewell_message();
    return 0;
}

void display_welcome_message()
{
    std::cout << format.divide({"Welcome to the Nascar Race Simulator!", "This is our second project for our Microprocessor Programming course, thanks for using the program!"});
}

void get_user_input()
{
    std::cout << "Race distance (km):\n>>" << std::endl;
    std::cin >> race_distance;
    std::cout << "Number of cars:\n>>" << std::endl;
    std::cin >> num_cars;

    do
    {
        std::cout << "Number of pits:\n>>" << std::endl;
        std::cin >> num_pits;
    } while (num_pits > num_cars);
}

void initialization()
{
    for (int i = 0; i < initial_values.carsAmount; i++)
    {
        car_object this_car;
        cars.push_back(this_car);
    }

    int *ptr;
    int arr[num_pits];
    ptr = distribution(arr, num_pits, num_cars);

    int inherit_cars_global_id = 0;
    for (int i = 0; i < num_pits; i++)
    {
        vector<car_object> inherit_cars;
        for (int e = 0; e < ptr[i]; e++)
        {
            cars[inherit_cars_global_id].id = inherit_cars_global_id;
            cars[inherit_cars_global_id].pit_id = i;
            inherit_cars.push_back(cars[inherit_cars_global_id]);
            inherit_cars_global_id++;
        }
        pit_object this_pit;
        this_pit = {.id = i, .inherit_cars = inherit_cars};
        pits.push_back(Pit(i, inheritCars));
    }
}

void display_farewell_message()
{
    std::cout << format.divide({"End of race. ", "See you soon!", "Team: Abner, Adrian, Samuel, Jose."});
}

// Subroutine for the pits
void *pit(void *arg)
{
    long tID = (long)arg;
    while ()
}

// subroutine for the cars
void *cars(void *arg)
{
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