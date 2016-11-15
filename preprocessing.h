#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "car.h"
#include <utility> //std::pair
#include <vector>


class preprocessing
{
public:
    preprocessing();
    std::vector<double> openCar(Car my_car);
    std::vector<Car> matrixToCars(std::vector<std::vector<double>> matrix);
    Car returnCar(std::vector<double> attributes);
    double computeCoeff(int rank, int total);
    void generateRandomVector(Car my_car, double V);
    std::vector<double> generateRandomVector(std::vector<std::vector<double>> cars);
    std::vector<double> generateCoeff(int N);
    std::vector<double> add(std::vector<double> a, std::vector<double> b);
    std::vector<double> multiply(std::vector<double> lambda, std::vector<double> car);
    Car generateRandomCar(std::vector<double> means, std::vector<double> variances);
    void printVector(std::vector<double> vec);
    std::vector<vector<double>> generate(std::vector<vector<double>> cars);
    std::vector<vector<double>> generateCoeffs(std::vector<vector<double>> cars);
    std::vector<std::vector<double>> CarsToMatrix(std::vector<std::pair<Car,double>> output);
};

#endif // PREPROCESSING_H
