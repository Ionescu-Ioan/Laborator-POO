//
// Created by Ionut on 3/7/2021.
//
#include "Vocalist.h"
#include <string>


Vocalist::Vocalist()
{

}
Vocalist::Vocalist(const std::string &name, int age, const std::string &gen): Persoana(name, age), gen_muzical(gen)
{

}

void Vocalist::set_gen_muzical(const std::string &gen)
{
    gen_muzical = gen;
}

std::string Vocalist::get_gen_muzical()
{
    return gen_muzical;
}

Vocalist::~Vocalist()
{
#ifdef LOCAL
    std::cout << "In destructor cantaret\n";
#endif
}

void Vocalist::afisare()
{
    std::cout << "NUME: " << nume << ", " << "VARSTA: " << varsta << " de ani, " << "GEN MUZICAL: "  << gen_muzical <<"\n";
}

bool Vocalist::operator ==(Vocalist& c)
{
    if(this->get_nume() == c.get_nume() && this->get_varsta() == c.get_varsta() && this->gen_muzical == c.gen_muzical)
        return true;
    return false;
}
std::ostream& operator <<(std::ostream& out, const Vocalist& v)
{
    Persoana p = Persoana(v.nume, v.varsta);
    out << p << " " << v.gen_muzical;
    return out;
}