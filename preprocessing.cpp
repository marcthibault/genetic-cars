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
// Compute the coeff associated to the ranking of the car
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

// Sum of two cars
std::vector<double> preprocessing::add(std::vector<double> a, std::vector<double> b){
    return std::transform (a.begin(), a.end(), b.begin(), a.begin(), std::plus<int>());
    }

//Multiply car with a scalar
std::vector<double> preprocessing::multiply(std::vector<double> car, double x){
    return std::transform(car.begin(), car.end(), car.begin(), std::bind1st(std::multiplies<T>(),x));
}

// Compute a new car with the ranking of the race
Car preprocessing::generateCar(std::vector<Car> ranking){
    coeffs = generateCoeff(ranking.size);
    std::vector<double> preCar = new std::vector<double>();
    for(int i=0;i<car.size;i++) {
        preCar = add( preCar , multiply(open(car[i]),coeffs[i]) )
        /* std::cout << *it; ... */
    }
    Car car = close(preCar);
    return car;
}
}


