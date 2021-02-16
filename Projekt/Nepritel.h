//
// Created by dvora on 03.12.2020.
//

#ifndef HRDINA_H_NEPRITEL_H
#define HRDINA_H_NEPRITEL_H
#include "Predmety.h"
#include <vector>

class Nepritel {
    int m_zivoty;
    std::vector<Predmety> m_inventar;
    std:: string m_jmeno;
    int m_poskozeni;

public:
    int getZivoty();
    std::string getJmeno();
    int getPoskozeni();
    Nepritel(int zivoty, std::string jmeno, int poskozeni);
    void uberZivot(int okolik);

};

std::ostream &operator << (std::ostream &os, Nepritel &a);

#endif //HRDINA_H_NEPRITEL_H
