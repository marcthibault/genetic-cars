#include "preprocessing.h"
#include "car.h"
<<<<<<< HEAD
#include <math.h>
=======
>>>>>>> 89b2f883818cbe51f0792d038fc7b7953dbafc3e
#include <vector>

preprocessing::preprocessing()
{

}

// Transform an object Car in array
std::vector<double> preprocessing::open(car my_car){
    std::vector<double> data;
    data.push_back(my_car.a);

    return data;
}
// Compute the coeff associated to tha ranking of the car
double preprocessing::computeCoeff(int rank, int total){
    if(rank < total){
       return 1./pow(2, rank);
    } else {
       return 1./pow(2, (total-1));
    }
}
// Function that takes the ranking of the race and generates the coefficients
std::vector<double> preprocessing::generateCoeff(int N){
    vector<double> coeffs = new vector<double>();
    for (i=0;i<N;i++){
       coeffs.push_back(computeCoeffs(i));
    }
    return coeffs;
}
// Compute the random evolution of the new cars
void preprocessing::computeRandomVector(car my_car){
    std::vector<double> attributes = open(my_car);
    for(int i=0;i<attributes.size();i++){
        attributes[i];
    }
}


