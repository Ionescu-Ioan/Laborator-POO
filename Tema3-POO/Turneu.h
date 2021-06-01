//
// Created by Ionut on 3/17/2021.
//

#ifndef TEMA1_POO_TURNEU_H
#define TEMA1_POO_TURNEU_H
#include <string>
#include <vector>
#include <iostream>
#include "Local.h"

class Turneu
{
public:
    Turneu(std::vector <std::string> o, int a = 0);
    Turneu();
    ~Turneu();
    void set_an(int);
    int get_an();
    std::vector <std::string> get_orase();
    void add_oras(std::string);
    void remove_oras(std::string);
    friend std::ostream& operator <<(std::ostream&, Turneu&);

private:
    int an;
    std::vector <std::string> orase;
};

#endif //TEMA1_POO_TURNEU_H
