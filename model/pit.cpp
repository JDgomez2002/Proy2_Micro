#include <iostream>
#include <vector>

using namespace std;

/// @brief simulates a pit
class Pit
{
private:
    int id;
    vector<Car> cars;

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
    /// @param id, the identifier of the pit
    /// @param cars, vector of Car object - analogue: the affiliated runners
    Pit(int id, vector<Car> cars)
    {
        this->id = id;
        this->cars = cars;
    };
};