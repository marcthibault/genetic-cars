#ifndef CAR_H
#define CAR_H
#include <vector>
#include<utility>
#include<car.h>
using namespace std;

/* Load the a  vector of " cars "
 * load a vector of their performance ( or ranking )
 * Corrolation : Pearson product-moment correlation coefficient
 *  pour le score  coeff_correlation =1 => on prend la valeur max du parametre, -1 valeurs min, autres => min + (coeff+1)/2   *(max-min)
 * Pour le ranking ranking petit => meilleur voiture, => coeff_correlation =1 => on prend la valeur min du parametre, 1 valeurs max  autres => max + (coeff+1)/2   *(min-max)
 * pour la carcasse : Pour le moment , le nombre de point est choisi constant 8 poins : R1,R2 et 6 autres,
 *                                      toutes les voitures recus ont le même nmb de point
 *                                     Centre C(0,r1) , pas inclus dans la carcasse
 *                                     R1(D/2,0)  , D is noted L also
 *                                     R2(-D/2,0)
 *                                     car.angles et car.distances donne distance entre point et C, et les angles (C,axeX,point)
 *                                     Conditions : angles distincts
 * Create "best"  predicted car
 */



class firstLearner
{
public :
    vector<car> listcar;
    vector<int> ranking;
    vector<double> scores;
    int car_number; // number of cars that we will use for the prediction, should be the length of listcar,ranking and scores
    int parameters_number ; // number of car parameters used for corrolation = 6  +   2* (nombre de points ( sans compter R1 et R2))
    int point_voiture; // nombre de points différent (sans compter R1 et R2))
    vector<double> corrolations_ranking; // corrolations with ranking
    vector<double> corrolations_scores ;// corrolations with score

    //constructir
    firstLearner(int car_number,int point_voiture,vector<car> listcar,vector<int> ranking,vector<double> scores);

    void compute_corrolations_ranking();
    void compute_corrolations_scores();
    car predict_ranking_car();
    car predict_score_car();





};


