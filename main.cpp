#include <QCoreApplication>
#include <Box2D/Box2D.h>
#include <QApplication>
#include <QCoreApplication>
#include "car.h"
#include "preprocessing.h"
#include <iostream>
#include "windows.h"
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPolygonF>
#include <QPointF>
#include <utility>


int main(int argc, char *argv[])
{


//  QCoreApplication a(argc, argv);
    std::cout << "Starting..." << std::endl;


  // TEST GEN TEAM

// Tester la génération de nouvelles voitures à partir d'un ranking
    /*std::vector<double> angles;
    std::vector<Car> ranking;
    angles.push_back(3);
    angles.push_back(7);
    std::vector<double> distances;
    distances.push_back(3);
    distances.push_back(7.4);
    distances.push_back(9.14);

    Car my_car1 = Car();
    Car my_car2 = Car();
    Car my_car3 = Car();

    std::vector<std::pair<Car,double>> cars;
    cars.push_back(std::pair<Car,double>(my_car1,110));
    cars.push_back(std::pair<Car,double>(my_car2,80));
    cars.push_back(std::pair<Car,double>(my_car3,40));*/


    preprocessing preprocessor = preprocessing();

    std::cout << "Impression de trois voitures générées à partir d'un ranking" << std::endl;

    /*preprocessor.printVector(preprocessor.openCar(&my_car1));
    preprocessor.printVector(preprocessor.openCar(&my_car2));
    preprocessor.printVector(preprocessor.openCar(&my_car3));*/

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

    preprocessor.printVector(preprocessor.openCar(&car));
    std::cout << "Fin de l'affichage" << std::endl;
    // return a.exec();

    return 0;

}

std::vector<Car> preprocessing::geneticMutation(std::vector< std::pair<Car,double>> cars){
    std::vector<Car> ans;
    return ans;
}
//test
