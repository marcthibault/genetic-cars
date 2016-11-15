#include <QCoreApplication>
#include "car.h"
#include "firstLearner.h"
#include <iostream>
#include <vector>
#include <typeinfo>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //std::cout << "Theo was here" << std::endl;
    //std::cout << "Enfin !!" <<std::endl;
    //std::cout << "Hello World" << std::endl;

    //testing firstLearner

    int point_voiture=6;
    vector<pair <double,double>> nouvelle_carcasse1;
    vector<pair <double,double>> nouvelle_carcasse2;
    vector<pair <double,double>> nouvelle_carcasse3;
    vector<pair <double,double>> nouvelle_carcasse4;
    vector<pair <double,double>> nouvelle_carcasse5;
    vector<pair <double,double>> nouvelle_carcasse6;
    for(int j = 0; j <point_voiture ; j++){
        nouvelle_carcasse1.push_back(pair<double, double> ((1+j)*3.12/point_voiture,j+1));
        nouvelle_carcasse2.push_back(pair<double, double> ((1+j)*3.12/point_voiture,j+2));
        nouvelle_carcasse3.push_back(pair<double, double> ((1+j)*3.12/point_voiture,2*j+1));
        nouvelle_carcasse4.push_back(pair<double, double> ((1+0.5*j)*3.12/point_voiture,2*j+1));
        nouvelle_carcasse5.push_back(pair<double, double> ((1+0.5*j)*3.12/point_voiture,2*j+1));
        nouvelle_carcasse6.push_back(pair<double, double> ((1+0.5*j)*3.12/point_voiture,2*j+1));
    }
    Car car1(2,3,2,4,10,6,nouvelle_carcasse1);
    Car car2(5,2,7,4,20,5,nouvelle_carcasse2);
    Car car3(7,3,3,4,15,8,nouvelle_carcasse3);
    Car car4(2,3,2,4,10,6,nouvelle_carcasse4);
    Car car5(5,2,7,4,20,5,nouvelle_carcasse5);
    Car car6(7,3,3,4,15,8,nouvelle_carcasse6);

    //std::cout << (car1.get_points())[2].first << std::endl;

    vector<Car> Listcar;
    Listcar.push_back(car1);
    Listcar.push_back(car2);
    Listcar.push_back(car3);
    Listcar.push_back(car4);
    Listcar.push_back(car5);
    Listcar.push_back(car6);
    //std::cout << Listcar[1].r1 << std::endl;
    vector<double> scores;
    scores.push_back(100);
    scores.push_back(50);
    scores.push_back(250);
    scores.push_back(120);
    scores.push_back(70);
    scores.push_back(280);
    vector<int> ranking;
    ranking.push_back(4);
    ranking.push_back(6);
    ranking.push_back(2);
    ranking.push_back(3);
    ranking.push_back(5);
    ranking.push_back(1);



    //instruction to execute fiest learner
    //begin

    firstLearner testlearner1 =firstLearner(6,point_voiture,Listcar,ranking,scores);
    testlearner1.make_cars();

    testlearner1.compute_corrolations_scores();

    Car test_result=testlearner1.predict_scores_car();
    //end

    /*
    //testing predict_scores
    std::cout << test_result.r1 << std::endl;
    std::cout << test_result.d1 << std::endl;
    std::cout << test_result.r2 << std::endl;
    std::cout << test_result.d2 << std::endl;
    std::cout << test_result.D << std::endl;
    std::cout << test_result.d << std::endl;
    for (int j=0;j<point_voiture;j++){
        std::cout << (test_result.get_points_without_wheels())[j].first << std::endl;
        std::cout << (test_result.get_points_without_wheels())[j].second << std::endl;
    }
    */
    Car bayes_result=testlearner1.predict_naive_Bayes_car(3);
    /*
    //testing predict-bayes
    std::cout << bayes_result.r1 << std::endl;
    std::cout << bayes_result.d1 << std::endl;
    std::cout << bayes_result.r2 << std::endl;
    std::cout << bayes_result.d2 << std::endl;
    std::cout << bayes_result.D << std::endl;
    std::cout << bayes_result.d << std::endl;
    for (int j=0;j<point_voiture;j++){
        std::cout << (bayes_result.get_points_without_wheels())[j].first << std::endl;
        std::cout << (bayes_result.get_points_without_wheels())[j].second << std::endl;
    }
    */
    return 0;
}
