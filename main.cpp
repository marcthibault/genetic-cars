#include <QCoreApplication>
#include "car.h"
#include <iostream>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Hello World" << std::endl;
    std::cout << "My very first commit" << std::endl;


    return a.exec();
}
