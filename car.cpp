﻿#define _USE_MATH_DEFINES //Necessaire pour utiliser la constante M_PI
#include "car.h"
#include <vector>
#include <utility>
#include <iostream>
#include <math.h>
#include <time.h>
#include <algorithm>

using namespace std;

static double r_max = 1;//Rayon maximal
static double D_max = 4;//Distance entre les deux roues maximale
static double d_max = 1;//Densité maximale
static double distance_max = 6;//Distance des points au centre maximale
static int N=8;//Nombre de sommets du polygone


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
    double theta = get_angle_wheel();
    if(violate_constraint(M_PI+theta)||violate_constraint(2*M_PI-theta)) {
        std::cout<<"Raise Exception: angle constraint violated !" <<std::endl;
    }
}

Car::Car(double r1, double d1, double r2, double d2, double D, double d, vector<pair<double, double> > angles_distances)
    : r1(r1), d1(d1), r2(r2), d2(d2), D(D), d(d), angles_distances(angles_distances){
    double theta = get_angle_wheel();
    if(violate_constraint(M_PI+theta)||violate_constraint(2*M_PI-theta)) {
        std::cout<<"Raise Exception: angle constraint violated !" <<std::endl;
    }
}

double Car::get_angle_wheel(){ //angle théta (cf schéma)
    return atan(2*(this->r1)/(this->D));
}

vector<int> Car::get_wheels_index(){
    double theta = get_angle_wheel();
    vector<int> wheels_index;
    wheels_index.push_back(0); //roue arrière
    wheels_index.push_back(7); //roue avant
    for(int i=0;i<N-2;i++){
        if (std::get<0>(angles_distances[i])<M_PI+theta) wheels_index[0]++;
        else if (std::get<0>(angles_distances[i])>2*M_PI-theta) wheels_index[1]--;
    }
    return  wheels_index;
}

bool Car::violate_constraint(double angle){
    for (int i=0;i<N-2;i++){
        if (angle==std::get<0>(angles_distances[i])) {return true;}
    }
    return false;
}


vector<pair<double, double> > Car::get_points(){ //renvoie les sommets du polygones (dans l'ordre trigonométrique)
    vector<pair<double,double>> points = vector<pair<double,double>>(angles_distances);

    double theta=this->get_angle_wheel();
    double RC=sqrt(r1*r1+(D/2)*(D/2)); //distance from center C to wheel R
    points.push_back(pair<double,double>(M_PI+theta, RC));
    points.push_back(pair<double,double>(2*M_PI-theta, RC));

    std::sort(points.begin(),points.end());
    return points;
}

vector<pair<double, double> > Car::get_points_without_wheels(){
    vector<pair<double,double>> points = vector<pair<double,double>>(angles_distances);
    std::sort(points.begin(), points.end());
    return points;
}
