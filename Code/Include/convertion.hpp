#pragma once

#include <iostream>
#include <sstream>
#include <string>

std::string floatToString(float value) {
    std::ostringstream oss;
    oss.precision(5);
    oss << std::fixed << value;

    std::string str = oss.str();

    // Remove trailing zeroes
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);

    // If the last character is a dot, remove it
    if (!str.empty() && str.back() == '.') {
        str.pop_back();
    }

    return str;
}