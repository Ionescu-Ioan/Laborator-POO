//
// Created by Ionut on 3/7/2021.
//

#ifndef TEMA1_POO_VOCALIST_H
#define TEMA1_POO_VOCALIST_H
#include "Persoana.h"
#include <string>
#include <iostream>
#include "Local.h"
class Vocalist: virtual public Persoana
{
public:
    Vocalist();
    Vocalist(const std::string &name, int age, const std::string &gen);
    ~Vocalist();
    virtual void afisare();
    void set_gen_muzical(const std::string &gen);
    std::string get_gen_muzical();
    bool operator ==(Vocalist&);
    friend std::ostream& operator <<(std::ostream& , const Vocalist&);

protected:
    std::string gen_muzical;
};

#endif //TEMA1_POO_VOCALIST_H
