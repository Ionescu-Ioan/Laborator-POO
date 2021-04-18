//
// Created by Ionut on 3/4/2021.
//
#include "Instrument_muzical.h"
#include <string>
#include <cmath>
#include <iostream>
#include "Utilitati.h"

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

std::ostream& operator <<(std::ostream& out, const Instrument_muzical& i)
 {
    //float f = std::round(i.pret*100)/100.0;
    out << i.denumire + "-pret: " + f2s(i.pret) + " ";
    return out;
}

Instrument_muzical::~Instrument_muzical()
{
#ifdef LOCAL
    std::cout << "In destructor instrument muzical " + denumire + "\n";
#endif
}

Instrument_muzical& Instrument_muzical::operator=(const Instrument_muzical& copie)
{
    denumire = copie.denumire;
    pret = copie.pret;
    return *this;
}

bool Instrument_muzical::operator ==(const Instrument_muzical& i)
{
    if(denumire == i.denumire && pret==i.pret)
        return true;
    return false;
}