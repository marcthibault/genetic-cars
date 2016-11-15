#include <QCoreApplication>
#include "car.h"
#include "preprocessing.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<double> angles;
    std::vector<Car> ranking;
    angles.push_back(3);
    angles.push_back(7);
    std::vector<double> distances;
    distances.push_back(3);
    distances.push_back(7.4);
    Car my_car = Car(2.3, 2, 4, 3, 3.5, 4, angles, distances);
    Car my_car2 = Car(4, 1, 1, 1, 1, 1, angles, distances);
    ranking.push_back(my_car);
    ranking.push_back(my_car2);
    preprocessing preprocessor = preprocessing();
    //my_car.densiteRoue1 = 2.3;



    return a.exec();
    //return 0;
}
