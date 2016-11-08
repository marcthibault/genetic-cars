#include "preprocessing.h"
#include "car.h"
#include <math.h>
#include <vector>

preprocessing::preprocessing()
{

}

// Transform an object Car in array
std::vector<double> preprocessing::open(Car my_car){
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
    vector<double> coeffs;
    for (int i=0;i<N;i++){
       coeffs.push_back(preprocessing::computeCoeff(i));
    }
    return coeffs;
}
// Compute the random evolution of the new cars
void preprocessing::computeRandomVector(Car my_car){
    std::vector<double> attributes = open(my_car);
    for(int i=0;i<attributes.size();i++){
        attributes[i];
    }

// Sum of two cars
std::vector<double> preprocessing::add(std::vector<double> a, std::vector<double> b){
    c= std::vector<double>;
    for (int i=0;i<a.size;i++){
        c[i] = a[i] + b[i];
    }
    return c;
}

//Multiply car with a scalar
std::vector<double> preprocessing::multiply(std::vector<double> car, double x){
    c= std::vector<double>;
    for (int i=0;i<car.size;i++){
        c[i] = x * car[i];
    }
    return c;
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


