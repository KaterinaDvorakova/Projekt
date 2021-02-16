//
// Created by dvora on 30.11.2020.
//

#ifndef PROJEKT_PREDMETY_H
#define PROJEKT_PREDMETY_H
#include <iostream>

class Predmety{
public:
    int m_identifikator;
    int m_mnozstvi;
    std::string m_nazev;
    float m_pridanaSila;
    int m_pridaneZivoty;


Predmety(int mnozstvi, int identifikator, std::string nazev, float pridanaSila);
Predmety(int mnozstvi, std::string nazev, int identifikator, int pridaneZivoty);
Predmety() = default; //Hra.cpp Ziskej predmet
float getPridanaSila();

};
std::ostream &operator << (std::ostream &os, const Predmety &a);

#endif //PROJEKT_PREDMETY_H
