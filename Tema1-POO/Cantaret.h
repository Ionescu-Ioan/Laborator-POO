//
// Created by Ionut on 3/7/2021.
//

#ifndef TEMA1_POO_CANTARET_H
#define TEMA1_POO_CANTARET_H
#include "Persoana.h"
#include <string>
#include <iostream>
class Cantaret:public Persoana
{
public:
    Cantaret();
    Cantaret(const std::string &name, int age, const std::string &gen);
    ~Cantaret();
    void set_gen_muzical(const std::string &gen);
    std::string get_gen_muzical();

private:
    std::string gen_muzical;
};

#endif //TEMA1_POO_CANTARET_H
