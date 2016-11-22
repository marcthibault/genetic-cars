#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "car.h"
#include <utility> //std::pair
#include <vector>


class preprocessing
{
public:
    preprocessing();
    std::vector<double> openCar(Car* my_car);
    std::vector<Car> matrixToCars(std::vector<std::vector<double>> matrix);
    Car returnCar(std::vector<double> attributes);
    double computeCoeff(int rank, int total);
    std::vector<double> generateRandomVector(std::vector<std::vector<double>> cars);
    std::vector<double> generateCoeff(int N);
    std::vector<double> add(std::vector<double> a, std::vector<double> b);
    std::vector<double> multiply(std::vector<double> lambda, std::vector<double> car);
    Car generateRandomCar(std::vector<double> means, std::vector<double> variances);
    std::vector<vector<double>> generateCoeffsRandom(std::vector<vector<double>> cars);
    void printVector(std::vector<double> vec);
    std::vector<vector<double>> generate(std::vector<vector<double>> cars);
    std::vector<vector<double>> generateCoeffsRandom(std::vector<vector<double>> cars);
    std::vector<vector<double>> generateCoeffs(std::vector<vector<double>> carsAndDistance);
    std::vector<std::vector<double>> CarsToMatrix(std::vector<std::pair<Car,double>> output);
    std::vector<Car> geneticMutation(std::vector<pair<Car,double>> cars);
    std::pair<int,int> selectParents(std::vector<double> & distances);
};

#endif // PREPROCESSING_H
