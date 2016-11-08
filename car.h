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
    vector<pair<double, double> > angles_distances; //coordonées polaires des points A3,...AN
    bool ordered;
     struct { bool operator()(pair<double, double> a, pair<double, double> b) { return a.first < b.second; } } pair_inf;

    Car(); //constructeur (random)
    Car(double r1, double d1, double r2, double d2, double D, double d, vector<pair<double, double> > angles_distances); //constructeur

    double get_angle_wheel(); //cf schéma (angle théta)
    bool check_constraint(); //vérifie si l'angle candidat ne coincide pas avec les roues
    void order_angles();
    bool violate_constraint(double candidate,vector<double> S); //renvoie True si l'angle candidat existe déjà dans S!
    vector<pair<double, double> > get_points(); //renvoie les sommets du polygones (dans l'ordre trigonométrique)
    vector<int> get_wheels_index(); //renvoie les positions des roues avant et arrière dans le polygone
};

#endif // CAR_H
