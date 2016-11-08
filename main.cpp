#include <QCoreApplication>
#include "car.h"
#include "preprocessing.h"
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
    //std::cout << my_car.densiteRoue1 << std::endl;
    Car my_car1 = Car(2.3, 2, 4, 3, 3.5, 4, angles, distances);
    Car my_car2 = Car(1.3, 5, 2, 1.3, 3.9, 2, angles, distances);
    Car my_car3 = Car(2.9, 2.5, 3, 3, 1.5, 1, angles, distances);
    std::vector<Car> cars;
    cars.push_back(my_car1);
    cars.push_back(my_car2);
    cars.push_back(my_car3);
    preprocessing preprocessor = preprocessing();
    std::vector<double> car =  preprocessor.openCar(my_car1);
    preprocessor.printCar(car);


     std::cout << "Fin de l'affichage" << std::endl;
    return a.exec();
    //return 0;
}
