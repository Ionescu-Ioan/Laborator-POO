//
// Created by Ionut on 3/4/2021.
//

#ifndef TEMA1_POO_PERSOANA_H
#define TEMA1_POO_PERSOANA_H
#include <string>
class Persoana
{
public:
    Persoana(const std::string &name, int age);
    Persoana();
    ~Persoana();

    void set_nume(std::string &);
    void set_varsta(int);

    std::string get_nume();
    int get_varsta();

    Persoana& operator ++(int);
    std::string to_string();
    friend std::ostream& operator <<(std::ostream&, const Persoana&);
    friend std::istream& operator >>(std::istream&, Persoana&);
    bool operator ==(const Persoana&);

private:
    std::string nume;
    int varsta;
};
#endif //TEMA1_POO_PERSOANA_H
