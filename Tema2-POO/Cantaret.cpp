//
// Created by Ionut on 4/4/2021.
//
#include "Cantaret.h"

Cantaret::Cantaret(std::string nume, int varsta, std::string denumire_instrument, std::string gen_muzical, std::string nume_scena) : Muzicant(nume, denumire_instrument, varsta), Vocalist(nume, varsta, gen_muzical), Persoana(nume, varsta)
{
    this->nume_scena = nume_scena;
}

Cantaret::~Cantaret()
{
}

bool Cantaret::operator ==(const Cantaret& c)
{
    Persoana p(nume, varsta);
    if(p == c && ins == c.ins && c.gen_muzical == gen_muzical && c.nume_scena == nume_scena)
        return true;
    return false;
}

void Cantaret::afisare()
{
    std::cout <<"NUME: " << nume << ", " << "VARSTA: " << varsta << " de ani" << ", GEN MUZICAL: " << gen_muzical << ", INSTRUMENT: " << ins << ", NUME DE SCENA: " << nume_scena <<"\n";
}

std::ostream& operator <<(std::ostream& out , const Cantaret& c)
{
    Persoana p = Persoana(c.nume, c.varsta);
    out << p << " " << c.ins << " " << c.gen_muzical << " " << c.nume_scena <<"\n";
    return out;
}