//
// Created by Ionut on 4/4/2021.
//

#ifndef TEMA1_POO_EXCEPTII_H
#define TEMA1_POO_EXCEPTII_H
#include <string>
#include "rlutil.h"
#include "portable_file_dialogs.h"
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
        pfd::message ("Eroare fisier!", mesaj);
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
            pfd::message ("Eroare varsta persoana!", "Varsta a fost introdusa gresit. Varsta nu poate fi < 14");
      else if(ok==2)
        {
          std::string mesaj = "Numele "+nume+" nu este corect!";
            pfd::message("Eroare nume persoana!", mesaj);
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
        pfd::message("Eroare melodie!", mesaj);
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
        pfd::message("Eroare turneu!", mesaj);
    }
};


#endif //TEMA1_POO_EXCEPTII_H
