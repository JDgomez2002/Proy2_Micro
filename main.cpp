#include <stdio.h>
#include "model/car.cpp"

public void *carOperations(void *arg) {
    Car *car = (Car*) arg;

    while (car->getDistance(globalTime) <  globalDistance) {
        
    }
    return nullptr;
}

public void *pitOperations(void *arg) {    
    Sponsor *sponsor = (Sponsor*) arg;
}

public void *globalClock(void *arg) {
    Car *car = (Car*) arg;
    return nullptr;
}


int main()
{
    printf("Hello World");
    Car car(1);
    cout 
    return 0;
}
