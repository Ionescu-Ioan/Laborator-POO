#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Instrument_muzical.h"
#include "Persoana.h"
#include "Muzicant.h"
#include "Formatie.h"
//#include "Vocalist.h"
//#include <iomanip>
//#include "portable_file_dialogs.h"
#include "Exceptii.h"


std::vector<std::string> split(std::string s, char c = ' ') {
    std::vector<std::string> vs;
    int poz = 0, i;
    for (i = 0; i < s.length(); ++i)
        if (s[i] == c) {
            vs.push_back(s.substr(poz, i - poz));
            poz = i + 1;
        }
    vs.push_back(s.substr(poz, i - poz));
    return vs;
}

void salvare_date(std::string file_name, Formatie &f) {
    std::ofstream fout;
    std::string fname = "../" + file_name;
    fout.open(fname.c_str());
    fout << file_name.erase(file_name.size() - 4) << "\n";
    fout << f.get_manager().get_nume() << " " << f.get_manager().get_varsta() << "\n";
    int n = f.get_muzicanti().size();
    fout << n << "\n";
    for (int i = 0; i < n; ++i)
        fout << f.get_muzicanti()[i].get_nume() << " " << f.get_muzicanti()[i].get_varsta() << " "
             << f.get_muzicanti()[i].get_instrument() << "\n";

    n = f.get_vocalisti().size();
    fout << n << "\n";
    for (int i = 0; i < n; ++i)
        fout << f.get_vocalisti()[i].get_nume() << " " << f.get_vocalisti()[i].get_varsta() << " "
             << f.get_vocalisti()[i].get_gen_muzical() << "\n";

    n = f.get_cantareti().size();
    fout << n << "\n";
    for (int i = 0; i < n; ++i)
        fout << f.get_cantareti()[i].get_nume() << " " << f.get_cantareti()[i].get_varsta() << " "
             << f.get_cantareti()[i].get_instrument() << " " << f.get_cantareti()[i].get_gen_muzical() << " "
             << f.get_cantareti()[i].get_nume_scena() << "\n";

    n = f.get_melodii().size();
    fout << n << "\n";
    for (int i = 0; i < n; ++i)
        fout << f.get_melodii()[i].get_nume_melodie() << " " << f.get_melodii()[i].get_durata() << " "
             << f.get_melodii()[i].get_anul_lansarii() << "\n";

    n = f.get_turnee().size();
    fout << n << "\n";
    for (int i = 0; i < n; ++i) {
        fout << f.get_turnee()[i].get_an() << " ";
        for (int j = 0; j < f.get_turnee()[i].get_orase().size(); ++j)
            fout << f.get_turnee()[i].get_orase()[j] << " ";
        fout << "\n";
    }
    fout.close();
}

Formatie citire(std::string &fis_name) {

    std::ifstream fin;
    std::string fname = "../" + fis_name;
    fin.open(fname.c_str());
    if (fin.fail())
        throw Exceptie_Lipsa_Fisier(fname);

    std::string s, t, ss, tt, date;
    int x, n, y;
    float x1;
//    fin >> s;
    getline(fin, s);
    getline(fin, date);
    Formatie f(s, date);
    fin >> s >> x;

    Persoana p(s, x);
    f.set_manager(p);

    fin >> n;
    while (n--) {
        fin >> s >> x >> t;

        Muzicant m(s, t, x);
        f.add_muzicant(m);
    }

    fin >> n;

    while (n--) {
        fin >> s >> x >> t;

        Vocalist v(s, x, t);
        f.add_vocalist(v);
    }

    fin >> n;
    while (n--) {
        fin >> s >> x >> t >> ss >> tt;

        Cantaret c(s, x, t, ss, tt);
        f.add_cantaret(c);
    }

    fin >> n;
    while (n--) {
        fin >> s >> x1 >> y;

        Melodie m(s, x1, y);
        f.add_melodie(m);
    }


    fin >> n;
    std::getline(fin, s);

    while (n--) {
        std::getline(fin, s);
        std::vector<std::string> vs = split(s);
        int An = stoi(vs[0]);
        std::vector<std::string> Orase;
        for (int i = 1; i < vs.size(); ++i)
            Orase.push_back(vs[i]);

        Turneu T(Orase, An);
        f.add_turneu(T);
    }

    return f;

}


int meniu_afisare() {
    std::cout << "Meniu afisare:\n";
    std::cout << "0. Intoarcere la meniul principal\n";
    std::cout << "1. Afisati intreaga formatie\n";
    std::cout << "2. Afisati vocalistii foratiei\n";
    std::cout << "3. Afisati cantaretii foratiei\n";
    std::cout << "4. Afisati muzicantii foratiei\n";
    std::cout << "5. Afisati managerul formatiei\n";
    std::cout << "6. Afisati toti membrii formatiei\n";
    std::cout << "7. Afisati informatiile despre formatiei\n";

    int optiune = 0;
    std::cout << "Optiunea aleasa: ";
    do {
        std::cin >> optiune;
        if (optiune < 0 || optiune > 7)
            std::cout << "Optiune incorecta!\n";
    } while (optiune < 0 || optiune > 7);
    return optiune;
}

int meniu_adaugare() {
    std::cout << "Meniu adaugare:\n";
    std::cout << "0. Intoarcere la meniul principal\n";
    std::cout << "1. Adaugati un vocalist in formatie\n";
    std::cout << "2. Adaugati un cantaret in formatie\n";
    std::cout << "3. Adaugati un muzicant in formatie\n";

    int optiune = 0;
    std::cout << "Optiunea aleasa: ";
    do {
        std::cin >> optiune;
        if (optiune < 0 || optiune > 3)
            std::cout << "Optiune incorecta!\n";
    } while (optiune < 0 || optiune > 3);
    return optiune;
}

int meniu_stergere() {
    std::cout << "Meniu stergere:\n";
    std::cout << "0. Intoarcere la meniul principal\n";
    std::cout << "1. Stergeti un vocalist din formatie\n";
    std::cout << "2. Stergeti un cantaret din formatie\n";
    std::cout << "3. Stergeti un muzicant din formatie\n";

    int optiune = 0;
    std::cout << "Optiunea aleasa: ";
    do {
        std::cin >> optiune;
        if (optiune < 0 || optiune > 3)
            std::cout << "Optiune incorecta!\n";
    } while (optiune < 0 || optiune > 3);
    return optiune;
}

int meniu() {
    std::cout << "Meniu:\n";
    std::cout << "0. Exit\n";
    std::cout << "1. Citire fisier formatie\n";
    std::cout << "2. Adaugare\n";
    std::cout << "3. Set manager\n";
    std::cout << "4. Stergere\n";
    std::cout << "5. Afisare\n";
    std::cout << "6. Salvare date\n";

    int optiune = 0;
    std::cout << "Optiunea aleasa: ";
    do {
        std::cin >> optiune;
        if (optiune < 0 || optiune > 6)
            std::cout << "Optiune incorecta!\n";
    } while (optiune < 0 || optiune > 6);

    return optiune;
}

void afisare_formatie(Formatie &f) {

    std::cout << "\nNumele formatiei: " << f.get_nume_formatie() << "\n";
    std::cout << "Managerul: " << f.get_manager() << "\n";
    std::cout << "Informatii trupa: " << f.get_informatii() << "\n";
    std::cout << "Muzicantii:\n";
    f.afisare_muzicanti();
    std::cout << "\n";
    std::cout << "Vocalistii:\n";
    f.afisare_vocalisti();
    std::cout << "\n";
    std::cout << "Cantaretii:\n";
    f.afisare_cantareti();
    std::cout << "\n";
    std::cout << "Melodiile:\n";
    f.afisare_melodii();
    std::cout << "\n";
    std::cout << "Turneele:\n";
    f.afisare_turnee();
    std::cout << "\n";
}


int main() {
    Formatie f;
    int optiune;
    int optiune_submeniu;
    std::string nume_fisier;
    std::string name;
    int varsta;
    std::string gen_muzical;
    std::string instrument_muzical;
    std::string nume_scena;
    std::string nume_manager;
    Vocalist v;
    Cantaret c;
    Muzicant m;
    Persoana p;
    try {
        do {
            optiune = meniu();

            switch (optiune) {
                case 1:
                    std::cout << "Introduceti numele fisierului/formatiei: ";
                    std::cin >> nume_fisier;
                    f = citire(nume_fisier);
                    break;

                case 2:
                    optiune_submeniu = meniu_adaugare();
                    switch (optiune_submeniu) {
                        case 1:
                            std::cout << "Introduceti datele pentru un nou vocalist\n";
                            std::cout << "Nume: ";
                            std::cin >> name;
                            std::cout << "Varsta: ";
                            std::cin >> varsta;
                            std::cout << "Gen muzical: ";
                            std::cin >> gen_muzical;
                            v = Vocalist(name, varsta, gen_muzical);
                            f.add_vocalist(v);
                            break;

                        case 2:
                            std::cout << "Introduceti datele pentru un nou cantaret\n";
                            std::cout << "Nume: ";
                            std::cin >> name;
                            std::cout << "Varsta: ";
                            std::cin >> varsta;
                            std::cout << "Gen muzical: ";
                            std::cin >> gen_muzical;
                            std::cout << "Instrument muzical: ";
                            std::cin >> instrument_muzical;
                            std::cout << "Nume de scena: ";
                            std::cin >> nume_scena;
                            c = Cantaret(name, varsta, instrument_muzical, gen_muzical, nume_scena);
                            f.add_cantaret(c);
                            break;

                        case 3:
                            std::cout << "Introduceti datele pentru un nou muzicant\n";
                            std::cout << "Nume: ";
                            std::cin >> name;
                            std::cout << "Varsta: ";
                            std::cin >> varsta;
                            std::cout << "Instrument muzical: ";
                            std::cin >> instrument_muzical;
                            m = Muzicant(name, instrument_muzical, varsta);
                            f.add_muzicant(m);
                            break;
                    }
                    break;

                case 3:
                    std::cout << "Introduceti noul manager\n";
                    std::cout << "Nume: ";
                    std::cin >> name;
                    std::cout << "Varsta: ";
                    std::cin >> varsta;
                    p = Persoana(name, varsta);
                    f.set_manager(p);
                    break;

                case 4:
                    optiune_submeniu = meniu_stergere();
                    switch (optiune_submeniu) {
                        case 1:
                            std::cout << "Introduceti datele vocalistului care va fi eliminat\n";
                            std::cout << "Nume: ";
                            std::cin >> name;
                            std::cout << "Varsta: ";
                            std::cin >> varsta;
                            std::cout << "Gen muzical: ";
                            std::cin >> gen_muzical;
                            v = Vocalist(name, varsta, gen_muzical);
                            f.remove_vocalist(v);
                            break;

                        case 2:
                            std::cout << "Introduceti datele cantaretului care va fi eliminat\n";
                            std::cout << "Nume: ";
                            std::cin >> name;
                            std::cout << "Varsta: ";
                            std::cin >> varsta;
                            std::cout << "Gen muzical: ";
                            std::cin >> gen_muzical;
                            std::cout << "Instrument muzical: ";
                            std::cin >> instrument_muzical;
                            std::cout << "Nume de scena: ";
                            std::cin >> nume_scena;
                            c = Cantaret(name, varsta, instrument_muzical, gen_muzical, nume_scena);
                            f.remove_cantaret(c);
                            break;

                        case 3:
                            std::cout << "Introduceti datele muzicantului care va fi eliminat\n";
                            std::cout << "Nume: ";
                            std::cin >> name;
                            std::cout << "Varsta: ";
                            std::cin >> varsta;
                            std::cout << "Instrument muzical: ";
                            std::cin >> instrument_muzical;
                            m = Muzicant(name, instrument_muzical, varsta);
                            f.remove_muzicant(m);
                            break;
                    }
                    break;

                case 5:
                    optiune_submeniu = meniu_afisare();
                    switch (optiune_submeniu) {
                        case 1:
                            afisare_formatie(f);
                            std::cout << "\n";
                            break;

                        case 2:
                            f.afisare_vocalisti();
                            std::cout << "\n";
                            break;

                        case 3:
                            f.afisare_cantareti();
                            std::cout << "\n";
                            break;

                        case 4:
                            f.afisare_muzicanti();
                            std::cout << "\n";
                            break;

                        case 5:
                            std::cout << "Manager: "<< f.get_manager() << "\n";
                            break;

                        case 6:
                            f.afisare_membrii();
                            std::cout << "\n";
                            break;

                        case 7:
                            std::cout << "Informatii trupa: " << f.get_informatii() << "\n";
                            break;
                    }
                    break;

                case 6:
                    std::cout << "Introduceti numele fisierului in care doriti sa salvati informatiile: ";
                    std::cin >> nume_fisier;
                    salvare_date(nume_fisier, f);
                    std::cout << "Datele au fost salvate\n";
                    break;
            }
        } while (optiune != 0);

    }
    catch (Exceptie_Lipsa_Fisier &e) {
        e.afisare();
        return 1;
    }
    catch (Exceptie_Persoana &e) {
        e.afisare();
        return 1;
    }
    catch (Exceptie_Melodie &e) {
        e.afisare();
        return 1;
    }
    catch (Exceptie_Turneu &e) {
        e.afisare();
        return 1;
    }


    return 0;
}




