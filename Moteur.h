#ifndef MOTEUR_H
#define MOTEUR_H

#include "Box2D/Box2D.h"
#include "b2Car.h"
#include "Floor.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


class Moteur{

public :
    Moteur();
    Moteur(float32 g);
    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;
    void next(float dt);
    void printPositions();
    b2World* world;
    Floor* b2floor;
    std::vector<b2Car*> car;
    void getPosition();
    bool toutesCarBloquees(float tempsStagnationMax);
    float t; // temps dans le moteur physique
};

#endif // MOTEUR_H
