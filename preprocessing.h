#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "car.h"
#include <vector>


class preprocessing
{
public:
    preprocessing();
    std::vector<double> open(car my_car);
    double computeCoeff(int rank, int total);
    void computeRandomVector(car my_car);
    std::vector<double> generateCoeff(int N)
};

#endif // PREPROCESSING_H
