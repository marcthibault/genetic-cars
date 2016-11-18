#include <iostream>
#include "Moteur.h"

using namespace std;

int main()
{
    Moteur* m = new Moteur(10.0);
    for (int i = 0; i<600; i++){
        m->next();
    }
    return 0;
}

