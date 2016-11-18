#ifndef B2CAR_H
#define B2CAR_H

#include "Box2D/Box2D.h"
#include <iostream>

class b2Car
{
public:
    b2Car(); // Constructeur vide
    void initializeTestCar(b2World* m_world); // On construit une voiture test (celle de l'exemple Box2D) dans un monde pointé
    b2Body* m_car;

    void printPosition();
    //    b2Car(Car car); constructeur d'une b2Car (pouyr box2d) à partir d'une Car (ensemble de double)

};

#endif // B2CAR_H

