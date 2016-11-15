#include "car.h"
#include <vector>
#include <utility>
#include <iostream>

using namespace std;


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

}

void Car::printCar(){
    std::cout << "rayon1 = " << this->rayon1 << std::endl;
    std::cout << "rayon2 = " << this->rayon2 << std::endl;
    std::cout << "L = " << this->L << std::endl;
    std::cout << "densiteRoue1 = " << this->densiteRoue1 << std::endl;
    std::cout << "densiteRoue2 = " << this->densiteRoue2 << std::endl;
    std::cout << "densiteVoiture = " << this->densiteVoiture << std::endl;
    for (std::vector<double>::iterator it = this->angles.begin() ; it != this->angles.end(); ++it){
       std::cout << *it << std::endl;
    }
    for (std::vector<double>::iterator it = this->distances.begin() ; it != this->distances.end(); ++it){
      std::cout << *it << std::endl;
    }
 }
