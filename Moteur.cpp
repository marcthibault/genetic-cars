#include "Floor.h"
#include "car.h"
#include "b2Car.h"
#include "Moteur.h"

Moteur::Moteur(){
    b2Vec2 gravity(0.0f, -10.0f);
    b2World *world = new b2World(gravity);

    b2floor =  new Floor();

    std::vector<b2Car>* b2CarsList;
    b2CarsList->push_back(b2Car());
}

void Moteur::next(){

   // world->Step(timeStep, velocityIterations, positionIterations);

}

std::vector<float*> Moteur::getPosition(){
    std::vector< float* > v;
    float zero [3];
    zero[0] = 0;
    zero[1] = 0;
    zero[2] = 0;
    v.push_back( zero );
    return v;
}
