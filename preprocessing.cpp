#include "preprocessing.h"
#include "car.h"
#include <math.h>
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
// Compute the random evolution of the new cars
void preprocessing::computeRandomVector(car my_car){
    std::vector<double> attributes = open(my_car);
    for(int i=0;i<attributes.size();i++){
        attributes[i];
    }
}


