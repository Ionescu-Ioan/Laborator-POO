//
// IONESCU IOAN
// GRUPA 151
// COMPILATOR: GCC VERSIUNE 8.1.0
// ASISTENT: MARIUS MICLUTA-CAMPEANU
//

#ifndef TEMA1_POO_BRAND_H
#define TEMA1_POO_BRAND_H
#include <string>

class Brand {
private:
    Brand() = default;
    static Brand* pb;
    static std::string denumire;
public:
    static Brand* get_brand();
    static void set_brand(const std::string &d);
    static std::string get_denumire();
};




#endif //TEMA1_POO_BRAND_H
