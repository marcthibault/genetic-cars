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

    QGraphicsScene* m_scene = new QGraphicsScene(&fenetre);
    m_scene->setSceneRect(0,0,400,400);
    QGraphicsView* m_view = new QGraphicsView(m_scene,&fenetre);
             //m_view->setGeometry(0,0,500,500);
    m_view->show();

    QVector<QPointF> vect;
      vect.append(QPointF(10.0,10.0));
      vect.append(QPointF(10.0,50.0));
      vect.append(QPointF(50.0,30.0));
      vect.append(QPointF(40.0,50.0));
      vect.append(QPointF(20.0,10.0));
      m_scene->addPolygon(QPolygonF(vect));


    fenetre.show();
    return app.exec();
}
//test
