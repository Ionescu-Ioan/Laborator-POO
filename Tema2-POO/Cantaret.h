//
// Created by Ionut on 4/4/2021.
//

#ifndef TEMA1_POO_CANTARET_H
#define TEMA1_POO_CANTARET_H
#include <string>
#include "Muzicant.h"
#include "Vocalist.h"

class Cantaret: virtual public Muzicant, virtual public Vocalist
{
    std::string nume_scena;
public:
    Cantaret(std::string nume, int varsta, std::string denumire_instrument, std::string gen_muzical, std::string nume_scena);
    Cantaret(){}
    ~Cantaret();
    std::string get_nume_scena();
    void afisare();
    bool operator ==(const Cantaret&);
    friend std::ostream& operator <<(std::ostream& , const Cantaret&);
};

#endif //TEMA1_POO_CANTARET_H
