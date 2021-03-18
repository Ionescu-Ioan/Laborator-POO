//
// Created by Ionut on 3/4/2021.
//

#ifndef TEMA1_POO_INSTRUMENT_MUZICAL_H
#define TEMA1_POO_INSTRUMENT_MUZICAL_H
#include <string>
#include <ostream>

class Instrument_muzical
{
public:
    Instrument_muzical(const std::string &denumire, float p = 0.0);
    Instrument_muzical(const Instrument_muzical &im);
    Instrument_muzical();
    ~Instrument_muzical();
    Instrument_muzical& operator=(const Instrument_muzical&);
    bool operator ==(const Instrument_muzical&);

    float get_pret();
    std::string get_denumire();

    void set_pret(float);
    void set_denumire(std::string &);

    friend std::ostream& operator <<(std::ostream&, const Instrument_muzical& );

private:
    std::string denumire;
    float pret;
};

#endif //TEMA1_POO_INSTRUMENT_MUZICAL_H
