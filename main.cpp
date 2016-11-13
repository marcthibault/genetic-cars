#include <QCoreApplication>
#include "car.h"
#include <iostream>
#include "windows.h"
#include <QWidget>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << "Theo was here" << std::endl;

    std::cout << "Enfin !!" <<std::endl;
    std::cout << "Hello World" << std::endl;


    windows fenetre;
    fenetre.show();

    return a.exec();
}
//test
