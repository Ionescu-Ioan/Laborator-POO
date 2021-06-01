//
// Created by Ionut on 3/4/2021.
//
#include "Muzicant.h"
#include "Persoana.h"
#include "Instrument_muzical.h"
#include <string>
#include <iostream>

Muzicant::Muzicant(std::string nume, std::string instrument, int varsta, float pret) : Persoana(nume, varsta)
{
    ins.set_pret(pret);
    ins.set_denumire(instrument);
}

/*Muzicant::Muzicant(const Persoana& p, const Instrument_muzical& i)
{
    pers = p;
    ins = i;
}
*/

void Muzicant::afisare()
{
    std::cout << "NUME: " << nume << ", " << "VARSTA: "<< varsta << " de ani, " <<"INSTRUMENT: " << ins << "\n";
}

void Muzicant::set_instrument(Instrument_muzical i)
{
    ins = i;
}

Persoana Muzicant::get_persoana()
{
    Persoana p(nume, varsta);
    return p;
}

Instrument_muzical Muzicant::get_instrument()
{
    return ins;
}

Muzicant::~Muzicant()
{
#ifdef LOCAL
    std::cout << "In destructor muzicant\n";
#endif
}

bool Muzicant::operator ==(const Muzicant& m)
{
    Persoana p(nume, varsta);
    if(p == m && ins == m.ins)
        return true;
    return false;
}

std::ostream& operator <<(std::ostream& out, const Muzicant& m)
{
    Persoana p = Persoana(m.nume, m.varsta);
    out << p << " " << m.ins;
    return out;
}