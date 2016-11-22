#include <iostream>
#include "Moteur.h"

using namespace std;

int main()
{
    Moteur* m = new Moteur(10.0);
    while (!m->toutesCarBloquees(5.0)){
        m->next(1.0/20.0);
        m->printPositions();
    //std::vector< std::array<float,4> > bidule = m->getPosition() ; //test de la fonction getPosition
    }
    return 0;
}

