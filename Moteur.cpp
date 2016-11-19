#include "Moteur.h"
#include "b2Car.h"

Moteur::Moteur(){
    car = std::vector<b2Car*>();
}

Moteur::Moteur(float32 g){

    this->timeStep = 1.0f / 60.0f;
    this->velocityIterations = 5;
    this->positionIterations = 5;

    Floor *fl = new Floor(15.0);

    this->car = std::vector<b2Car*>();
    b2Car* car1 = new b2Car();
    car.push_back(car1);
    b2Car* car2 = new b2Car();
    car.push_back(car2);

    int     compteur = 0;
    for(std::vector<b2Car*>::iterator i = car.begin(); i != car.end(); i++){
        b2Car* currentCar = (*i);
        b2World* currentWorld = new b2World(b2Vec2(0.0, -g));
        if (compteur == 0){ currentCar->initializeTestCar(currentWorld); } else{currentCar->initializeTestCarNulle(currentWorld);}
        fl->floorInitialize(currentWorld);
        world.push_back(currentWorld);
        compteur++;
    }





    // Initialiser toutes les voitures du vecteur
//    for (std::vector<b2Car*>::iterator i = car.begin(); i!=car.end(); i++){
//        b2Car* currentCar = (*i);
//        currentCar->initializeTestCar(world);
//    }
}

void Moteur::next(float dt){
    // On fait avancer le moteur physique
    unsigned int n = floor(dt/timeStep);
    for (unsigned int i=0; i<n; i++){
        for(std::vector<b2World*>::iterator i = world.begin(); i != world.end(); i++){
            b2World* currentWorld = (*i);
            currentWorld->Step(this->timeStep, this->velocityIterations, this->positionIterations);
        }
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
    this->classement();
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

void Moteur::classement(){
    // Récupération des couples position/voiture
    std::vector<CouplePositionXVoiture> positionVoiture = std::vector<CouplePositionXVoiture> ();
    unsigned int compteur = 0;
    for (std::vector<b2Car*>::iterator i = car.begin(); i!=car.end(); i++){
        b2Car* currentCar = (*i);
        positionVoiture.push_back(CouplePositionXVoiture(currentCar->m_car->GetPosition().x, compteur));
        compteur ++;
    }
    // Tri des positionHorizontale
    compteur = 1;
    std::sort(positionVoiture.begin(), positionVoiture.end(), greater_than());
    // On réaffecte le classment
    for (std::vector<CouplePositionXVoiture>::iterator i = positionVoiture.begin(); i!=positionVoiture.end(); i++){
        CouplePositionXVoiture currentPositionVoiture = (*i);
        (car.at(currentPositionVoiture.voiture))->classement = compteur;
        compteur++;
    }
}


