//
// Created by Ionut on 3/7/2021.
//
#include "Formatie.h"
#include <string>
#include "Persoana.h"
#include <iostream>
#include <vector>
#include <typeinfo>

Formatie::Formatie(const std::string &nume_formatie)
{
    this->nume_formatie = nume_formatie;
}

std::string Formatie::get_nume_formatie()
{
    return nume_formatie;
}

void Formatie::add_muzicant(Muzicant &m)
{
    v.push_back(m);
    update_membrii();
}

void Formatie::remove_muzicant(Muzicant& m)
{
    for(std::vector <Muzicant>:: iterator it = v.begin(); it != v.end(); ++it)
        if(*it == m)
        {
            v.erase(it);
            update_membrii();
            break;
        }

}

std::vector<Muzicant> Formatie::get_muzicanti()
{
   return v;
}

Formatie::~Formatie()
{
#ifdef LOCAL
    std::cout << "In destructor formatie\n";
#endif
}

void Formatie::add_melodie(const Melodie &m)
{
    w.push_back(m);
}

void Formatie::set_manager(Persoana & p)
{
    manager = p;
    update_membrii();
}

std::vector <Melodie> Formatie::get_melodii()
{
    return w;
}

void Formatie::add_vocalist(Vocalist& c)
{
    solisti.push_back(c);
    update_membrii();
}



void Formatie::remove_vocalist(Vocalist& c)
{
    for(std::vector <Vocalist>:: iterator it = solisti.begin(); it != solisti.end(); ++it)
        if(*it == c)
        {
            solisti.erase(it);
            update_membrii();
            break;
        }

}


void Formatie::add_cantaret(Cantaret& x)
{
    c.push_back(x);
    update_membrii();
}

void Formatie::remove_cantaret(Cantaret& x)
{
    for(std::vector <Cantaret>:: iterator it = c.begin(); it != c.end(); ++it)
        if(*it == x)
        {
            c.erase(it);
            update_membrii();
            break;
        }

}

std::vector <Turneu> Formatie::get_turnee()
{
    return turnee;
}

void Formatie::afisare_muzicanti()
{
    for(int i=0; i<v.size(); ++i)
        std::cout<< v[i] << " \n";
}

void Formatie::afisare_cantareti(){
    for(int i=0; i<c.size(); ++i)
        std::cout<< c[i] << " \n";
}

void Formatie::afisare_vocalisti() {
    for(int i=0; i<solisti.size(); ++i)
        std::cout<< solisti[i] << " \n";
}

void Formatie::afisare_membrii() {
    std::cout << "Numarul de membrii: "<< membrii.size() << "\n";
    for(int i=0; i<membrii.size(); ++i)
        membrii[i]->afisare();

}


void Formatie::update_membrii()
{
    membrii.clear();
    if(manager.get_nume() != "")
        membrii.push_back(&manager);
    for(int i=0; i< v.size(); ++i)
        membrii.push_back(&v[i]);

    for(int i=0; i< solisti.size(); ++i)
        membrii.push_back(&solisti[i]);

    for(int i=0; i< c.size(); ++i)
        membrii.push_back(&c[i]);

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

void Formatie::afisare_melodii() {
    for(int i=0; i<w.size(); ++i)
        std::cout << w[i];
}

std::vector <Cantaret> Formatie::get_cantareti()
{
    return c;
}

Persoana Formatie::get_manager()
{
    return manager;
}

std::vector <Vocalist> Formatie::get_vocalisti()
{
    return solisti;
}

void Formatie::remove_manager()
{
    std::string sir_vid="";
    manager.set_nume(sir_vid);
    manager.set_varsta(0);
    update_membrii();
}