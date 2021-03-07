//
// Created by Ionut on 3/4/2021.
//
#include "Muzicant.h"
#include "Persoana.h"
#include "Instrument_muzical.h"
#include <string>
#include <iostream>

Muzicant::Muzicant(const std::string &nume, const std::string &instrument, int varsta, float pret)
{
    //pers.set_nume(nume);
    //pers.set_varsta(varsta);
    ins = Instrument_muzical(instrument, pret);
    pers = Persoana(nume, varsta);
}

Muzicant::Muzicant(const Persoana& p, const Instrument_muzical& i)
{
    pers = p;
    ins = i;
}

void Muzicant::set_instrument(Instrument_muzical i)
{
    ins = i;
}

Persoana Muzicant::get_persoana()
{
    return pers;
}

Instrument_muzical Muzicant::get_instrument()
{
    return ins;
}

Muzicant::~Muzicant()
{
    std::cout << "In destructor muzicant\n";
}