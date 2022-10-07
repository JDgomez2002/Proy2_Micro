#include <stdio.h>

#include <bits/stdc++.h>
#include <vector>

#include "model/data.cpp"
#include "model/car.cpp"
#include "model/pit.cpp"

#include "view/format.cpp"

#include "controller/controller.cpp"
using namespace std;

data::programData request(Format format);

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char *argv[])
{

    Format format("-------------------------------------------------------------------------------");
    cout << format.divide({"Welcome to Race Simulator!", "This is our Microprocesadores second project, thanks for using the program!"});
    data::programData input = request(format);

    Controller controller(input);

    cout << format.divide({"See you soon!", "Team: Abner, Adrian, Samuel, Jose."});
    return 0;
}

/// @brief Request necessary input data from user.
data::programData request(Format format)
{
    data::programData input;
    cout << format._int("race kilometers");
    cin >> input.distance;
    cout << format._int("pits in race");
    cin >> input.pitsAmount;
    cout << format._int("cars in race");
    cin >> input.carsAmount;
    return input;
};