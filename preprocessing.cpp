
#include "preprocessing.h"
#include "car.h"
#include <math.h>
#include <vector>
#include <random>
#include <stdlib.h>
#include <iostream>
#include <time.h>

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
    data.push_back(my_car.r1);
    data.push_back(my_car.r2);
    data.push_back(my_car.D);
    data.push_back(my_car.d1);
    data.push_back(my_car.d2);
    data.push_back(my_car.d);
    for(int i=0;i<my_car.angles_distances.size();i++){
       data.push_back(my_car.angles_distances[i].first);
    }
    for(int i=0;i<my_car.angles_distances.size();i++){
       data.push_back(my_car.angles_distances[i].second);
    }
    return data;
}

// Convert vector in car
Car preprocessing::returnCar(std::vector<double> attributes){
    Car my_car = Car();
    my_car.r1 = attributes[0];
    my_car.r2 = attributes[1];
    my_car.D = attributes[2];
    my_car.d1 = attributes[3];
    my_car.d2 = attributes[4];
    my_car.D = attributes[5];
    int len = (attributes.size() - 6)/2;
    for(int i = 0; i < len; i++){
        my_car.angles_distances.push_back(make_pair(attributes[6+i], attributes[6+len+i]));
        //my_car.angles.push_back(attributes[6+i]);
        //my_car.distances.push_back(attributes[6+len+i]);
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
std::vector<vector<double>> preprocessing::generateCoeffsRandom(std::vector<vector<double>> cars){
    std::vector<vector<double>> ans;
    for (int i=0;i<cars.size();i++){
        std::vector<double> tmp;
        for (int j =0;j<cars[0].size()-1;j++){
            tmp.push_back(1.0);
        }
        ans.push_back(tmp);
    }
    return ans;
}

// Generate all the new cars
std::vector<vector<double>> preprocessing::generate(std::vector<vector<double>> cars){
    std::vector<vector<double>> newCars;
    for (int i=0;i<cars.size();i++){
        vector<vector<double>> coeffs = preprocessing::generateCoeffsRandom(cars);
        vector<double> tmp(cars[0].size(),0);
        for (int j=0;j<cars.size();j++){
            tmp  = preprocessing::add( tmp , preprocessing::multiply( cars[j],coeffs[j] ) );
        }
        newCars.push_back(tmp);
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
std::vector<std::vector<double>> preprocessing::carsToMatrix(std::vector<std::pair<Car,double>> output){
    std::vector<std::vector<double>> M;
    for(std::vector<std::pair<Car,double>>::iterator it = output.begin(); it != output.end(); ++it){
        std::vector<double> data;
        data = openCar((*it).first);
        data.push_back((*it).second);
        M.push_back(data);
    }
    return M;
}

// Calcule les coefficients pour la combinaison linéaire des voitures
// première stratégie : on choisit deux parents parmis la population proportionnellement à leur performance (=distance parcourue)
//

// Tirage avec remise de deux parents, proportionnellement à la distance parcourue

std::vector<vector<double>> preprocessing::generateCoeffs(std::vector<vector<double>> *carsAndDistance){
    std::vector<vector<double>> coeffs;

    std::vector<double> distances;
    for (int i=0;i<carsAndDistance->size() ; i++){
        distances.push_back(carsAndDistance[i][carsAndDistance[i].size()-1]);
    }

    std::pair<int,int> parents;
    parents = selectParents(distances);

    std::vector<double> coeff1;
    std::vector<double> coeff2;

    for (int i=0 ; i<carsAndDistance[0].size() -1 ; i++){
        //on choisit chaque caractère entre parent 1 et 2 de manière aléatoire
        srand(time(NULL));
        double r = ((double)rand() / (RAND_MAX));
        if (r <= 0.5){
            coeff1.push_back(0);
            coeff2.push_back(1);
        }
        else{
            coeff1.push_back(1);
            coeff2.push_back(0);
        }
    }
    // on met tous les coeffs de toutes les autres voitures à (0,0...)
    std::vector<double> null(carsAndDistance->size()-1, 0.0);
    for (int i=0;i<carsAndDistance->size() ; i++){
        if (i==parents.first){
            coeffs.push_back(coeff1);
        }
        if (i==parents.second){
            coeffs.push_back(coeff2);
        }
        else {
            coeffs.push_back(null);
        }
    }
    return coeffs;
}

pair<int,int> preprocessing::selectParents(std::vector<double> & distances) {
    double distanceTotale = 0.0;
    double distanceCourante = 0.0;
    for(std::vector<double>::iterator it = distances.begin(); it != distances.end(); ++it){
        distanceTotale += *it;
    }
     std::cout << "distanceTotale = " << distanceTotale << endl;
    std::vector<double>::iterator it2 = distances.begin();
    int n1 = -1;
    int n2 = -1;
    int cpt = 0;
    srand(time(NULL));
    double r1 = ((double) rand() / (RAND_MAX));
    std::cout << "r1 = " << r1 << endl;
    double r2 = ((double) rand() / (RAND_MAX));
    std::cout << "r2 = " << r2 << endl;
    while(n1 < 0 || n2 < 0){
        distanceCourante += (*it2 / distanceTotale);
        std::cout << "distanceCourante = " << distanceCourante << endl;
        if(r1 <= distanceCourante && n1 < 0){
            n1 = cpt;
        }
        if(r2 <= distanceCourante && n2 < 0){
            n2 = cpt;
        }
        cpt++;
        it2++;
    }
    if(n1 < n2)
        return make_pair(n1,n2);
    else
        return make_pair(n2,n1);
}
