// #include <QCoreApplication>
#include "car.h"
#include "preprocessing.h"
#include <iostream>
#include <utility>


int main(int argc, char *argv[])
{
//  QCoreApplication a(argc, argv);
    std::cout << "Starting..." << std::endl;

// Tester la génération de nouvelles voitures à partir d'un ranking
    std::vector<double> angles;
    std::vector<Car> ranking;
    angles.push_back(3);
    angles.push_back(7);
    std::vector<double> distances;
    distances.push_back(3);
    distances.push_back(7.4);
    distances.push_back(9.14);

    Car my_car1 = Car(2.3, 2, 4, 3, 3.5, 4, angles, distances);
    Car my_car2 = Car(1.3, 5, 2, 1.3, 3.9, 2, angles, distances);
    Car my_car3 = Car(2.9, 2.5, 3, 3, 1.5, 1, angles, distances);

    std::vector<std::pair<Car,double>> cars;
    cars.push_back(std::pair<Car,double>(my_car1,110));
    cars.push_back(std::pair<Car,double>(my_car2,80));
    cars.push_back(std::pair<Car,double>(my_car3,40));

    preprocessing preprocessor = preprocessing();

    std::vector<std::pair<Car,double>> output;
    output.push_back(make_pair(my_car1,1.0));
    output.push_back(make_pair(my_car2,2.0));
    output.push_back(make_pair(my_car3,3.0));

    // std::vector<std::vector<double>> Matrix;


    Matrix = preprocessor.CarsToMatrix(output);

    pair<int,int> parents = preprocessor.selectParents(distances);
    std::cout << "Papa = " << parents.first << std::endl;
    std::cout << "Maman = " << parents.second << std::endl;

    Matrix = preprocessor.CarsToMatrix(output);

    std::cout << "Impression de trois voitures générées à partir d'un ranking" << std::endl;

    std::vector<vector<double>> cars_matrix = preprocessor.CarsToMatrix(cars);
    std::cout << "cars_matrix ok" << std::endl;

    //std::vector<vector<double>> new_cars_matrix = preprocessor.generate(cars_matrix);
    std::cout << "new_cars_matrix ok" << std::endl;
    /*
    //std::vector<Car> new_cars =  preprocessor.matrixToCars(new_cars_matrix);
    std::cout << "new_cars ok" << std::endl;*/

    //for(int i=0;i<new_cars.size();i++){
        //preprocessor.printVector(preprocessor.openCar(new_cars[i]));
    //}
    /*
    preprocessor.printVector(preprocessor.openCar(my_car1));
    preprocessor.printVector(preprocessor.openCar(my_car2));
    preprocessor.printVector(preprocessor.openCar(my_car3));
    */

// Tester la génération d'une voiture aléatoire
    std::vector<double> means;
    std::vector<double> variances;
    means.push_back(1.6);
    means.push_back(2.6);
    means.push_back(3.6);
    means.push_back(4.6);
    means.push_back(22.6);
    means.push_back(22.6);
    means.push_back(22.6);
    means.push_back(22.6);
    means.push_back(22.6);
    means.push_back(22.6);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);

    std::cout << "Impression d'une voiture générée aléatoirement" << std::endl;
    Car car = preprocessor.generateRandomCar(means, variances);

    std::cout<< "Affichage des coefficients" << std::endl;

    //vector<vector<double>> matrix2 = preprocessor.CarsToMatrix(pairs);

    // création d'une matrice de test
    vector<vector<double>> matrix;
    vector<double> car1;
    car1.push_back(10);
    car1.push_back(20);
    car1.push_back(20);
    vector<double> car2;
    car2.push_back(15);
    car2.push_back(25);
    car2.push_back(25);
    vector<double> car3;
    car3.push_back(5);
    car3.push_back(30);
    car3.push_back(30);
    matrix.push_back(car1);
    matrix.push_back(car2);
    matrix.push_back(car3);

    //test de generateCoeffs
    vector<vector<double>> coeffs = preprocessor.generateCoeffsRandom(matrix);
    preprocessor.printVector(matrix[0]);
    preprocessor.printVector(coeffs[0]);

    //test de generate
    std::vector<vector<double>> newCars = preprocessor.generate(matrix);
    preprocessor.printVector(newCars[0]);
    std::cout << newCars.size() << std::endl;

    std::cout << "Fin de l'affichage" << std::endl;
    // return a.exec();
    return 0;

}

std::vector<Car> preprocessing::geneticMutation(std::vector< std::pair<Car,double>> cars){
    std::vector<Car> ans;
    return ans;
}
