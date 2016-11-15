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
}

void windows::run()
{


    timer->start(0);

}

void windows::afficher()
{
    if(a){
        setFixedSize(1000, 600);
        a=false;
    }
    else{
        setFixedSize(1000, 500);
        a=true;
    }
    timer->start(step);
}
