#include "preprocessing.h"
#include "car.h"
#include <math.h>
#include <vector>
#include <random>
#include <iostream>

preprocessing::preprocessing()
{

}

// Transform an object Car in array

std::vector<double> preprocessing::openCar(Car my_car){
    std::vector<double> data;
    data.push_back(my_car.rayon1);
    data.push_back(my_car.rayon2);
    data.push_back(my_car.L);
    data.push_back(my_car.densiteRoue1);
    data.push_back(my_car.densiteRoue2);
    data.push_back(my_car.densiteVoiture);
    for(int i=0;i<my_car.angles.size();i++){
       data.push_back(my_car.angles[i]);
    }
    for(int i=0;i<my_car.distances.size();i++){
       data.push_back(my_car.distances[i]);
    }

    return data;
}
Car preprocessing::returnCar(std::vector<double> attributes){
    Car my_car = Car();
    my_car.rayon1 = attributes[0];
    my_car.rayon1 = attributes[1];
    my_car.L = attributes[2];
    my_car.densiteRoue1 = attributes[3];
    my_car.densiteRoue2 = attributes[4];
    my_car.densiteVoiture = attributes[5];
    int len = (attributes.size() - 6)/2;
    for(int i = 0; i < len; i++){
        my_car.angles.push_back(attributes[6+i]);
        my_car.distances.push_back(attributes[6+len+i]);
    }
    return my_car;
}

// Compute the coeff associated to the ranking of the car
//- Version simpliste
double preprocessing::computeCoeff(int rank, int total){
    if(rank < total){
       return 1./pow(2, rank);
    } else {
       return 1./pow(2, (total-1));
    }
}
// Function that takes the ranking of the race and generates the coefficients
std::vector<double> preprocessing::generateCoeff(int N){
    std::vector<double> coeffs;
    for (int i=0;i<N;i++){
       coeffs.push_back(computeCoeff(i, N));
    }
    return coeffs;
}
// Compute the random evolution of the new cars
//- We can imagine a model where the variability decreases (like temperature)
void preprocessing::computeRandomVector(Car my_car,double V){
    std::vector<double> attributes = openCar(my_car);
    std::default_random_engine generator;
    for(int i=0;i<attributes.size();i++){
        //std::normal_distribution<double> distribution(5.0,2.0);
        double variance = attributes[i]/10;
        std::normal_distribution<double> distribution(0,variance);
        double variation = distribution(generator);
        attributes[i] += variation;
    }
}

// Sum of two cars
std::vector<double> preprocessing::add(std::vector<double> a, std::vector<double> b){
    std::vector<double> c;
    for (int i=0;i<a.size();i++){
        c[i] = a[i] + b[i];
    }
    return c;
}

//Multiply car with a scalar
std::vector<double> preprocessing::multiply(std::vector<double> car, double x){
    std::vector<double> c;
    for (int i=0;i<car.size();i++){
        c[i] = x * car[i];
    }
    return c;
}

// Compute a new car with the ranking of the race
/*Car preprocessing::generateCar(std::vector<Car> ranking){
    coeffs = generateCoeff(ranking.size);
    std::vector<double> preCar = new std::vector<double>();
    for(int i=0;i<car.size;i++) {
        preCar = add( preCar , multiply(open(car[i]),coeffs[i]) )
    }
    Car car = preprocessing::returnCar(preCar);
    return car;
}*/

// Compute a random car
Car preprocessing::generateRandomCar(std::vector<double> * means, std::vector<double> * variances){
    std::vector<double> attributes;
    std::default_random_engine generator;
    for(int i = 0;i < 6; i++){
        std::normal_distribution<double> distribution((*means)[i], (*variances)[i]);
        double value = distribution(generator);
        attributes[i] = value;
    }
    int len = ((*means).size() - 6) / 2;
    for(int i = 0; i < len; i++){
        std::normal_distribution<double> distribution_means((*means)[6 + i], (*variances)[6 + i]);
        double value_mean = distribution_means(generator);
        attributes[6 + i] = value_mean;

        std::normal_distribution<double> distribution_variances((*means)[6 + len + i], (*variances)[6 + len + i]);
        double value_variance = distribution_variances(generator);
        attributes[6 + len + i] = value_variance;
    }
    return returnCar(attributes);
}

void preprocessing::printCar(Car my_car){
    std::vector<double> car = openCar(my_car);
    printCar(car);
}
void preprocessing::printCar(std::vector<double> car){
    for (std::vector<double>::const_iterator i = car.begin(); i != car.end(); ++i)
        std::cout << *i << ' ';
    std::cout << " " << std::endl;
}


