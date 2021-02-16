//
// Created by dvora on 30.11.2020.
//

#include "Lokace.h"


void Lokace::pridejPredmet(Predmety *p) {
    m_predmety.push_back(*p);
}

void Lokace::odeberPredmet(int id) {
    int pozice = 0;
    bool nasel = false;
    for (int i = 0; i < m_predmety.size(); i++) { //Jestli je něco v m_predmety
        if (m_predmety.at(i).m_identifikator == id) { // Jestli to sedí na id které chceme odebrat
            pozice = i;
            nasel = true;
        }
    }
    if(nasel == true) m_predmety.erase(m_predmety.begin() + pozice); //Mazání vektoru na pozici
}

void Lokace::vypisPredmety() {
    for(int i = 0; i < m_predmety.size(); i++){
        std::cout << m_predmety.at(i) << std::endl;
    }
}

Lokace::Lokace(std::string nazev) {
    m_nazev = nazev;
}

std::string Lokace::ziskejNazev() {
    return m_nazev;
}

bool Lokace::overVitezstvi() {
    return m_posun;
}

void Lokace::pridejNepritele(Nepritel *n){
    m_nepratele = n;

}

void Lokace::pridejPopisLokace(std::string &popis) {
    m_popis = popis;
}

std::string Lokace::getPopisLokace() {
    return m_popis;
}

std::string Lokace::getMozneAkce() {
    std::string akce = "";
    if(m_nepratele != nullptr){
        akce.append("Muzes zautocit \n");
    }
    if(m_predmety.size()>0){
        akce.append("Muzes sebrat \n");
    }
    return akce;
}

void Lokace::vypisNepratele() {
        std::cout << m_nepratele << std::endl;
    }


Predmety *Lokace::ziskejPredmet(int predmet_id){
    Predmety *docasnyPredmet = new Predmety(); //Docasna promenna do ktere si nahrajeme novy Predmet
    for (int i = 0; i < m_predmety.size(); i++){
        if ( m_predmety.at(i).m_identifikator == predmet_id ){ //Porovnavame id a identifikator

            docasnyPredmet->m_identifikator = m_predmety.at(i).m_identifikator;
            docasnyPredmet->m_mnozstvi = m_predmety.at(i).m_mnozstvi;
            docasnyPredmet->m_nazev = m_predmety.at(i).m_nazev;
            docasnyPredmet->m_pridanaSila = m_predmety.at(i).m_pridanaSila;
            docasnyPredmet->m_pridaneZivoty = m_predmety.at(i).m_pridaneZivoty;
            return docasnyPredmet;
        }
    }
    return nullptr;
}

Nepritel *Lokace::ziskejNepritele() {
    return m_nepratele;
}

void Lokace::vyhranaLokace() {
    m_posun = true;
}