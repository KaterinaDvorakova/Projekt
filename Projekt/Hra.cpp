//
// Created by dvora on 03.12.2020.
//

#include "Hra.h"
#include "Nepritel.h"

Hra::Hra(std::string uvedeni) {
    m_uvedeni = uvedeni; //uvedeni do hry, Hra.h , main.cpp
    hrdina = new Hrdina("Harry", 100, 50);
    Predmety *petrificustotalus = new Predmety(2, 1, "Petrificus Totalus", 5.7);
    Predmety *MecGodricaNebelvira = new Predmety(1, "Mec Godrica Nebelvira", 2, 6);
    Predmety *ExpectoPatronum = new Predmety(3, "Expecto Patronum", 3, 7.0);
    hrdina->seberPredmet(petrificustotalus);
    hrdina->seberPredmet(MecGodricaNebelvira);
    hrdina->seberPredmet(ExpectoPatronum);
}

void Hra::ziskejPrikaz (){
    std::cout << m_uvedeni << std::endl;
    std::cout << std::endl;
    std::cout << "Mozne prikazy zjistis prikazem Help" << std::endl;
    while (true){
        if(hrdina->getZivoty()<=0){ //Hra skončila
            break;
        }
        std::string prikaz;
        std::cout << "Zadej prikaz: ";
        std::getline(std::cin,prikaz);
        std::cout << prikaz << std::endl;
        if(prikaz.compare(prikaz_Exit) == 0){
            break; //Konec hry
        }
        else if(prikaz.compare("Aktualni lokace") == 0){
            std::cout << m_lokace.at(m_aktualniLokace).ziskejNazev() << std::endl;
        }
        else if(prikaz.compare("Pokracuj dal") == 0){
            if(m_lokace.at(m_aktualniLokace).overVitezstvi()){
                m_aktualniLokace++; //Pokracujeme na dalsi lokaci
            } else{
                std::cout << "Nesplnil jsi vsechny ukoly" << std::endl;
            }
        }
        else if (prikaz.compare("Popis lokace") == 0){
         std::string popis = m_lokace.at(m_aktualniLokace).getPopisLokace();
         std::cout << popis << std::endl;
        }
        else if(prikaz.compare("Mozne akce") == 0){
            std::string akce = m_lokace.at(m_aktualniLokace).getMozneAkce();
            std::cout << akce << std::endl;
        }
        else if (prikaz.compare("Vypis predmety") == 0){
            m_lokace.at(m_aktualniLokace).vypisPredmety();
        }
        else if (prikaz.compare("Vypis nepratele") == 0) {
            m_lokace.at(m_aktualniLokace).vypisNepratele();
        }

        else if(prikaz.compare("Help") == 0){
            std::cout << "Vypis predmety - Vypise predmety v lokaci" << std::endl;
            std::cout << "Vypis nepratele - Vypise nepratele v lokaci" << std::endl;
            std::cout << "Mozne akce - Vypise vsechny akce co lze v lokaci udelat" << std::endl;
            std::cout << "Popis lokace - Vypise popis aktualni lokace" << std::endl;
            std::cout << "Pokracuj dal - Vypise zda muzeme prejit do dalsi lokace" << std::endl;
            std::cout << "Aktualni lokace - Vypise v jake lokaci se nachazime" << std::endl;
            std::cout << "Seber - Hrdina sebere predmet a predmet zmizí z inventare lokace" << std::endl;
        }
        else if(prikaz.compare("Seber") == 0){
            int id_predmet;
            std::cout << "Identifikator predmetu: ";
            std::string docasnaPromena;
            std::getline(std::cin, docasnaPromena);
            id_predmet = std::stoi(docasnaPromena); //Pretypovani z string na int
            Predmety *p = m_lokace.at(m_aktualniLokace).ziskejPredmet(id_predmet);
            if(p == nullptr){ //Zkontrolujeme jestli p neni nullptr, pokud ano tak vypis chybovou hlasku a pokracuj na dalsi prikaz
                std::cout << "Nepodarilo se najit predmet" << std::endl;
                continue;
            }
            hrdina->seberPredmet(p);
            m_lokace.at(m_aktualniLokace).odeberPredmet(id_predmet);
        }
        else if(prikaz.compare("Zautoc") == 0){
            Nepritel* nepritel = m_lokace.at(m_aktualniLokace).ziskejNepritele();
            bool posun = hrdina ->zautoc(nepritel);
            if(posun == true){
                m_lokace.at(m_aktualniLokace).vyhranaLokace();
            }
        }
        else
            {std::cout << "Prikaz nebyl rozpoznany" << std::endl;}

    }

}

void Hra::test() {
    hrdina->zobrazInventar();
    generujMapu();
    hrdina->odhodPredmet(2);
    hrdina->zobrazInventar();
}

void Hra::generujMapu() {
    m_lokace.emplace_back("Zakazane patro");
    std::string zakazanepatro = "Nachazis se v zakazanem patre. Vsude kolem je tma, a jedine co jde citit je psi dech..nebo spise dech tri psu?";
    m_lokace.back().pridejPopisLokace(zakazanepatro);
    Nepritel *chloupek = new Nepritel(100, "Trihlavy pes Chloupek", 20);
    m_lokace.back().pridejNepritele(chloupek);
    Predmety koste(3,1,"Koste", 5.9);
    m_lokace.back().pridejPredmet(& koste);
    Predmety okonorka(1, "Oko norka, harfy sum, promen vodu v dobry rum", 111, 20);
    m_lokace.back().pridejPredmet(& okonorka);

    m_lokace.emplace_back("Tajemna komnata");
    std::string tajemnakomnata = "Nachazis se v tajemne komnate. Ve velike mistnosti, s masivnimi kamennymi sochami.";
    m_lokace.back().pridejPopisLokace(tajemnakomnata);
    Nepritel *bazilisek = new Nepritel(100, "Bazilišek", 30);
    m_lokace.back().pridejNepritele(bazilisek);
    Predmety mec(2,2,"Mec Godrica Nebelvira",6.0);
    m_lokace.back().pridejPredmet(& mec);
    Predmety incendio(2, 22, "Incendio Tria", 20.0);
    m_lokace.back().pridejPredmet(& incendio);

    m_lokace.emplace_back("Chroptici chyse");
    std::string chropticichyse = "Nachazis se v Prasinkach. Vedle tebe je Chroptici chyse, ponura stavba, ze ktere se ozyvaji narky a skreky.";
    m_lokace.back().pridejPopisLokace(chropticichyse);
    Nepritel *krysa = new Nepritel(100, "Peter Petigrue", 40);
    m_lokace.back().pridejNepritele(krysa);
    Predmety expecto(4, 3, "Expecto Patronum", 30.0);
    m_lokace.back().pridejPredmet(& expecto);
    Predmety impervius(1, "Impervius", 33, 5);
    m_lokace.back().pridejPredmet(& impervius);

    m_lokace.emplace_back("Jezero");
    std::string jezero = "Nachazis se v jezere blizko Bradavic, kolem tebe jsou jezerni lide.";
    m_lokace.back().pridejPopisLokace(jezero);
    Nepritel *jezernilide = new Nepritel(100, "Jezerni lide", 50);
    m_lokace.back().pridejNepritele(jezernilide);
    Predmety zabernik(1,"Zabernik",4, 30);
    m_lokace.back().pridejPredmet(&zabernik);

    m_lokace.emplace_back("Komnata nejvyssi potreby");
    std::string komnata = "Nachazis se v komnate nejvyssi potreby. Ve svetle mistnosti, ktera si zije vlastnim zivotem.";
    m_lokace.back().pridejPopisLokace(komnata);
    Nepritel *profesorka = new Nepritel(100, "Profesorka Umbridgeova", 60);
    m_lokace.back().pridejNepritele(profesorka);
    Predmety fiendfyre(2, 5, "FiendFyre", 40.5);
    m_lokace.back().pridejPredmet(&fiendfyre);

    m_lokace.emplace_back("hospoda Deravy kotel");
    std::string deravykotel = "Nachazis se v hospode jmenem Deravy kotel.";
    m_lokace.back().pridejPopisLokace(deravykotel);
    Nepritel *smrtijed = new Nepritel(100, "Smrtijed", 70);
    m_lokace.back().pridejNepritele(smrtijed);
    Predmety aqua(1, 6, "Aqua Carcerem", 12.3);
    m_lokace.back().pridejPredmet(& aqua);
    Predmety pivo(3, "Kouzelne pivo", 66, 40);

    m_lokace.emplace_back("Gringottova banka");
    std::string gringottovabanka = "Nachazis se v Gringottove bance, vsude kolem tebe jsou skreti.";
    m_lokace.back().pridejPopisLokace(gringottovabanka);
    Nepritel *drak = new Nepritel(100, "Drak", 80);
    m_lokace.back().pridejNepritele(drak);
    Predmety bombarda(1, 7,"Bombarda Maxima",30.0);
    m_lokace.back().pridejPredmet(&bombarda);

    m_lokace.emplace_back("Bradavice");
    std::string bradavice = "Nachazis se na nadvori Bradavickeho hradu.";
    m_lokace.back().pridejPopisLokace(bradavice);
    Nepritel *voldemort = new Nepritel(100, "Voldemort", 90);
    m_lokace.back().pridejNepritele(voldemort);
    Predmety avada(1, 8, "Avada Kedavra",50.0);
    m_lokace.back().pridejPredmet(& avada);
}