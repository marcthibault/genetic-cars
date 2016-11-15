#include <QCoreApplication>
#include "car.h"
#include <iostream>



int main(int argc, char *argv[])
{
   // QCoreApplication a(argc, argv);

    Car* Jeep= new Car();
    double theta= Jeep->get_angle_wheel();
    std::cout<<theta<<std::endl;
    //Jeep->get_points_xy();


    std::cout << "Enfin !!" <<std::endl;
    std::cout << "Hello World" << std::endl;

    return 0;
    //return a.exec();
}
