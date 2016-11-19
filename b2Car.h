#ifndef B2CAR_H
#define B2CAR_H

#include "Box2D/Box2D.h"
#include <iostream>
#include <string>

class b2Car
{
public:
    b2Car(); // Constructeur vide
    void initializeTestCar(b2World* m_world); // On construit une voiture test (celle de l'exemple Box2D) dans un monde pointé
    b2Body* m_car;
    b2Vec2* positionMaximale; // Ce point enregistre les coordonnées du centre de la position la plus à droite de la voiture.
    float32 tempsStagnation;
    std::string nom;
    void printPosition();
    bool bloquee(float tempsStagnationMax);
    //    b2Car(Car car); constructeur d'une b2Car (pouyr box2d) à partir d'une Car (ensemble de double)

};

#endif // B2CAR_H

