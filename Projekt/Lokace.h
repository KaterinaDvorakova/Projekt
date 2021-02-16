//
// Created by dvora on 30.11.2020.
//

#ifndef HRDINA_H_LOKACE_H
#define HRDINA_H_LOKACE_H
#include <vector>
#include "Predmety.h"
#include "Hrdina.h"
#include "Nepritel.h"

class Lokace {
    std::vector<Predmety> m_predmety;
    std::string m_nazev;
    bool m_posun = false;
    Nepritel* m_nepratele = nullptr;
    std::string m_popis;



public:
    void vypisPredmety();
    void pridejPredmet(Predmety *p);
    void odeberPredmet(int id); //odebíráme předměty pomocí id
    Lokace(std::string nazev);
    std:: string ziskejNazev();
    bool overVitezstvi();
    void pridejNepritele(Nepritel* n);
    void pridejPopisLokace(std::string &popis);
    std::string getPopisLokace();
    std::string getMozneAkce();
    void vypisNepratele();
    Predmety *ziskejPredmet(int predmet_id); //pro dočasnou proměnnou a identifikátor v Hra.cpp
    Nepritel* ziskejNepritele();
    void vyhranaLokace();
};


#endif //HRDINA_H_LOKACE_H
