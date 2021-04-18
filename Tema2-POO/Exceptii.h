//
// Created by Ionut on 4/4/2021.
//

#ifndef TEMA1_POO_EXCEPTII_H
#define TEMA1_POO_EXCEPTII_H
#include <string>
#include <windows.h>
#include <stdlib.h>
#include "Utilitati.h"
class Exceptie_Lipsa_Fisier{
    std::string s;
public:
    Exceptie_Lipsa_Fisier(std::string s){
        this->s=s;
    }
    void afisare()
    {
        std::string mesaj = "Fisierul: "+s+" nu exista sau calea nu este corecta!\n";
        MessageBox(NULL, mesaj.c_str(), "Avertisment", MB_OK);
    }
};

class Exceptie_Persoana
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

            MessageBox(NULL, "Varsta a fost introdusa gresit. Varsta nu poate fi < 14", "Persoana incorecta", MB_OK);
      else if(ok==2)
        {
          std::string mesaj = "Numele "+nume+" nu este corect!";
            MessageBox(NULL, mesaj.c_str(), "Persoana incorecta", MB_OK);
        }


    }
};

class Exceptie_Melodie{
    int durata;
public:
    Exceptie_Melodie(int x)
    {
        durata = x;
    }
    void afisare(){
        std::string mesaj = "Durata melodiei "+i2s(durata)+" nu este corecta\n";
        MessageBox(NULL, mesaj.c_str(), "Melodie incorecta", MB_OK);
    }
};

class Exceptie_Turneu{
  int an;
public:
    Exceptie_Turneu(int x)
    {
        an = x;
    }
    void afisare(){
        std::string mesaj = "Lista de orase a turneului din anul "+i2s(an)+" nu poate fi vida\n";
        MessageBox(NULL, mesaj.c_str(), "Turneu incorecta", MB_OK);
    }
};



#endif //TEMA1_POO_EXCEPTII_H
