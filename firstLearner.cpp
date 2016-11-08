#include "firstLearner.h"
#include <vector>
#include <utility>
#include <math.h>
using namespace std;


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
        param_mean[0]+=  listcar[i]->rayon1;
        param_mean[1]+=  listcar[i]->rayon2;
        param_mean[2]+=  listcar[i]->L;
        param_mean[3]+=  listcar[i]->densiteRoue1;
        param_mean[4]+=  listcar[i]->densiteRoue2;
        param_mean[5]+=  listcar[i]->densiteVoiture;
        for(int j = 0; j <point_voiture ; j++){
            param_mean[6+2*j]+=(listcar[i]->angles_distances)[j].first;  // first is distance, second is angle
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
        param_var[0]+=  (listcar[i]->rayon1-param_mean[0])*(listcar[i]->rayon1-param_mean[0]);
        param_var[1]+=  (listcar[i]->rayon2-param_mean[1])*(listcar[i]->rayon2-param_mean[1]);
        param_var[2]+=  (listcar[i]->L-param_mean[2])*(listcar[i]->L-param_mean[2]);
        param_var[3]+=  (listcar[i]->densiteRoue1-param_mean[3])*(listcar[i]->densiteRoue1-param_mean[3]);
        param_var[4]+=  (listcar[i]->densiteRoue2-param_mean[4])*(listcar[i]->densiteRoue2-param_mean[4]);
        param_var[5]+=  (listcar[i]->densiteVoiture-param_mean[5])*(listcar[i]->densiteVoiture-param_mean[5]);
        param_cov[0]+=  (listcar[i]->rayon1-param_mean[0])*(ranking[i]-ranking_mean) ;
        param_cov[1]+=  (listcar[i]->rayon2-param_mean[1])*(ranking[i]-ranking_mean) ;
        param_cov[2]+=  (listcar[i]->L-param_mean[2])*(ranking[i]-ranking_mean);
        param_cov[3]+=  (listcar[i]->densiteRoue1-param_mean[3])*(ranking[i]-ranking_mean);
        param_cov[4]+=  (listcar[i]->densiteRoue2-param_mean[4])*(ranking[i]-ranking_mean);
        param_cov[5]+=  (listcar[i]->densiteVoiture-param_mean[5])*(ranking[i]-ranking_mean);
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
            param_mean[0]+=  listcar[i]->rayon1;
            param_mean[1]+=  listcar[i]->rayon2;
            param_mean[2]+=  listcar[i]->L;
            param_mean[3]+=  listcar[i]->densiteRoue1;
            param_mean[4]+=  listcar[i]->densiteRoue2;
            param_mean[5]+=  listcar[i]->densiteVoiture;
            for(int j = 0; j <point_voiture ; j++){
                param_mean[6+2*j]+=(listcar[i]->angles_distances)[j].first;  // first is distance, second is angle
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
            param_var[0]+=  (listcar[i]->rayon1-param_mean[0])*(listcar[i]->rayon1-param_mean[0]);
            param_var[1]+=  (listcar[i]->rayon2-param_mean[1])*(listcar[i]->rayon2-param_mean[1]);
            param_var[2]+=  (listcar[i]->L-param_mean[2])*(listcar[i]->L-param_mean[2]);
            param_var[3]+=  (listcar[i]->densiteRoue1-param_mean[3])*(listcar[i]->densiteRoue1-param_mean[3]);
            param_var[4]+=  (listcar[i]->densiteRoue2-param_mean[4])*(listcar[i]->densiteRoue2-param_mean[4]);
            param_var[5]+=  (listcar[i]->densiteVoiture-param_mean[5])*(listcar[i]->densiteVoiture-param_mean[5]);
            param_cov[0]+=  (listcar[i]->rayon1-param_mean[0])*((scores[i]-scores_mean);
            param_cov[1]+=  (listcar[i]->rayon2-param_mean[1])*(scores[i]-scores_mean);
            param_cov[2]+=  (listcar[i]->L-param_mean[2])*(scores[i]-scores_mean);
            param_cov[3]+=  (listcar[i]->densiteRoue1-param_mean[3])*(scores[i]-scores_mean);
            param_cov[4]+=  (listcar[i]->densiteRoue2-param_mean[4])*(scores[i]-scores_mean);
            param_cov[5]+=  (listcar[i]->densiteVoiture-param_mean[5])*(scores[i]-scores_mean);
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



