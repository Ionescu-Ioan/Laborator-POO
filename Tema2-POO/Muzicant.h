//
// Created by Ionut on 3/4/2021.
//

#ifndef TEMA1_POO_MUZICANT_H
#define TEMA1_POO_MUZICANT_H
#include "Persoana.h"
#include "Instrument_muzical.h"
#include "Local.h"
class Muzicant : virtual public Persoana
{
public:
    Muzicant(std::string nume, std::string instrument, int varsta, float pret = 0.0);
    //Muzicant(const Persoana& p, const Instrument_muzical& i);
    ~Muzicant();
    void set_instrument(Instrument_muzical i);
    virtual void afisare();
    Persoana get_persoana();
    Instrument_muzical get_instrument();
    bool operator ==(const Muzicant&);
    friend std::ostream& operator <<(std::ostream& , const Muzicant&);

protected:
    Instrument_muzical ins;
};
#endif //TEMA1_POO_MUZICANT_H
