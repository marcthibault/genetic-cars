#include "car.h"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;


<<<<<<< HEAD
<<<<<<< HEAD
/*Car(double rayon1, double rayon2, double L, double yO, double densiteRoue1, double densiteRoue2,
    double densiteVoiture, vector<double> angles, vector<double> distances)
    : rayon1(rayon1), rayon2(rayon2), L(L), densiteRoue1(densiteRoue1), densiteRoue2(densiteRoue2),
      densiteVoiture(densiteVoiture), angles(angles){}*/

Car::Car(double rayon1, double rayon2, double L, double densiteRoue1, double densiteRoue2, double densiteVoiture, std::vector<double> angles, std::vector<double> distances){
   this->rayon1 = rayon1;
   this->rayon2 = rayon2;
   this->L = L;
   this->densiteRoue1 =  densiteRoue1;
   this->densiteRoue2 =  densiteRoue2;
   this->densiteVoiture = densiteVoiture;
   this->angles = angles;
   this->distances = distances;
}

Car::Car(){

=======
Car(double rayon1, double rayon2, double L, double yO, double densiteRoue1, double densiteRoue2,
    double densiteVoiture, vector<double> angles, vector<double> distances)
    : rayon1(rayon1), rayon2(rayon2), L(L), densiteRoue1(densiteRoue1), densiteRoue2(densiteRoue2),
      densiteVoiture(densiteVoiture), angles(angles){}

Car::Car(){

>>>>>>> 1a774373a9662524246a34f62248058396dda717
=======
Car(double rayon1, double rayon2, double L, double yO, double densiteRoue1, double densiteRoue2,
    double densiteVoiture, vector<double> angles, vector<double> distances)
    : rayon1(rayon1), rayon2(rayon2), L(L), densiteRoue1(densiteRoue1), densiteRoue2(densiteRoue2),
      densiteVoiture(densiteVoiture), angles(angles){}

Car::Car(){

>>>>>>> 1a774373a9662524246a34f62248058396dda717
}
