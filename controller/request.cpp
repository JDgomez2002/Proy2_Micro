#include "../view/format.cpp"

using namespace std;

namespace request
{
    struct raceData
    {
        int distance;
        int carsAmount;
        int pitsAmount;
    };

    raceData prompt(Format format)
    {
        raceData data;
        cout << format._int("Race Distance");
        cin << data.distance;
        cout << format._int("Cars Amount");
        cin << data.carsAmount;
        cout << format._int("Pits Amount");
        cin << data.pitsAmount;
        return data;
    };
};