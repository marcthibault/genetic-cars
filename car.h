#ifndef CAR_H
#define CAR_H

#include <vector>

using namespace std;

class Car
{
public :
    static int nNoeuds = 10; // nombre total de noeuds
    double rayon1;
    double rayon2;
    double L; // distance entre les roues
    double yO; // ordonnee du point O
    double densiteRoue1;
    double densiteRoue2;
    double densiteVoiture;

    vector<double> angles;
    vector<double> distances; // tailles des rayons
    Car();
    Car(double rayon1, double rayon2, double L, double yO, double densiteRoue1, double densiteRoue2, double densiteVoiture, vector<double> angles, vector<double> distances);
};

#endif // CAR_H
