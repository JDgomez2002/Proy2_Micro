
#include "car.cpp"
#include <iostream>
using namespace std;

class Pit {
    private:    
        int id;
        Car *cars;        

    public: 
        int getId() {
            return id;
        };

        void setId(int id) {            
            this->id = id; 
        };

        int getSponsorId() {
            return cars;
        };

        void setSponsorId(Car cars) {
            this->cars = cars; 
        };
        
    Pit (int id, Car cars) {
        this->id = id;
        this->cars = cars;
    }
};