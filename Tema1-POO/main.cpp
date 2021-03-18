#include <iostream>
#include <string>
#include <vector>
#include "Instrument_muzical.h"
#include "Persoana.h"
#include "Muzicant.h"
#include "Formatie.h"
#include "Cantaret.h"
#include <iomanip>


int main()
{
    Instrument_muzical i1("flaut", 200), i2("vioara");

    std::cout << i1;
    std::cout << i2;

    i1.set_pret(1000);
    std::string s = "pian";
    i2.set_denumire(s);
    i2.set_pret(10000);

    float pret_total = i1.get_pret() + i2.get_pret();

    std::cout << i1;
    std::cout << i2;

    std::cout << pret_total << "\n";

    Persoana p1("Alex", 25), p2("Paul", 20);
    std::cout << p1.to_string() << p2.to_string();

    Muzicant m1("Vasile", "tambal", 40, 500.1234);
    Muzicant m2("Ionel", "chitara", 42, 600.1234);
    Muzicant m3("Alex", "toba", 30, 400);
    Formatie f1("Azur");
    f1.add_muzicant(m1);
    f1.add_muzicant(m2);
    f1.add_muzicant(m3);
    f1.afisare_muzicanti();
    f1.remove_muzicant(m2);
    f1.afisare_muzicanti();
    f1.add_muzicant(m2);
    f1.afisare_muzicanti();
    std::vector<std::string> o={"Bucuresti", "Constanta", "Cluj"};
    Turneu t1(o, 2022);
    f1.add_turneu(t1);
    Turneu t2;
    t2.set_an(2023);
    t2.add_oras("Iasi");
    f1.add_turneu(t2);
    f1.afisare_turnee();

    return 0;
}
