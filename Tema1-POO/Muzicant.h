//
// Created by Ionut on 3/4/2021.
//

#ifndef TEMA1_POO_MUZICANT_H
#define TEMA1_POO_MUZICANT_H
#include "Persoana.h"
#include "Instrument_muzical.h"

class Muzicant
{
public:
    Muzicant(const std::string &nume, const std::string &instrument, int varstas, float pret);
    Muzicant(const Persoana& p, const Instrument_muzical& i);
    ~Muzicant();
    void set_instrument(Instrument_muzical i);
    Persoana get_persoana();
    Instrument_muzical get_instrument();

private:
    Persoana pers;
    Instrument_muzical ins;
};
#endif //TEMA1_POO_MUZICANT_H
