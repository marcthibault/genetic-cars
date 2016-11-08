#ifndef CAR_H
#define CAR_H

#include <vector>

using namespace std;

class Car
{
public :
    static const int nNoeuds = 10; // nombre total de noeuds
    double rayon1;
    double rayon2;
    double L; // distance entre les roues
    double densiteRoue1;
    double densiteRoue2;
    double densiteVoiture;

    vector<double> angles;
    vector<double> distances; // tailles des rayons
    Car();
    Car(double rayon1, double rayon2, double L, double densiteRoue1, double densiteRoue2, double densiteVoiture, vector<double> angles, vector<double> distances);
    void printCar();
};

#endif // CAR_H
