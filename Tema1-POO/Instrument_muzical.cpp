//
// Created by Ionut on 3/4/2021.
//
#include "Instrument_muzical.h"
#include <string>
#include <iostream>
Instrument_muzical::Instrument_muzical(const std::string &denumire, float p)
{
    this->denumire = denumire;
    pret = p;
}

Instrument_muzical::Instrument_muzical(const Instrument_muzical &im)
{
    denumire = im.denumire;
    pret = im.pret;
}

Instrument_muzical::Instrument_muzical()
{
    denumire = "";
    pret = 0.0;
}

float Instrument_muzical::get_pret()
{
    return pret;
}

std::string Instrument_muzical::get_denumire()
{
    return denumire;
}

void Instrument_muzical::set_pret(float p)
{
    pret = p;
}

void Instrument_muzical::set_denumire(std::string &d)
{
    denumire = d;
}

std::string Instrument_muzical::to_string()
{
    float f = int(pret*100)/100.0;
    return denumire + " " + std::to_string(f) + "\n";
}

Instrument_muzical::~Instrument_muzical()
{
    std::cout << "In destructor instrument muzical " + denumire + "\n";
}

Instrument_muzical& Instrument_muzical::operator=(const Instrument_muzical& copie)
{
    denumire = copie.denumire;
    pret = copie.pret;
    return *this;
}
