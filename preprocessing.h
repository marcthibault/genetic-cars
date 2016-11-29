#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "car.h"
#include <utility> //std::pair
#include <math.h>
#include <vector>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "strategy.h"

class preprocessing
{
public:
    preprocessing();
    std::default_random_engine generator;
    std::vector<double> openCar(Car* my_car);
    std::vector<Car> matrixToCars(std::vector<std::vector<double>>* matrix);
    Car returnCar(std::vector<double>* attributes);
    std::vector<double> add(std::vector<double> a, std::vector<double> b);
    std::vector<double> multiply(std::vector<double> lambda, std::vector<double> car);
    Car generateRandomCar(std::vector<double> means, std::vector<double> variances);
    void printVector(std::vector<double> vec);
    void generate(strategy strat, std::vector<vector<double>> *cars,std::vector<vector<double>> *newCars,int nbCars);
    std::vector<std::vector<double>> carsToMatrix(std::vector<std::pair<Car,double>>* output);
    void printVector(std::vector<double> * vec);
    std::vector<Car> initialise(int N, std::vector<double> means, std::vector<double> variances);


};

#endif // PREPROCESSING_H
