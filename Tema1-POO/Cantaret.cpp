//
// Created by Ionut on 3/7/2021.
//
#include "Cantaret.h"
#include <string>
Cantaret::Cantaret()
{

}
Cantaret::Cantaret(const std::string &name, int age, const std::string &gen):Persoana(name, age), gen_muzical(gen)
{

}

void Cantaret::set_gen_muzical(const std::string &gen)
{
    gen_muzical = gen;
}

std::string Cantaret::get_gen_muzical()
{
    return gen_muzical;
}

Cantaret::~Cantaret()
{
    std::cout << "In destructor cantaret\n";
}