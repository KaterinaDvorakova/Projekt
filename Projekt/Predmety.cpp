//
// Created by dvora on 30.11.2020.
//

#include "Predmety.h"

std::ostream &operator<< (std::ostream &os, const Predmety &a) {
    os << "Nazev: " << a.m_nazev << std:: endl;
    os << "Mnozstvi: " << a.m_mnozstvi<< std::endl;
    os << "Pridana sila: " << a.m_pridanaSila<< std::endl;
    os << "Pridane zivoty: " << a.m_pridaneZivoty<< std::endl;
    os << "Identifikator: " << a.m_identifikator << std::endl;
    return os;
}

Predmety::Predmety(int mnozstvi, int identifikator, std::string nazev, float pridanaSila) {
    m_nazev = nazev;
    m_identifikator = identifikator;
    m_pridanaSila = pridanaSila;
    m_pridaneZivoty = 0;
    m_mnozstvi = mnozstvi;
}

Predmety::Predmety(int mnozstvi, std::string nazev, int identifikator, int pridaneZivoty) {
    m_mnozstvi = mnozstvi;
    m_nazev = nazev;
    m_identifikator = identifikator;
    m_pridaneZivoty = pridaneZivoty;
    m_pridanaSila = 0;
}

float Predmety::getPridanaSila() {
    return m_pridanaSila;
}