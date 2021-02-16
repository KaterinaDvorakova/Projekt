//
// Created by dvora on 03.12.2020.
//

#include "Nepritel.h"

Nepritel::Nepritel(int zivoty, std::string jmeno, int poskozeni) {
    m_jmeno = jmeno;
    m_poskozeni = poskozeni;
    m_zivoty = zivoty;
}
std::ostream &operator<< (std::ostream &os, Nepritel&a) {
    os << "Jmeno: " << a.getJmeno() << std::endl;
    os << "Zivoty: " << a.getZivoty() << std::endl;
    os << "Poskozeni: " << a.getPoskozeni() << std::endl;
    return os;
}

int Nepritel:: getZivoty(){
    return m_zivoty;
}
std::string Nepritel::getJmeno(){
    return m_jmeno;
}
int Nepritel::getPoskozeni(){
    return m_poskozeni;
}
void Nepritel::uberZivot(int okolik) {
    m_zivoty = m_zivoty - okolik;
    if(m_zivoty <= 0){
        std::cout << "Nepritel " << m_jmeno << " je mrtev" << std::endl;
    }
}