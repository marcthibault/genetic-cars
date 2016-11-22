//#include <QCoreApplication>
//#include <Box2D/Box2D.h>
//#include <QApplication>
//#include <QCoreApplication>
#include "car.h"
#include "preprocessing.h"
#include <iostream>
//#include "windows.h"
//#include <QWidget>
//#include <QTimer>
//#include <QGraphicsScene>
//#include <QGraphicsView>
//#include <QPolygonF>
//#include <QPointF>
//#include <utility>

int main(int argc, char *argv[])
{

  // TEST GEN TEAM

    preprocessing preprocessor = preprocessing();
    // Tester la génération d'une voiture aléatoire
    std::vector<double> means = {1.6, 2.6, 3.6, 4.6, 22.6, 22.6, 22.6, 22.6, 22.6, 22.6};
    std::vector<double> variances = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

    std::cout << "Generation de voitures générées aléatoirement" << std::endl;
    Car car = preprocessor.generateRandomCar(means, variances);
    Car car2 = preprocessor.generateRandomCar(means, variances);
    Car car3 = preprocessor.generateRandomCar(means, variances);
    std::cout << "Impression d'un voiture" << std::endl;
    std::vector<double> vec = preprocessor.openCar(&car);
    preprocessor.printVector(&vec);
    std::cout << "Test de CarsToMatrix" << std::endl;
    std::pair<Car,double> p1 (car,1.);
    std::pair<Car,double> p2 (car2,2.);
    std::pair<Car,double> p3 (car3,3.);
    std::vector<std::pair<Car,double>> cars = { p1,p2,p3};
    std::vector<std::vector<double>> vec_tab = preprocessor.carsToMatrix(&cars);
    preprocessor.printVector(&vec_tab[0]);

    std::vector<std::vector<double>> newMatrix;
    preprocessor.generate(&vec_tab,&newMatrix,3);
    preprocessor.printVector(&(newMatrix[0]));

    std::cout << "Fin de l'affichage" << std::endl;
    // return a.exec();

    return 0;

}


//test
