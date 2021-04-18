#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Instrument_muzical.h"
#include "Persoana.h"
#include "Muzicant.h"
#include "Formatie.h"
#include "Vocalist.h"
#include <iomanip>
#include <windows.h>
#include "Exceptii.h"


std::vector <std::string> split(std::string s, char c = ' ')
{
    std::vector <std::string> vs;
    int poz = 0, i;
    for(i=0; i<s.length(); ++i)
        if(s[i] == c)
        {
            vs.push_back(s.substr(poz, i-poz));
            poz = i+1;
        }
    vs.push_back(s.substr(poz, i-poz));
    return vs;
}

Formatie citire()
{

    std::ifstream fin;
    std::string fname = "C:\\Users\\Ionut\\CLionProjects\\Laborator-POO-main\\Laborator-POO-main\\Tema1-POO\\Iris.txt";
    fin.open(fname.c_str());
    if (fin.fail())
        throw Exceptie_Lipsa_Fisier(fname);

    std::string s, t, ss, tt;
    int x, n, y;
    fin >> s;
    Formatie f(s);
    fin >> s >> x;

    Persoana p(s, x);
    f.set_manager(p);

    fin >> n;
    while (n--)
    {
        fin >> s >> x >> t;

        Muzicant m(s, t, x);
        f.add_muzicant(m);
    }

    fin >> n;

    while (n--)
    {
        fin >> s >> x >> t;

        Vocalist v(s, x, t);
        f.add_vocalist(v);
    }

    fin >> n;
    while (n--)
    {
        fin >> s >> x >> t >> ss >> tt;

        Cantaret c(s, x, t, ss, tt);
        f.add_cantaret(c);
    }

    fin >> n;
    while (n--)
    {
        fin >> s >> x >> y;

        Melodie m(s, x, y);
        f.add_melodie(m);
    }


    fin >> n;
    std::getline(fin, s);

    while (n--)
    {
        std::getline(fin, s);
        std::vector <std::string> vs = split(s);
        int an = stoi(vs[0]);
        std::vector <std::string> orase;
        for (int i = 1; i < vs.size(); ++i)
            orase.push_back(vs[i]);

        Turneu t(orase, an);
        f.add_turneu(t);
    }

    return f;

}


void meniu()
{
    std::cout << "Meniu:\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Citire fisier\n";
    std::cout << "2. Adaugare\n";
    std::cout << "3. Set manager\n";
    std::cout << "4. Stergere\n";
    std::cout << "5. Afisare\n";
    ///de facut submeniuri

}

int main()
{
    try{
    ///test
        /*
        Formatie f1 = citire();
        f1.afisare_muzicanti();
        std::cout << "\n";
        f1.afisare_turnee();
        std::cout << "\n";
        f1.afisare_cantareti();
        std::cout << "\n";
        f1.afisare_vocalisti();
        std::cout << "afisare membrii" <<"\n";
        f1.update_membrii();
        f1.afisare_membrii();
        std::vector <Muzicant> v=f1.get_muzicanti();
        std::vector <Cantaret> v1=f1.get_cantareti();
        std::vector <Vocalist> v2=f1.get_vocalisti();
        f1.remove_muzicant(v[1]);
        f1.remove_cantaret(v1[1]);
        f1.remove_vocalist(v2[1]);
        f1.remove_manager();
        std::cout << "dupa stergere\n";
        f1.afisare_membrii();
        Persoana p("Abc", 80);
        f1.set_manager(p);
        Vocalist voc("BB", 34, "rock");
        f1.add_vocalist(voc);
        std::cout << "dupa adaugare\n";
        f1.afisare_membrii();
        f1.afisare_melodii();
        f1.afisare_turnee();
        */

        ///meniu interactiv


    }
    catch (Exceptie_Lipsa_Fisier e){
        e.afisare();
    }
    catch (Exceptie_Persoana e)
    {
        e.afisare();
    }
    catch (Exceptie_Melodie e)
    {
        e.afisare();
    }
    catch (Exceptie_Turneu e)
    {
        e.afisare();
    }

    return 0;
}


