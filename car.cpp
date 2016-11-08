#include "car.h"
#include <vector>
#include <utility>
#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;

static double r_max = 1;//Rayon maximal
static double D_max = 4;//Distance entre les deux roues maximale
static double d_max = 1;//Densité maximale
static double distance_max = 6;//Distance des points au centre maximale
static int N=8;//Nombre de sommets du polygone


Car::Car(double r1, double d1, double r2, double d2, double D, double d, vector<pair<double, double> > angles_distances)
    : r1(r1), d1(d1), r2(r2), d2(d2), D(D), d(d), angles_distances(angles_distances){}

Car::Car(){
    srand(time(0));
    r1 = (double) rand() / RAND_MAX * r_max;
    r2 = (double) rand() / RAND_MAX * r_max;
    d1 = (double) rand() / RAND_MAX * d_max;
    d2 = (double) rand() / RAND_MAX * d_max;
    D = (double) rand() / RAND_MAX * D_max;
    d = (double) rand() / RAND_MAX * d_max;

    vector<pair<double, double> > angles_distances;

    for(int i=0; i<N-2; i++){
        double angle =  (double) rand() / RAND_MAX * 2 * M_PI;
        double distance = (double) rand() / RAND_MAX * distance_max;
        angles_distances.push_back(pair<double, double> (angle,distance));
    }
}

bool violate_constraint(double candidate,vector<double> S){
    for (std::vector<double>::iterator i=S.begin();i!=S.end();i++){
        if (candidate==(*i)) return true;
    }
    return false;
}

Car Jeep= Car();
