//
// Created by Ionut on 3/7/2021.
//
#include "Formatie.h"
#include <string>
#include "Persoana.h"
#include <iostream>
#include <vector>

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

void Formatie::remove_muzicant(const Muzicant& m)
{
    for(std::vector <Muzicant>:: iterator it = v.begin(); it != v.end(); ++it)
        if(*it == m)
        {
            v.erase(it);
            break;
        }
}


void Formatie::remove_cantaret(Cantaret& c)
{
    for(std::vector <Cantaret>:: iterator it = solisti.begin(); it != solisti.end(); ++it)
        if(*it == c)
        {
            solisti.erase(it);
            break;
        }
}

void Formatie::afisare_muzicanti()
{
    for(int i=0; i<v.size(); ++i)
        std::cout<< v[i] << " \n";
}

void Formatie::add_turneu(const Turneu& t)
{
    turnee.push_back(t);
}

void Formatie::afisare_turnee()
{
    for(int i=0; i<turnee.size(); ++i)
        std::cout << turnee[i];
}