//
// Created by Ionut on 3/7/2021.
//

#ifndef TEMA1_POO_FORMATIE_H
#define TEMA1_POO_FORMATIE_H
#include <string>
#include <iostream>
#include "Muzicant.h"
#include "Melodie.h"
#include "Persoana.h"
#include "Cantaret.h"
#include <vector>
class Formatie
{
public:
    Formatie(const std::string &nume_formatie);
    ~Formatie();

    void add_muzicant(const Muzicant&);
    std::vector <Muzicant> get_muzicanti();
    void add_melodie(const Melodie&);
    void add_cantaret(const Cantaret&);
    std::vector <Melodie> get_melodii();
    void set_manager(const Persoana&);

private:
    std::string nume_formatie;
    std::vector <Muzicant> v;
    std::vector <Melodie> w;
    std::vector <Cantaret> solisti;
    Persoana manager;

};

#endif //TEMA1_POO_FORMATIE_H
