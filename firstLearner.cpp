#include "firstLearner.h"
#include <vector>
#include <utility>
#include <math.h>
#include <limits>
using namespace std;
// (TODO ) adapt to new variable names in car.h

firstLearner::firstLearner(int car_number,int point_voiture,vector<car> listcar,vector<int> ranking,vector<double> scores){
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

void firstLearner::compute_corrolations_ranking(){
    // store les moyennes pour le calcul de la variance/ covariance et coeff de correlation
    vector<double> param_mean(parameters_number);

    // store la covariance non normalisée
    vector<double> param_cov(parameters_number);
    //store la variance des parametres non normalisée
    vector<double> param_var(parameters_number);
    // store la moyenne et variance du ranking non normalisée
    double ranking_mean=0;
    double ranking_var=0;


    // initialization
    for(int i = 0; i <parameters_number ; i++){
        param_mean[i]=0;
        param_cov[i]=0;
        param_var[i]=0;
    }
    // calcul des moyennes
    for(int i = 0; i <car_number ; i++){
        ranking_mean+=ranking[i];
        param_mean[0]+=  listcar[i]->r1;
        param_mean[1]+=  listcar[i]->r2;
        param_mean[2]+=  listcar[i]->D;
        param_mean[3]+=  listcar[i]->d1;
        param_mean[4]+=  listcar[i]->d2;
        param_mean[5]+=  listcar[i]->d;
        //angles_distances  contients les points de carcasse différent de R1,R2
        for(int j = 0; j <point_voiture ; j++){
            param_mean[6+2*j]+=(listcar[i]->angles_distances)[j].first;  // first is angle, second is distance
            param_mean[7+2*j]+=(listcar[i]->angles_distances)[j].second;
        }
    }

    ranking_mean/= car_number;
    param_mean[0]/= car_number;
    param_mean[1]/=  car_number;
    param_mean[2]/=  car_number;
    param_mean[3]/=  car_number;
    param_mean[4]/=  car_number;
    param_mean[5]/=  car_number;
    for(int j = 0; j <point_voiture ; j++){
        param_mean[6+2*j]/=car_number;
        param_mean[7+2*j]/=car_number;
    }


    // calcul des variances et covariances non normalisée, ( l'effet de la normalisation se compense lors du calcul des parametres de corrélation )
    for(int i = 0; i <car_number ; i++){
        param_var[0]+=  (listcar[i]->r1-param_mean[0])*(listcar[i]->r1-param_mean[0]);
        param_var[1]+=  (listcar[i]->r2-param_mean[1])*(listcar[i]->r2-param_mean[1]);
        param_var[2]+=  (listcar[i]->D-param_mean[2])*(listcar[i]->D-param_mean[2]);
        param_var[3]+=  (listcar[i]->d1-param_mean[3])*(listcar[i]->d1-param_mean[3]);
        param_var[4]+=  (listcar[i]->d2-param_mean[4])*(listcar[i]->d2-param_mean[4]);
        param_var[5]+=  (listcar[i]->d-param_mean[5])*(listcar[i]->d-param_mean[5]);
        param_cov[0]+=  (listcar[i]->r1-param_mean[0])*(ranking[i]-ranking_mean) ;
        param_cov[1]+=  (listcar[i]->r2-param_mean[1])*(ranking[i]-ranking_mean) ;
        param_cov[2]+=  (listcar[i]->D-param_mean[2])*(ranking[i]-ranking_mean);
        param_cov[3]+=  (listcar[i]->d1-param_mean[3])*(ranking[i]-ranking_mean);
        param_cov[4]+=  (listcar[i]->d2-param_mean[4])*(ranking[i]-ranking_mean);
        param_cov[5]+=  (listcar[i]->d-param_mean[5])*(ranking[i]-ranking_mean);
        for(int j = 0; j <point_voiture ; j++){
            param_var[6+2*j]+=( (listcar[i]->angles)[j].first -  param_mean[6+2*j] )*( (listcar[i]->angles)[j].first -  param_mean[6+2*j] );
            param_var[7+2*j]+=( (listcar[i]->distances)[j].second -  param_mean[7+2*j] )*( (listcar[i]->distances)[j].second -  param_mean[7+2*j] );
            param_cov[6+2*j]+=( (listcar[i]->angles)[j].first -  param_mean[6+2*j] )*(ranking[i]-ranking_mean);
            param_cov[7+2*j]+=( (listcar[i]->distances)[j].second -  param_mean[7+2*j] )*(ranking[i]-ranking_mean);
        }
        ranking_var+=(ranking[i]-ranking_mean)* (ranking[i]-ranking_mean);

    }

    // calcul des coeff de corrélation
    for(int i = 0; i <parameters_number ; i++){
        corrolations_ranking[i]= param_cov[i] /(   sqrt(param_var[i]*ranking_var)  ) ;
    }

}


void firstLearner::compute_corrolations_scores(){
        // store les moyennes pour le calcul de la variance/ covariance et coeff de correlation
        vector<double> param_mean(parameters_number);

        // store la covariance non normalisée
        vector<double> param_cov(parameters_number);
        //store la variance des parametres non normalisée
        vector<double> param_var(parameters_number);
        // store la moyenne et variance des scores non normalisée
        double scores_mean=0;
        double scores_var=0;


        // initialization
        for(int i = 0; i <parameters_number ; i++){
            scores_mean[i]=0;
            param_cov[i]=0;
            param_var[i]=0;
        }
        // calcul des moyennes
        for(int i = 0; i <car_number ; i++){
            scores_mean+=scores[i];
            param_mean[0]+=  listcar[i]->r1;
            param_mean[1]+=  listcar[i]->r2;
            param_mean[2]+=  listcar[i]->D;
            param_mean[3]+=  listcar[i]->d1;
            param_mean[4]+=  listcar[i]->d2;
            param_mean[5]+=  listcar[i]->d;
            for(int j = 0; j <point_voiture ; j++){
                param_mean[6+2*j]+=(listcar[i]->angles_distances)[j].first;  // first is angle, second is distance
                param_mean[7+2*j]+=(listcar[i]->angles_distances)[j].second;
            }
        }

        scores_mean/= car_number;
        param_mean[0]/= car_number;
        param_mean[1]/=  car_number;
        param_mean[2]/=  car_number;
        param_mean[3]/=  car_number;
        param_mean[4]/=  car_number;
        param_mean[5]/=  car_number;
        for(int j = 0; j <point_voiture ; j++){
            param_mean[6+2*j]/=car_number;
            param_mean[7+2*j]/=car_number;
        }


        // calcul des variances et covariances non normalisée, ( l'effet de la normalisation se compense lors du calcul des parametres de corrélation )
        for(int i = 0; i <car_number ; i++){
            param_var[0]+=  (listcar[i]->r1-param_mean[0])*(listcar[i]->r1-param_mean[0]);
            param_var[1]+=  (listcar[i]->r2-param_mean[1])*(listcar[i]->r2-param_mean[1]);
            param_var[2]+=  (listcar[i]->D-param_mean[2])*(listcar[i]->D-param_mean[2]);
            param_var[3]+=  (listcar[i]->d1-param_mean[3])*(listcar[i]->d1-param_mean[3]);
            param_var[4]+=  (listcar[i]->d2-param_mean[4])*(listcar[i]->d2-param_mean[4]);
            param_var[5]+=  (listcar[i]->d-param_mean[5])*(listcar[i]->d-param_mean[5]);
            param_cov[0]+=  (listcar[i]->r1-param_mean[0])*((scores[i]-scores_mean);
            param_cov[1]+=  (listcar[i]->r2-param_mean[1])*(scores[i]-scores_mean);
            param_cov[2]+=  (listcar[i]->D-param_mean[2])*(scores[i]-scores_mean);
            param_cov[3]+=  (listcar[i]->d1-param_mean[3])*(scores[i]-scores_mean);
            param_cov[4]+=  (listcar[i]->d2-param_mean[4])*(scores[i]-scores_mean);
            param_cov[5]+=  (listcar[i]->d-param_mean[5])*(scores[i]-scores_mean);
            for(int j = 0; j <point_voiture ; j++){
                param_var[6+2*j]+=( (listcar[i]->angles)[j].first -  param_mean[6+2*j] )*( (listcar[i]->angles)[j].first -  param_mean[6+2*j] );
                param_var[7+2*j]+=( (listcar[i]->distances)[j].second -  param_mean[7+2*j] )*( (listcar[i]->distances)[j].second -  param_mean[7+2*j] );
                param_cov[6+2*j]+=( (listcar[i]->angles)[j].first -  param_mean[6+2*j] )*(scores[i]-scores_mean);
                param_cov[7+2*j]+=( (listcar[i]->distances)[j].second -  param_mean[7+2*j] )*(scores[i]-scores_mean);
            }
            scores_var+=(scores[i]-scores_mean)* (scores[i]-scores_mean);

        }

        // calcul des coeff de corrélation
        for(int i = 0; i <parameters_number ; i++){
            corrolations_scores[i]= param_cov[i] /(   sqrt(param_var[i]*scores_var)  ) ;
        }
}


car firstLearner:predict_ranking_car(){
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
        if(param_min[0] > listcar[i]->r1) {
           param_min[0] = listcar[i]->r1;
        }
        if(param_min[1] > listcar[i]->r2) {
           param_min[1] = listcar[i]->r2;
        }
        if(param_min[2] > listcar[i]->D) {
           param_min[2] = listcar[i]->D;
        }
        if(param_min[3] > listcar[i]->d1) {
           param_min[3] = listcar[i]->d1;
        }
        if(param_min[4] > listcar[i]->d2) {
           param_min[4] = listcar[i]->d2;
        }
        if(param_min[5] > listcar[i]->d) {
           param_min[5] = listcar[i]->d;
        }

        if(param_max[0] < listcar[i]->r1) {
           param_max[0] = listcar[i]->r1;
        }
        if(param_max[1] < listcar[i]->r2) {
           param_max[1] = listcar[i]->r2;
        }
        if(param_max[2] < listcar[i]->D) {
           param_max[2] = listcar[i]->D;
        }
        if(param_max[3] < listcar[i]->d1) {
           param_max[3] = listcar[i]->d1;
        }
        if(param_max[4] < listcar[i]->d2) {
           param_max[4] = listcar[i]->d2;
        }
        if(param_max[5] < listcar[i]->d) {
           param_max[5] = listcar[i]->d;
        }


        for(int j = 0; j <point_voiture ; j++){
              // first is angle, second is distance
            if(param_max[6+2*j] < (listcar[i]->angles_distances)[j].first) {
               param_max[6+2*j] = (listcar[i]->angles_distances)[j].first;
            }
            if(param_max[7+2*j] < (listcar[i]->angles_distances)[j].second) {
               param_max[7+2*j] = (listcar[i]->angles_distances)[j].second;
            }
        }
    }
    for(int i = 0; i <parameters_number ; i++){
        new_car[i]= param_max[i] + (corrolations_ranking[i]+1)/2   *(param_min[i]-param_max[i]);
    }
    vector<pair <double,double>> nouvelle_carcasse(point_voiture);

    for(int j = 0; j <point_voiture ; j++){
        nouvelle_carcasse.push_back(pair<double, double> (new_car[6+2*j],new_car[7+2*j]));

    }




    Car new_car(new_car[0],new_car[3],new_car[1],new_car[4],new_car[2],new_car[5],nouvelle_carcasse);
    return new_car;

}
