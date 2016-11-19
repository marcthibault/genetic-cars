#ifndef MOTEUR_H
#define MOTEUR_H

#include "Box2D/Box2D.h"
#include "b2Car.h"
#include "Floor.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

struct CouplePositionXVoiture
{
    float x;
    unsigned int voiture;
    CouplePositionXVoiture(float x1, unsigned int voiture1) : x(x1), voiture(voiture1) {}
};
struct greater_than
{
    inline bool operator() (const CouplePositionXVoiture& couple1, const CouplePositionXVoiture& couple2){
        return (couple1.x > couple2.x);
    }
};


class Moteur{

public :
    Moteur();
    Moteur(float32 g);
    float t; // temps dans le moteur physique

    float32 timeStep;
    int32 velocityIterations;
    int32 positionIterations;


    Floor* b2floor;
    float gravite;
    std::vector<b2World*> world;
    std::vector<b2Car*> car;

    void next(float dt); // Avance de dt dans le moteur physique et mets à jour les paramètres
    void printPositions();
    void getPosition();
    void classement(); // Met à jour le classement des voitures.
    bool toutesCarBloquees(float tempsStagnationMax); // si true la course s'arrete
};

#endif // MOTEUR_H
