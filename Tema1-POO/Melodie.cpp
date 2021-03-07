//
// Created by Ionut on 3/7/2021.
//
#include "Melodie.h"
#include <string>
#include <iostream>

Melodie::Melodie(const std::string &nume, float durata, int an)
{
    nume_melodie = nume;
    this->durata = durata;
    anul_lansarii = an;
}

Melodie::~Melodie()
{
    std::cout << "In destructor Melodie\n";
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