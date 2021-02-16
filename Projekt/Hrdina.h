//
// Created by dvora on 30.11.2020.
//

#ifndef PROJEKT_HRDINA_H
#define PROJEKT_HRDINA_H
#include <iostream>
#include <vector>
#include "Predmety.h"
#include "Nepritel.h"

class Hrdina {
    std::string m_jmeno;
    int m_zivoty;
    int m_sila;
    int m_aktualniPredmet;
    std::vector<Predmety> m_inventar;
public:
    Hrdina(std::string jmeno, int zivoty, int sila);
    void zobrazInventar();
    void seberPredmet(Predmety *p);
    void odhodPredmet(int id);
    bool zautoc(Nepritel* nepritel);
    int getZivoty();
    int getSila();
    void uberZivot(int okolik);

};

#endif //PROJEKT_HRDINA_H
