#include <QCoreApplication>
#include "car.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Theo was here" << std::endl;
    std::cout << "Enfin !!" <<std::endl;
    std::cout << "Hello World" << std::endl;

    std::vector<double> angles;
    angles.push_back(3);
    angles.push_back(7);
    std::vector<double> distances;
    distances.push_back(3);
    distances.push_back(7.4);
    Car my_car = Car(2.3, 2, 4, 3, 3.5, 4, angles, distances);
    //my_car.densiteRoue1 = 2.3;
    std::cout << my_car.densiteRoue1 << std::endl;



    return a.exec();
    //return 0;
}
