#include "../view/format.h"

/// @brief All necessary input data from user.
using namespace std;

namespace data
{
    struct programData
    {
        int distance;
        int carsAmount;
        int pitsAmount;
    };

    programData request(Format format)
    {
        programData input;
        cout << format._int("race kilometers");
        cin >> input.distance;
        cout << format._int("pits in race");
        cin >> input.pitsAmount;
        cout << format._int("cars in race");
        cin >> input.carsAmount;
        return input;
    };
};