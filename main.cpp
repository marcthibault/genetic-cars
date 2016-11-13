#include <QApplication>
#include "car.h"
#include <iostream>
#include "windows.h"
#include <QWidget>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    windows fenetre;
    fenetre.show();

    return app.exec();
}
//test
