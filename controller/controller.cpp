#include <iostream>
using namespace std;

/// @brief
class Controller
{
private:
    data::programData initial_values;
    Pit *pits;

public:
    static void initializer()
    {
        cout << "On initializer";
    };

    Controller(data::programData initial_values)
    {
        this->initial_values = initial_values;
        initializer();
    };
};