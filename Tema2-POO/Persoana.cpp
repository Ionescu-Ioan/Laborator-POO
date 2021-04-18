//
// Created by Ionut on 3/4/2021.
//
#include <string>
#include "Persoana.h"
#include <iostream>
#include "Exceptii.h"
Persoana::Persoana(const std::string &name, int age)
{
    if (age < 14) throw Exceptie_Persoana(age);
    for(char i='0'; i<='9'; ++i)
        if (name.find(i) !=std::string::npos) throw Exceptie_Persoana(name);
    nume = name;
    varsta = age;
}

Persoana::Persoana()
{
    nume = "";
    varsta = -1;
}

void Persoana::afisare()
{
    std::cout  << "NUME: "<< nume <<", " << "VARSTA: "<< varsta << " de ani" <<"\n";
}

void Persoana::set_nume(std::string &n)
{
    nume = n;
}

void Persoana::set_varsta(int v)
{
    varsta = v;
}

std::string Persoana::get_nume()
{
    return nume;
}

int Persoana::get_varsta()
{
    return varsta;
}

std::string Persoana::to_string()
{
    return nume + " " + std::to_string(varsta) + "\n";
}

Persoana::~Persoana()
{
#ifdef LOCAL
    std::cout << "In destructor persoana " + nume + "\n";
#endif
}

Persoana& Persoana::operator ++(int k)
{
    varsta ++;
    return *this;
}

 std::ostream& operator <<(std::ostream& out, const Persoana& pers)
{
    out << pers.nume << " " << pers.varsta;
    return out;
}

std::istream& operator >>(std::istream& in, Persoana& pers)
{
    in >> pers.nume >> pers.varsta;
    return in;
}

bool Persoana::operator ==(const Persoana& p)
{
    if(nume == p.nume && varsta==p.varsta)
        return true;
    return false;
}