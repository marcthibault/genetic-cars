#include "Moteur.h"
#include "b2Car.h"

Moteur::Moteur(){
    car = std::vector<b2Car*>();
}

Moteur::Moteur(float32 g){
    this->world = new b2World(b2Vec2 (0.0, -10.0));
    this->timeStep = 1.0f / 60.0f;
    this->velocityIterations = 5;
    this->positionIterations = 5;
    this->car = std::vector<b2Car*>();

    Floor *fl = new Floor();

    fl->floorInitialize(world);

    b2Car* car1 = new b2Car();
    car.push_back(car1);

    // Initialiser toutes les voitures du vecteur
    // A refaire pourquoi pas avec un for_each !
    for (std::vector<b2Car*>::iterator i = car.begin(); i!=car.end(); i++){
        b2Car* currentCar = (*i);
        currentCar->initializeTestCar(world);
    }
}

void Moteur::next(){
    this->world->Step(this->timeStep, this->velocityIterations, this->positionIterations);
    b2Car* car1 = car.at(0);
    b2Vec2 position = car1->m_car->GetPosition();
    float32 angle = car1->m_car->GetAngle();
    std::cout << " X : " << position.x << " \t Y : " << position.y << " \t Angle : " << angle << std::endl;
}

void Moteur::printPositions(){
    for (std::vector<b2Car*>::iterator i = car.begin(); i!=car.end(); i++){
        b2Car* currentCar = (*i);
        currentCar->printPosition();
    }
}


void Moteur::getPosition(){
    // A refaire pourquoi pas avec un for_each !
    for (std::vector<b2Car*>::iterator i = car.begin(); i!=car.end(); i++){
        b2Car* currentCar = (*i);
        float angle = currentCar->m_car->GetAngle();
        float x = currentCar->m_car->GetPosition().x;
        float y = currentCar->m_car->GetPosition().y;
    }
    return ;
}

