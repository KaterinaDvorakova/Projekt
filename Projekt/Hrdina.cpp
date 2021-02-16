//
// Created by dvora on 30.11.2020.
//

#include "Hrdina.h"


Hrdina::Hrdina(std::string jmeno, int zivoty, int sila) {
    m_jmeno = jmeno;
    m_zivoty = zivoty;
    m_sila = sila;
    m_aktualniPredmet = -1;
}

void Hrdina::zobrazInventar() {
    for (int i = 0; i < m_inventar.size(); i++) {
        m_inventar.at(i);
        std::cout << m_inventar.at(i) << std::endl;
    }
}

void Hrdina::seberPredmet(Predmety *p) {
    m_inventar.push_back(*p);
}

void Hrdina::odhodPredmet(int id){
    int pozice=0;
    bool nasel = false;
    for (int i=0; i < m_inventar.size(); i++) {
        if(m_inventar.at(i).m_identifikator == id){ //Porovnavame identifikatory
            pozice=i;
            nasel= true;
        }
    }
    if(nasel == true){
        m_inventar.erase(m_inventar.begin() + pozice); //Mazani predmetu na pozici //Lokace.cpp
    }
}
int Hrdina::getZivoty() {
    return m_zivoty;
}

int Hrdina::getSila() {
        if(m_aktualniPredmet <=0){
            return m_sila;
        }
        else{
            return m_sila + m_inventar.at(m_aktualniPredmet).getPridanaSila();
        }
    }

void Hrdina::uberZivot(int okolik) {
    m_zivoty = m_zivoty - okolik;
    if(m_zivoty <= 0){
        std::cout << "Hrdina " << m_jmeno << " je mrtev" << std::endl;
    }
}

bool Hrdina:: zautoc(Nepritel* nepritel){
    if(nepritel->getZivoty() > 0) {
        int kolikUbrat = getSila();
        nepritel->uberZivot(kolikUbrat);
        if(nepritel->getZivoty() > 0) {
            return false;
        } else {
           std::cout << "Prave jsi zabil nepritele" << std::endl;
           return true;
        }
    }
    else{
        std::cout << "Nepritel je uz davno mrtvy" << std::endl;
        return true;
    }
}
