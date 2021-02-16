#include <iostream>
#include "Hra.h"


int main() {

    Hra* hra = new Hra("Jsi Harry Potter. V kazde lokalite na tebe ceka jeden uhlavni nepritel. Abys mohl postoupit dal, musis zautocit a znicit nepritele. Mohou ti pomoct predmety ktere se v dane lokalite nachazi. Hodne stesti.");
    hra->test();
    hra->ziskejPrikaz();
    delete hra;
    return 0;

}

