//
// Created by Ionut on 4/4/2021.
//

#ifndef TEMA1_POO_EXCEPTII_H
#define TEMA1_POO_EXCEPTII_H
#include <string>
#include <windows.h>
#include <cstdlib>
#include "Utilitati.cpp"
#include "exception"

class Exceptie_Lipsa_Fisier: public std::exception{
    std::string s;
public:
    Exceptie_Lipsa_Fisier(std::string s){
        this->s=s;
    }
    void afisare()
    {
        std::string mesaj = "Fisierul: "+s+" nu exista sau calea nu este corecta!\n";
        MessageBox(nullptr, mesaj.c_str(), "Avertisment", MB_OK);
    }
};

class Exceptie_Persoana: public std::exception
{
    int v;
    std::string nume;
    int ok=0;
public:
    Exceptie_Persoana(int x)
    {
        v = x;
        if(v < 14)
            ok=1;
    }
    Exceptie_Persoana(std::string s)
    {
        nume = s;
            ok=2;
    }

    void afisare()
    {
        if(ok==1)

            MessageBox(nullptr, "Varsta a fost introdusa gresit. Varsta nu poate fi < 14", "Persoana incorecta", MB_OK);
      else if(ok==2)
        {
          std::string mesaj = "Numele "+nume+" nu este corect!";
            MessageBox(nullptr, mesaj.c_str(), "Persoana incorecta", MB_OK);
        }


    }
};

class Exceptie_Melodie: public std::exception{
    int durata;
public:
    Exceptie_Melodie(int x)
    {
        durata = x;
    }
    void afisare(){
        std::string mesaj = "Durata melodiei "+v2s(durata)+" nu este corecta\n";
        MessageBox(nullptr, mesaj.c_str(), "Melodie incorecta", MB_OK);
    }
};

class Exceptie_Turneu: public std::exception{
  int an;
public:
    Exceptie_Turneu(int x)
    {
        an = x;
    }
    void afisare(){
        std::string mesaj = "Lista de orase a turneului din anul "+v2s(an)+" nu poate fi vida\n";
        MessageBox(nullptr, mesaj.c_str(), "Turneu incorecta", MB_OK);
    }
};


#endif //TEMA1_POO_EXCEPTII_H
