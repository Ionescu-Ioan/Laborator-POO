//
// IONESCU IOAN
// GRUPA 151
// COMPILATOR: GCC VERSIUNE 8.1.0
// ASISTENT: MARIUS MICLUTA-CAMPEANU
//

#ifndef TEMA1_POO_INFORMATII_TRUPA_H
#define TEMA1_POO_INFORMATII_TRUPA_H
#include <string>
class Informatii_trupa {
private:
    Informatii_trupa () = default;
    static Informatii_trupa * pi;
    static std::string informatii;
public:
    static Informatii_trupa * get_informatii();
    static void set_informatii(const std::string &i);
    static std::string get_info();
};


#endif //TEMA1_POO_INFORMATII_TRUPA_H
