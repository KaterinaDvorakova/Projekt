//
// Created by dvora on 03.12.2020.
//

#ifndef HRDINA_H_HRA_H
#define HRDINA_H_HRA_H
#include <iostream>
#include "Hrdina.h"
#include <vector>
#include "Lokace.h"

class Hra {
    std::vector<Lokace> m_lokace;
    int m_aktualniLokace = 0;
    std::string m_uvedeni;
public:
    Hra(std::string uvedeni);
    Hrdina *hrdina = nullptr;
    std::string prikaz_Exit {"exit"};
    void ziskejPrikaz ();
    void test();
    void generujMapu();



};


#endif //HRDINA_H_HRA_H
