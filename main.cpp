#include <QCoreApplication>
#include "car.h"
#include <iostream>



int main(int argc, char *argv[])
{
   // QCoreApplication a(argc, argv);

    Car* Jeep= new Car();
    std::cout << "Theo was here" << std::endl;

    std::cout << "Enfin !!" <<std::endl;
    std::cout << "Hello World" << std::endl;

    return 0;
    //return a.exec();
}
