#ifndef CAR_H
#define CAR_H

#include <vector>

using namespace std;

class Car{
public :
<<<<<<< HEAD
    static const int nNoeuds = 10; // nombre total de noeuds
    double rayon1;
    double rayon2;
    double L; // distance entre les roues
    double densiteRoue1;
    double densiteRoue2;
    double densiteVoiture;
=======
    double r1; //rayon roue avant
    double d1; //densité roue avant
    double r2; //rayon roue arrière
    double d2; //densité roue arrière
    double D; //distance entre les deux roues
    double d; //densité de la carrosserie
    static int N=8; //nombre de sommets du polygone (carrosserie)
    vector<pair<double, double> > angles_distances; //coordonées polaires des points A3,...AN
>>>>>>> 1a774373a9662524246a34f62248058396dda717

    vector<double> angles;
    vector<double> distances; // tailles des rayons
    Car();
<<<<<<< HEAD
    Car(double rayon1, double rayon2, double L, double densiteRoue1, double densiteRoue2, double densiteVoiture, vector<double> angles, vector<double> distances);
=======
    Car(double r1, double d1, double r2, double d2, double D, double d, vector<pair<double, double> > angles_distances);

>>>>>>> 1a774373a9662524246a34f62248058396dda717
};

#endif // CAR_H
