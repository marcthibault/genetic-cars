#ifndef CAR_H
#define CAR_H

#include <vector>

#include<utility>

using namespace std;

class Car{
public :
    double r1; //rayon roue avant
    double d1; //densité roue avant
    double r2; //rayon roue arrière
    double d2; //densité roue arrière
    double D; //distance entre les deux roues
    double d; //densité de la carrosserie
    static int N=8; //nombre de sommets du polygone (carrosserie)
    vector<pair<double, double> > angles_distances; //coordonées polaires des points A3,...AN

    Car();
    Car(double r1, double d1, double r2, double d2, double D, double d, vector<pair<double, double> > angles_distances);

};

#endif // CAR_H
