#include <QApplication>
#include "car.h"
#include <iostream>
#include "windows.h"
#include <QWidget>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    windows fenetre;
    fenetre.show();

    /*
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCaption()));
    timer->start(1000);
    */
    return app.exec();
}
//test
