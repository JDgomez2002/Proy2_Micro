#include "format.h"

using namespace std;

string Format::divide(std::vector<string> param)
{
    string output = "";
    for (auto i = param.begin(); i != param.end(); ++i)
        output += divider + "\n" + *i + "\n";
    return output;
}

string Format::_int(string param)
{
    return "\nEnter the number of " + param + ":\n>> ";
}

Format::Format(string divider) : divider(divider) {}