#include "car.h"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;


Car(double rayon1, double rayon2, double L, double yO, double densiteRoue1, double densiteRoue2,
    double densiteVoiture, vector<double> angles, vector<double> distances)
    : rayon1(rayon1), rayon2(rayon2), L(L), densiteRoue1(densiteRoue1), densiteRoue2(densiteRoue2),
      densiteVoiture(densiteVoiture), angles(angles){}


Car::Car(){

}
