#ifndef MOTEUR_H
#define MOTEUR_H

#include<Box2D/Box2D.h>
#include <vector>

class Moteur{
private :
    b2World* world;
    std::vector<b2Car> b2CarsList;
    Floor* b2floor;

public :
    Moteur();

    void next();

    std::vector<float[3]> getPosition();


};

#endif // MOTEUR_H
