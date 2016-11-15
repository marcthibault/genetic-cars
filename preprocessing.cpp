
#include "preprocessing.h"
#include "car.h"
#include <math.h>
#include <vector>
#include <random>
#include <iostream>

preprocessing::preprocessing(){

}

std::vector<Car> preprocessing::matrixToCars(std::vector<std::vector<double>> matrix){
    std::vector<Car> cars;
    for(int i=0;i<matrix.size();i++){
        cars.push_back(returnCar(matrix[i]));
    }
    return cars;
}

// Transform an object Car in vector
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

// Convert vector in car
Car preprocessing::returnCar(std::vector<double> attributes){
    Car my_car = Car();
    my_car.rayon1 = attributes[0];
    my_car.rayon2 = attributes[1];
    my_car.L = attributes[2];
    my_car.densiteRoue1 = attributes[3];
    my_car.densiteRoue2 = attributes[4];
    my_car.densiteVoiture = attributes[5];
    int len = (attributes.size() - 6)/2;
    for(int i = 0; i < len; i++){
        my_car.angles.push_back(attributes[6+i]);
        my_car.distances.push_back(attributes[6+len+i]);
    }
}

// Compute the coeff associated to the ranking of the car
double preprocessing::computeCoeff(int rank, int total){
    rank++; // nb 0 is 1st
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
std::vector<double> preprocessing::generateRandomVector(std::vector<std::vector<double>> cars){
    std::vector<double> means;
    std::vector<double> variances;
    std::vector<double> noise;
    std::default_random_engine generator;
    // pour chaque paramètre i (sauf la distance parcourue)
    for(int i=0;i<(cars[0].size()-1);i++){
        // calcul de la moyenne
       double m = 0;
        // pour chaque voiture j
       for(int j=0;j<cars.size();j++){
           m += cars[j][i];
       }
       m /= cars.size();
       double var = 0;
       for(int j=0;j<cars.size();j++){
           var += (cars[j][i] - m)*(cars[j][i] - m);
       }
       var /= cars.size();
       variances.push_back(var);
    }
    // pour chaque param i
    for(int i=0;i<(cars[0].size()-1);i++){
        std::normal_distribution<double> distribution(0,variances[i]);
        double param = distribution(generator);
        noise.push_back(param);
    }
    return noise;
}

// Sum of two cars
std::vector<double> preprocessing::add(std::vector<double> a, std::vector<double> b){
    std::vector<double> c(a.size(), 0.0);
    for (int i=0;i<a.size();i++){
        c.push_back(a[i] + b[i]);
    }
    return c;
}

//Multiply car with a scalar
std::vector<double> preprocessing::multiply(std::vector<double> lambda, std::vector<double> car){
    std::vector<double> c(car.size(), 0.0);
    for (int i=0;i<car.size();i++){
        c.push_back( lambda[i] * car[i]);
    }
    return c;
}

// Generate the random coefficients for one car
std::vector<vector<double>> preprocessing::generateCoeffs(std::vector<vector<double> > &cars){
    /*std::vector<vector<double>> ans;
    for (int i=0;i<cars.size();i++){
        std::vector<double> line;
        for (int j=0;j<cars[0].size();j++){
            line.push_back(1.0);
        }
        ans.push_back(line);
    }
    return ans;*/
    return cars;
}

// Generate all the new cars
std::vector<vector<double>> preprocessing::generate(std::vector<vector<double>>& cars){
    std::cout << "starting generate" << std::endl;
    std::vector<vector<double>> newCars;
    for (int i=0;i<cars.size();i++){
        std::cout << "hello " << i << std::endl;
        newCars.push_back(vector<double>(cars[0].size()));
        std::cout << "push back " << i << std::endl;
        vector<vector<double>> coeffs = preprocessing::generateCoeffs(cars);
        std::cout << "generaterd coeff " << std::endl;
        for (int j=0;j<cars.size();j++){
            newCars[i] = preprocessing::add( newCars[i] , preprocessing::multiply( cars[j],coeffs[j] ) );
        }
    }
    return newCars;
}

// Compute a random car
Car preprocessing::generateRandomCar(std::vector<double> means, std::vector<double> variances){
    std::vector<double> attributes;
    std::default_random_engine generator;
    for(int i = 0;i < 6; i++){
        std::normal_distribution<double> distribution(means[i], variances[i]);
        double value = distribution(generator);
        attributes.push_back(value);
    }
    int len = (means.size() - 6) / 2;
    for(int i = 0; i < len; i++){
        std::normal_distribution<double> distribution_means(means[6 + i], variances[6 + i]);
        double value_mean = distribution_means(generator);
        attributes.push_back(value_mean);
    }
    for(int i = 0; i < len; i++){
        std::normal_distribution<double> distribution_variances(means[6 + len + i], variances[6 + len + i]);
        double value_variance = distribution_variances(generator);
        attributes.push_back(value_variance);
    }
    return returnCar(attributes);
}

// Pour la debug : print vector
void preprocessing::printVector(std::vector<double> vec){
    for (std::vector<double>::const_iterator i = vec.begin(); i != vec.end(); ++i)
        std::cout << *i << ' ';
    std::cout << ' ' << std::endl;
}

// Transforme l'output de la course en matrice
std::vector<std::vector<double>> preprocessing::CarsToMatrix(std::vector<std::pair<Car,double>> output){
    std::vector<std::vector<double>> M;
    for(std::vector<std::pair<Car,double>>::iterator it = output.begin(); it != output.end(); ++it){
        std::vector<double> data;
        data = openCar((*it).first);
        data.push_back((*it).second);
        M.push_back(data);
    }
}
