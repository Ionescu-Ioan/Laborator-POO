//
// IONESCU IOAN
// GRUPA 151
// COMPILATOR: GCC VERSIUNE 8.1.0
// ASISTENT: MARIUS MICLUTA-CAMPEANU
//
#include "Brand.h"

Brand* Brand::get_brand() {
    if(pb == nullptr) { pb = new Brand; }
    return pb;
}

std::string Brand::get_denumire()
{
    return denumire;
}

void Brand::set_brand(const std::string &d)
{
    denumire=d;
}
Brand* Brand::pb = nullptr;
std::string Brand::denumire;