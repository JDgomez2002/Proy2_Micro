#include <iostream>
using namespace std;

class Car {
    private:
        int id;
        int sponsorId;
        int pitStops;
        int speed;
        int distance;

    public: 
        int getId() {
            return id;
        };

        void setId(int id) {            
            this->id = id; 
        };

        int getSponsorId() {
            return sponsorId
        };

        void setSponsorId(int sponsorId) {
            this->sponsorId = sponsorId; 
        };

        int getPitStops() {
            return pitStops
        };

        void setPitStops(int pitStops){
            this->pitStops = pitStops; 
        };

        double setDistance() {
            distance += speed;
        };
        
        int getSpeed() {
            return speed;
        };
        void setSpeed(int speed) {            
            this->speed = speed; 
        };
        
    Car (int id, int sponsorId, int pitStops, int speed) {
        this->id = id;
        this->sponsorId = sponsorId;
        this->pitStops = pitStops;
        this->speed = speed; 
        distance = 0;
    }
};