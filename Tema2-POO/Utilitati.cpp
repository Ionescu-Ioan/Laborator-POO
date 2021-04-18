//
// Created by Ionut on 3/17/2021.
//
#include <string>
#include "Utilitati.h"
#include <sstream>

std::string f2s(float x)
{
    std::ostringstream os;
    os << x;
    return os.str();


}
std::string i2s(int x)
{
    std::ostringstream os;
    os << x;
    return os.str();
}