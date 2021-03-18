//
// Created by Ionut on 3/17/2021.
//
#include "Turneu.h"
#include <string>
#include <iostream>

Turneu::Turneu(std::vector <std::string> orase, int an)
{
    this->an = an;
    this->orase = orase;
}

Turneu::Turneu()
{

}

Turneu::~Turneu()
{
    std::cout << "In destructor Turneu\n";
}

void Turneu::set_an(int an)
{
    this->an = an;
}

int Turneu::get_an()
{
    return an;
}

void Turneu::add_oras(std::string oras)
{
    orase.push_back(oras);
}

void Turneu::remove_oras(std::string oras)
{
    for(std::vector<std::string>::iterator it = orase.begin(); it != orase.end(); ++it)
        if(*it == oras)
        {
            orase.erase(it);
            break;
        }
}

std::ostream& operator <<(std::ostream& out, Turneu& t)
{
    out << t.an << " orase: ";
    for(int i=0 ; i<t.orase.size(); ++i)
        out << t.orase[i] << " ";
    out << "\n";
    return out;
}