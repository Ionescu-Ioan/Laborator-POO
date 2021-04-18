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
#include "Vocalist.h"
#include "Cantaret.h"
#include "Turneu.h"
#include <vector>
#include "Local.h"
typedef Persoana * pPersoana;

class Formatie
{
public:
    Formatie(const std::string &nume_formatie);
    ~Formatie();

    void add_muzicant(Muzicant&);
    void remove_muzicant(Muzicant&);
    void add_cantaret(Cantaret&);
    void remove_cantaret(Cantaret&);
    std::vector <Muzicant> get_muzicanti();
    std::vector <Cantaret> get_cantareti();
    std::vector <Vocalist> get_vocalisti();
    void add_melodie(const Melodie&);
    void add_vocalist(Vocalist&);
    void remove_vocalist(Vocalist&);
    std::vector <Melodie> get_melodii();
    void set_manager(Persoana&);
    void remove_manager();
    Persoana get_manager();
    void afisare_muzicanti();
    void afisare_vocalisti();
    void afisare_cantareti();
    void add_turneu(const Turneu&);
    void afisare_turnee();
    void afisare_melodii();
    void update_membrii();
    void afisare_membrii();

private:
    std::string nume_formatie;
    std::vector <pPersoana> membrii;
    std::vector <Muzicant> v;
    std::vector <Melodie> w;
    std::vector <Vocalist> solisti;
    std::vector <Cantaret> c;
    std::vector <Turneu> turnee;
    Persoana manager;

};

#endif //TEMA1_POO_FORMATIE_H
