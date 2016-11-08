#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "car.h"
#include <vector>


class preprocessing
{
public:
    preprocessing();
    std::vector<double> openCar(Car my_car);
    Car returnCar(std::vector<double> attributes);
    double computeCoeff(int rank, int total);
    void computeRandomVector(Car my_car, double V);
    std::vector<double> generateCoeff(int N);
    std::vector<double> add(std::vector<double> a, std::vector<double> b);
    std::vector<double> multiply(std::vector<double> car, double x);
    Car generateCar(std::vector<Car> ranking);
    void printCar(Car car);
    void printCar(std::vector<double> car);
    Car generateRandomCar(std::vector<double> * means, std::vector<double> * variances);
};

#endif // PREPROCESSING_H
