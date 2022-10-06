#include <stdio.h>

#include <bits/stdc++.h>
#include <vector>

#include "model/data.cpp"
#include "model/car.cpp"
#include "model/pit.cpp"
#include "view/format.h"
using namespace std;

Format format("---------------------------------------------------------");

/// @brief
/// @param argc
/// @param argv
/// @return
int main(int argc, char *argv[])
{
    cout << format.divide({"Welcome to Race Simulator!", "This is our Microprocesadores second project, thanks for using the program!"});
    data::programData input = data::request(format);
    cout << input.carsAmount;
    cout << format.divide({"See you soon!", "Team: Abner, Adrian, Samuel, Jose."});
    return 0;
}