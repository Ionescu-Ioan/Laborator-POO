//
// Created by Ionut on 3/17/2021.
//
#include "Turneu.h"
#include <string>
#include <iostream>
#include "Exceptii.h"

Turneu::Turneu(std::vector <std::string> o, int a)
{
    if (o.size() == 0) throw Exceptie_Turneu(a);
    this->an = a;
    this->orase = o;
}

Turneu::Turneu()
{

}

std::vector <std::string> Turneu::get_orase()
{
    return orase;
}

Turneu::~Turneu()
{
#ifdef LOCAL
    std::cout << "In destructor Turneu\n";
#endif
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
    out << "An desfasurare turneu: "<<t.an << "; Orase: ";
    for(int i=0 ; i<t.orase.size(); ++i)
        out << t.orase[i] << ", ";
    out << "\n";
    return out;
}