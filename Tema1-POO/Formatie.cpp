//
// Created by Ionut on 3/7/2021.
//
#include "Formatie.h"
#include <string>
#include "Persoana.h"
#include <iostream>

Formatie::Formatie(const std::string &nume_formatie)
{
    this->nume_formatie = nume_formatie;
}

void Formatie::add_muzicant(const Muzicant &m)
{
    v.push_back(m);
}

std::vector<Muzicant> Formatie::get_muzicanti()
{
   return v;
}

Formatie::~Formatie()
{
    std::cout << "In destructor formatie\n";
}

void Formatie::add_melodie(const Melodie &m)
{
    w.push_back(m);
}

void Formatie::set_manager(const Persoana & p)
{
    manager = p;
}

std::vector <Melodie> Formatie::get_melodii()
{
    return w;
}

void Formatie::add_cantaret(const Cantaret& c)
{
    solisti.push_back(c);
}