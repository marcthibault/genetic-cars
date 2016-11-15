#include "windows.h"

windows::windows() : QWidget()
{
    setFixedSize(100, 50);

    m_bouton = new QPushButton("Run !", this);
    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->move(0, 0);

    step=default_step;


    timer = new QTimer(this);

    this->a=true;

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(afficher()));

    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(run()));

    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(0,0,500,300);
    m_view = new QGraphicsView(m_scene,this);
    m_view->move(100,100);
    m_view->show();
}

windows::windows(int dt) : QWidget()
{
    setFixedSize(1000, 500);

    m_bouton = new QPushButton("Run !", this);
    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_bouton->move(0, 0);

    step=dt;


    timer = new QTimer(this);

    this->a=true;

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(afficher()));

    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(run()));

    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(0,0,500,300);
    m_view = new QGraphicsView(m_scene,this);
    m_view->move(100,100);
    m_view->show();

}

void windows::run()
{


    timer->start(0);

}

void windows::afficher()
{
    /*QGraphicsScene* m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(0,0,100,100);
    QGraphicsView* m_view = new QGraphicsView(m_scene,this);
    m_view->move(100,100);
    m_view->show();*/
    m_scene->clear();
    if(a){


        QVector<QPointF> vect;
          vect.append(QPointF(10.0,10.0));
          vect.append(QPointF(10.0,100.0));
          vect.append(QPointF(200.0,150.0));
          vect.append(QPointF(300.0,100.0));
          vect.append(QPointF(200.0,50.0));
          vect.append(QPointF(150.0,10.0));
          m_scene->addPolygon(QPolygonF(vect));
        a=false;
    }
    else{

        QVector<QPointF> vect;
          vect.append(QPointF(10.0,10.0));
          vect.append(QPointF(40.0,50.0));
          vect.append(QPointF(20.0,10.0));
          m_scene->addPolygon(QPolygonF(vect));
        a=true;
    }
    timer->start(step);
}
