#include <QCoreApplication>
#include "car.h"
#include <iostream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Theo was here" << std::endl;
    std::cout << "Enfin !!" <<std::endl;
    std::cout << "Hello World" << std::endl;
    std::vector<double> angles =  std::vector<double>();
    angles.push_back(1.0);
    angles.push_back(2.0);

    std::vector<double> distances =  std::vector<double>();
    distances.push_back(1.0);
    distances.push_back(2.0);

    Car * my_car = new Car::Car(1.0,
                         2.0,
                         5.0,
                         1.0,
                         1.0,
                         1.0,
                         angles,
                         distances);

    std::cout << my_car->rayon1 << std::endl;
    return 0;
}
