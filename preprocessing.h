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
    void computeRandomVector(Car my_car);
    std::vector<double> generateCoeff(int N);
    std::vector<double> add(std::vector<double> a, std::vector<double> b);
    std::vector<double> multiply(std::vector<double> car, double x);
    Car generateCar(std::vector<Car> ranking);
    Car generateRandomCar();
};

#endif // PREPROCESSING_H
