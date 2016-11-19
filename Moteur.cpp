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

    Floor *fl = new Floor(15.0);
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

void Moteur::next(float dt){
    // On fait avancer le moteur physique
    unsigned int n = floor(dt/timeStep);
    for (unsigned int i=0; i<n; i++){
        this->world->Step(this->timeStep, this->velocityIterations, this->positionIterations);
    }
    t += n*timeStep;
    // On met à jour les paramètres des voitures qui ne sont pas pris en compte par Box2D
    for (std::vector<b2Car*>::iterator i = car.begin(); i!=car.end(); i++){
        b2Car* currentCar = (*i);
        if (currentCar->positionMaximale->x < currentCar->m_car->GetPosition().x){
            // on est dans le cas où la voiture avance
            *(currentCar->positionMaximale) = currentCar->m_car->GetPosition();
        }
        else{
            // on est dans le cas où la voiture stagne
            // on incrémente le temps de stagnation de la voiture
            currentCar->tempsStagnation += n*timeStep;
        }
    }
}

void Moteur::printPositions(){
    std::cout << "Au temps : " << t << std::endl;
    for (std::vector<b2Car*>::iterator i = car.begin(); i!=car.end(); i++){
        b2Car* currentCar = (*i);
        std::cout << "\n" << currentCar->nom;
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
    // A compléter
    // TODO
    return ;
}

bool Moteur::toutesCarBloquees(float tempsStagnationMax){
    std::vector<b2Car*>::iterator i = car.begin();
    bool retour = true;
    while (retour && i!=car.end()){
        b2Car* currentCar = (*i);
        retour = currentCar->bloquee(tempsStagnationMax) & retour;
        i++;
    }
    return retour;
}
