//
// Created by Ionut on 3/4/2021.
//
#include "Muzicant.h"
#include "Persoana.h"
#include "Instrument_muzical.h"
#include <string>
#include <iostream>

Muzicant::Muzicant(std::string nume, std::string instrument, int varsta, float pret)
{
    pers.set_nume(nume);
    pers.set_varsta(varsta);
    ins.set_pret(pret);
    ins.set_denumire(instrument);
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

bool Muzicant::operator ==(const Muzicant& m)
{
    if(pers == m.pers && ins == m.ins)
        return true;
    return false;
}

std::ostream& operator <<(std::ostream& out, const Muzicant& m)
{
    out << m.pers << " " << m.ins;
    return out;
}