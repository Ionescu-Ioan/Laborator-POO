//
// IONESCU IOAN
// GRUPA 151
// COMPILATOR: GCC VERSIUNE 8.1.0
// ASISTENT: MARIUS MICLUTA-CAMPEANU
//
#include "Informatii_trupa.h"

Informatii_trupa* Informatii_trupa::get_informatii() {
    if(pi == nullptr) { pi = new Informatii_trupa; }
    return pi;
}

std::string Informatii_trupa::get_info()
{
    return informatii;
}

void Informatii_trupa::set_informatii(const std::string &i)
{
    informatii=i;
}
Informatii_trupa* Informatii_trupa::pi = nullptr;
std::string Informatii_trupa::informatii="";

