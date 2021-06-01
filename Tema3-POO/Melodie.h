//
// Created by Ionut on 3/7/2021.
//

#ifndef TEMA1_POO_MELODIE_H
#define TEMA1_POO_MELODIE_H
#include <string>
#include "Local.h"
class Melodie
{
public:
    Melodie(const std::string &nume, float durata, int an);
    ~Melodie();
    std::string get_nume_melodie();
    float get_durata();
    int get_anul_lansarii();
    friend std::ostream& operator <<(std::ostream&, Melodie&);
private:
    std::string nume_melodie;
    float durata;
    int anul_lansarii;
};

#endif //TEMA1_POO_MELODIE_H
