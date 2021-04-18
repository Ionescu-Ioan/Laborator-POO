//
// Created by Ionut on 3/7/2021.
//
#include "Melodie.h"
#include <string>
#include <iostream>
#include "Exceptii.h"
Melodie::Melodie(const std::string &nume, float durata, int an)
{
    if (durata <= 0) throw Exceptie_Melodie(durata);
    nume_melodie = nume;
    this->durata = durata;
    anul_lansarii = an;
}

Melodie::~Melodie()
{
#ifdef LOCAL
    std::cout << "In destructor Melodie\n";
#endif
}

std::string Melodie::get_nume_melodie()
{
    return nume_melodie;
}

float Melodie::get_durata()
{
    return durata;

}

int Melodie::get_anul_lansarii()
{
    return anul_lansarii;
}
std::ostream& operator <<(std::ostream& out, Melodie& m)
{
    out << "nume melodie: "<<m.get_nume_melodie() << ", durata: " << m.get_durata() << " minute"<< ", anul lansarii: " << m.get_anul_lansarii() << " ";
    out << "\n";
    return out;
}