#include "firstLearner.h"
#include <vector>
#include <utility>
#include <math.h>
#include <limits>
#include <iostream>
using namespace std;
// (TODO ) adapt to new variable names in car.h

firstLearner::firstLearner(int car_number,int point_voiture,vector<Car> listcar,vector<int> ranking,vector<double> scores){
    this->car_number=car_number;
    this->point_voiture= point_voiture;
    this->listcar=listcar;
    this->ranking=ranking;
    this->scores=scores;
    parameters_number=6 + 2* point_voiture;

    for(int i = 0; i <parameters_number ; i++){
        this->corrolations_ranking.push_back(0);
        this->corrolations_scores.push_back(0);
    }
}
// Transform an object Car in vector
std::vector<double> firstLearner::openCar(Car my_car){
    std::vector<double> data;
    data.push_back(my_car.r1);
    data.push_back(my_car.d1);
    data.push_back(my_car.r2);
    data.push_back(my_car.d2);
    data.push_back(my_car.D);
    data.push_back(my_car.d);
    for(int i=0;i< point_voiture;i++){

       data.push_back((my_car.get_points_without_wheels())[i].first);
       data.push_back((my_car.get_points_without_wheels())[i].second);
    }

    return data;
}
// Convert vector in car
Car firstLearner::returnCar(std::vector<double> attributes){
    Car my_car = Car();
    my_car.r1 = attributes[0];
    my_car.d1 = attributes[1];
    my_car.r2 = attributes[2];
    my_car.d2 = attributes[3];
    my_car.D = attributes[4];
    my_car.d = attributes[5];

    for(int j = 0; j < point_voiture; j++){
        my_car.angles_distances.push_back(pair<double, double> (attributes[6+2*j],attributes[7+2*j]));
    }
    return my_car;
}
// transform all cars to matrix
void firstLearner::make_cars(){
    for(int i = 0; i <car_number ; i++){
        all_cars.push_back(openCar(listcar[i]));

    }

}

void firstLearner::compute_corrolations_ranking(){
    // store les moyennes pour le calcul de la variance/ covariance et coeff de correlation
    vector<double> param_mean;

    // store la covariance non normalisée
    vector<double> param_cov;
    //store la variance des parametres non normalisée
    vector<double> param_var;
    // store la moyenne et variance du ranking non normalisée
    double ranking_mean=0;
    double ranking_var=0;


    // initialization
    for(int i = 0; i <parameters_number ; i++){
        param_mean.push_back(0);
        param_cov.push_back(0);
        param_var.push_back(0);
    }
    // calcul des moyennes
    for(int i = 0; i <car_number ; i++){
        ranking_mean+=ranking[i];
        for(int j = 0; j <parameters_number ; j++){
            param_mean[j]+=all_cars[i][j];
        }
    }

    ranking_mean/= car_number;
    for(int j = 0; j <parameters_number ; j++){
        param_mean[j]/= car_number;
    }


    // calcul des variances et covariances non normalisée, ( l'effet de la normalisation se compense lors du calcul des parametres de corrélation )
    for(int i = 0; i <car_number ; i++){
        for(int j = 0; j <parameters_number ; j++){
            param_var[j]+=( all_cars[i][j] -  param_mean[j] )*( all_cars[i][j] -  param_mean[j] );
            param_cov[j]+=( all_cars[i][j] -  param_mean[j] )*(ranking[i]-ranking_mean);
        }
        ranking_var+=(ranking[i]-ranking_mean)* (ranking[i]-ranking_mean);

    }

    // calcul des coeff de corrélation
    for(int i = 0; i <parameters_number ; i++){
        if( param_cov[i]==0){
            corrolations_ranking[i]=0;
        }
        else{
            corrolations_ranking[i]= param_cov[i] /(   sqrt(param_var[i]*ranking_var)  ) ;
        }
    }

}


void firstLearner::compute_corrolations_scores(){
    // store les moyennes pour le calcul de la variance/ covariance et coeff de correlation
    vector<double> param_mean;

    // store la covariance non normalisée
    vector<double> param_cov;
    //store la variance des parametres non normalisée
    vector<double> param_var;
    // store la moyenne et variance du score non normalisée
    double scores_mean=0;
    double scores_var=0;


    // initialization
    for(int i = 0; i <parameters_number ; i++){
        param_mean.push_back(0);
        param_cov.push_back(0);
        param_var.push_back(0);
    }
    // calcul des moyennes
    for(int i = 0; i <car_number ; i++){
        scores_mean+=scores[i];
        for(int j = 0; j <parameters_number ; j++){
            param_mean[j]+=all_cars[i][j];
        }
    }

    scores_mean/= car_number;
    for(int j = 0; j <parameters_number ; j++){
        param_mean[j]/= car_number;
    }


    // calcul des variances et covariances non normalisée, ( l'effet de la normalisation se compense lors du calcul des parametres de corrélation )
    for(int i = 0; i <car_number ; i++){
        for(int j = 0; j <parameters_number ; j++){
            param_var[j]+=( all_cars[i][j] -  param_mean[j] )*( all_cars[i][j] -  param_mean[j] );
            param_cov[j]+=( all_cars[i][j] -  param_mean[j] )*(scores[i]-scores_mean);
        }
        scores_var+=(scores[i]-scores_mean)* (scores[i]-scores_mean);

    }

    // calcul des coeff de corrélation
    for(int i = 0; i <parameters_number ; i++){
        if( param_cov[i]==0){
            corrolations_scores[i]=0;
        }
        else{
            corrolations_scores[i]= param_cov[i] /(   sqrt(param_var[i]*scores_var)  ) ;
        }
        //std::cout << corrolations_scores[i] << " " <<param_cov[i] << " " << param_var[i]  << std::endl;
    }

}


Car firstLearner::predict_ranking_car(){
    // store les valeurs min et max apparus de chaque parametres
    vector<double> param_min(parameters_number);
    vector<double> param_max(parameters_number);
    vector<double> new_car(parameters_number);
    double max_val=numeric_limits<double>::max();

    for(int i = 0; i <parameters_number ; i++){

        param_min[i]=max_val;
        param_max[i]=-1;
        new_car[i]=0;
    }
    for(int i = 0; i <car_number ; i++){
        for(int j = 0; j <parameters_number ; j++){
            if(param_min[j] > all_cars[i][j]) {
             param_min[j] = all_cars[i][j];
            }
            if(param_max[j] < all_cars[i][j]) {
               param_max[j] = all_cars[i][j];
            }

        }
    }
    for(int i = 0; i <parameters_number ; i++){
        new_car[i]= param_max[i] + (corrolations_ranking[i]+1)/2   *(param_min[i]-param_max[i]);
    }
    vector<pair <double,double>> nouvelle_carcasse;

    for(int j = 0; j <point_voiture ; j++){
        nouvelle_carcasse.push_back(pair<double, double> (new_car[6+2*j],new_car[7+2*j]));

    }




    Car rank_car(new_car[0],new_car[3],new_car[1],new_car[4],new_car[2],new_car[5],nouvelle_carcasse);
    return rank_car;

}
Car firstLearner::predict_scores_car(){
    // store les valeurs min et max apparus de chaque parametres
    vector<double> param_min(parameters_number);
    vector<double> param_max(parameters_number);
    vector<double> new_car(parameters_number);
    double max_val=numeric_limits<double>::max();

    for(int i = 0; i <parameters_number ; i++){

        param_min[i]=max_val;
        param_max[i]=-1;
        new_car[i]=0;
    }
    for(int i = 0; i <car_number ; i++){
        for(int j = 0; j <parameters_number ; j++){
            if(param_min[j] > all_cars[i][j]) {
             param_min[j] = all_cars[i][j];
            }
            if(param_max[j] < all_cars[i][j]) {
               param_max[j] = all_cars[i][j];
            }

        }
    }
    //std::cout << parameters_number << std::endl;
    for(int i = 0; i <parameters_number ; i++){
        //std::cout << corrolations_scores[i] << std::endl;
        new_car[i]= param_min[i] + (corrolations_scores[i]+1)/2   *(param_max[i]-param_min[i]);
        //std::cout << new_car[i] << " " <<  param_min[i] << " " << param_max[i] << " "<<corrolations_scores[i]<<   std::endl;
    }
    vector<pair <double,double>> nouvelle_carcasse;

    for(int j = 0; j <point_voiture ; j++){
        nouvelle_carcasse.push_back(pair<double, double> (new_car[6+2*j],new_car[7+2*j]));

    }




    Car scores_car(new_car[0],new_car[3],new_car[1],new_car[4],new_car[2],new_car[5],nouvelle_carcasse);
    return scores_car;

}
