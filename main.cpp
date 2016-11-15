#include <QApplication>
#include "car.h"
#include <iostream>
#include "windows.h"
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPolygonF>
#include <QPointF>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);



    windows fenetre(500);
    fenetre.show();
    return app.exec();
}
//test
