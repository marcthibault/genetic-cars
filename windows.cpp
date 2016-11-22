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

    avancement=0;
}

windows::windows(int dt) : QWidget()
{
    setFixedSize(1000, 500);


    m_bouton = new QPushButton("Run !", this);
    m_bouton->setFont(QFont("Comic Sans MS", 14));
    m_reset = new QPushButton("Stop", this);

    step=dt;


    timer = new QTimer(this);

    this->a=true;

    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(afficher()));

    QObject::connect(m_bouton, SIGNAL(clicked()), this, SLOT(run()));



    m_scene = new QGraphicsScene(this);
    m_scene->setSceneRect(0,0,500,300);


    m_view = new QGraphicsView(m_scene,this);
    m_view->move(0,0);
    m_view->show();


    this->m_LCD = new QLCDNumber(5, this);

    // Gestion du layout pour le placement des boutons
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(m_bouton,0,1);
    layout->addWidget(m_reset,0,2);
    layout->addWidget(m_LCD,1,0);
    layout->addWidget(m_view,0,0);
    this->setLayout(layout);

    this->m_Timer_value=0;
    this->m_timer = new QTimer(this);
    connect(this->m_timer, SIGNAL(timeout()), this, SLOT(update()));
    this->m_timer->setInterval(100);

    // On connecte les différents signaux et slots
    connect(this->m_bouton, SIGNAL(clicked()), this, SLOT(run()));
    connect(this->m_reset, SIGNAL(clicked()), this, SLOT(reset()));

    avancement=0;

}

void windows::run()
{

    this->m_timer->start();
    timer->start(0);

}

void windows::dessiner(QVector<QPointF> v,QPen pen,QBrush brush){
    m_scene->addPolygon(QPolygonF(v),pen,brush);
}

void windows::afficher()
{
    m_scene->clear();
    if(a){

        /*
        QVector<QPointF> vect;
        vect.append(QPointF(avancement+10.0,10.0));
        vect.append(QPointF(avancement+10.0,100.0));
        vect.append(QPointF(avancement+200.0,150.0));
        vect.append(QPointF(avancement+300.0,100.0));
        vect.append(QPointF(avancement+200.0,50.0));
        vect.append(QPointF(avancement+150.0,10.0));
        dessiner(vect);
        //a=false;
        avancement++;
        QVector<QPointF> vect2;
        vect2.append(QPointF(10.0,160.0));
        vect2.append(QPointF(100.0,150.0));
        vect2.append(QPointF(200.0,160.0));
        vect2.append(QPointF(300.0,170.0));
        vect2.append(QPointF(400.0,150.0));
        vect2.append(QPointF(550.0,110.0));

        this->displayFloor(vect2);
        */
        QVector<QPointF> vect;
        vect.append(QPointF(10.0,10.0));
        vect.append(QPointF(10.0,100.0));
        vect.append(QPointF(200.0,150.0));
        vect.append(QPointF(300.0,100.0));
        vect.append(QPointF(200.0,50.0));
        vect.append(QPointF(150.0,10.0));
        dessiner(vect);


        QVector<QPointF> vect2;
        vect2.append(QPointF(10.0-avancement,160.0));
        vect2.append(QPointF(100.0-avancement,150.0));
        vect2.append(QPointF(200.0-avancement,160.0));
        vect2.append(QPointF(300.0-avancement,170.0));
        vect2.append(QPointF(400.0-avancement,150.0));
        vect2.append(QPointF(550.0-avancement,110.0));

        this->displayFloor(vect2);
        m_scene->setSceneRect(-avancement,0,500,300);

        avancement++;
    }
    else{

        QVector<QPointF> vect;
        vect.append(QPointF(10.0,10.0));
        vect.append(QPointF(10.0,100.0));
        vect.append(QPointF(200.0,150.0));
        vect.append(QPointF(300.0,100.0));
        vect.append(QPointF(200.0,50.0));
        vect.append(QPointF(150.0,10.0));
        dessiner(vect,QPen(Qt::green),QBrush(Qt::yellow));
        a=true;
    }
    timer->start(step);
}

void windows::reset()
{
    this->m_timer->stop();
    m_Timer_value=0;
    m_LCD->display(m_Timer_value);
    timer->stop();
}

void windows::update()
{
    m_Timer_value++;
    m_LCD->display(m_Timer_value);
}

QPointF windows::cartesien(double x, double y, double angle, double longueur, double repere){
    double x0=x+longueur*cos(angle+repere);
    double y0=y+longueur*sin(angle+repere);
    return QPointF(x0,y0);
}

void windows::displayFloor(QVector<QPointF> v){
    QPointF p1=v.first();
    v.pop_front();
    while(!v.isEmpty()){
        QPointF p2=v.first();
        v.pop_front();
        m_scene->addLine(QLineF ( p1, p2));
        p1=p2;
    }

}
