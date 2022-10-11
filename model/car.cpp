#include <iostream>
using namespace std;

/// @brief simulates a car
class Car
{
private:
    int id;
    int pitId;
    int pitStops;
    int speed;
    int distance;
    int globalDistance;

public:
    /// @brief
    /// @return id
    int getId()
    {
        return id;
    };

    /// @brief
    /// @param id
    void setId(int id)
    {
        this->id = id;
    };

    /// @brief
    /// @return pitId
    int getPitId()
    {
        return pitId;
    };

    /// @brief
    /// @param pitId
    void setPitId(int pitId)
    {
        this->pitId = pitId;
    };

    /// @brief
    /// @return
    int getPitStops()
    {
        return pitStops;
    };

    /// @brief
    /// @param pitStops
    void setPitStops(int pitStops)
    {
        this->pitStops = pitStops;
    };

    /// @brief
    /// @param speed
    int getDistance()
    {
        return distance;
    };

    /// @brief
    /// @return
    int setDistance()
    {
        distance += speed;
    };

    /// @brief
    /// @return
    int getSpeed()
    {
        return speed;
    };

    /// @brief
    /// @param speed
    void setSpeed(int speed)
    {
        this->speed = speed;
    };

    int getGlobalDistance()
    {
        return globalDistance;
    };
    /// @brief
    /// @param id, the identifier of the car - analogue: running number
    /// @param pitId, the identifier of the car pit
    /// @param pitStops, the amount of stops on the pits during the race
    /// @param speed, the speed of the car
    Car(int id, int globalDistance)
    {
        this->id = id;
        this->pitId = 0;
        this->pitStops = 0;
        this->speed = 0;
        this->distance = 0;
        this->globalDistance = globalDistance;
    }
};