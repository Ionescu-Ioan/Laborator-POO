//
// Created by Ionut on 3/17/2021.
//
#include <string>
#include "Utilitati.h"
#include <sstream>

template<class T>
std::string v2s(T x)
{
    std::ostringstream os;
    os << x;
    return os.str();

}