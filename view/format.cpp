#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

/// @brief contains functions who take care of formatting the texts
class Format
{
private:
    string divider;

public:
    /// @brief generate a string separated by the divider defined for the class
    /// @param param, vector of string
    /// @param output, optional initial text
    /// @return formatted string
    string divide(std::vector<string> param)
    {
        string output = "";
        for (auto i = param.begin(); i != param.end(); ++i)
            output += divider + "\n" + *i + "\n";
        return output;
    };

    /// @brief generate a string that states a int prompt
    /// @param param, element to insert between the format
    /// @return
    string _int(string param)
    {
        return "\nEnter the number of " + param + ":\n>> ";
    };

    /// @brief
    /// @param divider, the divider for the texts that are used in many inside functions
    Format(string divider)
    {
        this->divider = divider;
    };
};