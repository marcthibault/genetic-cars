#include "Moteur.h"

Moteur::Moteur(){
    b2Vec2 gravity(0.0f, -10.0f);
    b2World *m_world = new b2World(gravity);

    b2floor =  new Floor();

    b2CarsList = new vector<b2Car>;
    b2CarsList->push_back(b2Car());
}

void Moteur::next(){

}

std::vector<float[3]> Moteur::getPosition(){
    std::vector< float[3] > v;
    float zero [3];
    zero[0] = 0;
    zero[1] = 0;
    zero[2] = 0;
    v.push_back( zero );
    return v;
}
