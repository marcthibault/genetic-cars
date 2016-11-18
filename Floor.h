#ifndef FLOOR_H
#define FLOOR_H

#include "Box2D/Box2D.h"
#include <list>
#include <random>

class Floor
{
public:
    Floor();
    Floor(double l, double v);
    double getLength();
    double getVariance();
    void createArrayb2Vec2(int N);
    void floorInitialize(b2World* world);
//    void extend();
private:
    double length;
    double variance;
    std::list<b2Vec2>* p;
};
#endif // FLOOR_H
