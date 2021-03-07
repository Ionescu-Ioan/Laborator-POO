#include <iostream>
#include <string>
#include <vector>
#include "Instrument_muzical.h"
#include "Persoana.h"
#include "Muzicant.h"
#include <iomanip>


int main()
{
    Instrument_muzical i1("flaut", 200), i2("vioara");

    std::cout << i1.to_string();
    std::cout << i2.to_string();

    i1.set_pret(1000);
    std::string s = "pian";
    i2.set_denumire(s);
    i2.set_pret(10000);

    float pret_total = i1.get_pret() + i2.get_pret();

    std::cout << i1.to_string();
    std::cout << i2.to_string();

    std::cout << pret_total << "\n";

    Persoana p1("Alex", 25), p2("Paul", 20);
    std::cout << p1.to_string() << p2.to_string();

    Muzicant m1("Vasile", "tambal", 40, 500.1234);
    std::cout<< m1.get_persoana().to_string() << m1.get_instrument().to_string();

    Persoana p;
    std::cin >> p;
    std::cout << p << std::endl;
    p++;
    std::cout << p << std::endl;
    return 0;
}
