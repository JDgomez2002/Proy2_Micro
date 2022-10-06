#include <iostream>
using namespace std;

class Car {
    private:
        int id;
        int sponsorId;
        int pitStops;
        int speed;

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

        double getDistance(int globalTime) {
            return speed * globalTime;
        };
        
        int getSpeed() {
            return speed;
        };
        void setSpeed(int speed) {            
            this->speed = speed; 
        };
        
    Car(int id, int sponsorId, int pitStops, int speed) {
        this->id = id;
        this->sponsorId = sponsorId;
        this->pitStops = pitStops;
        this->speed = speed; 
    }
};