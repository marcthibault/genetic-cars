#include <Box2D/Box2D.h>
#include <QApplication>
#include <QCoreApplication>
#include "car.h"
#include "preprocessing.h"
#include <iostream>
#include "windows.h"
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPolygonF>
#include <QPointF>
#include <utility>
#include "Moteur.h"

using namespace std;

int main(int argc, char** argv)
{
    /*
  //TEST CAR TEAM
   // QCoreApplication a(argc, argv);

    Car* Jeep= new Car();
    double theta= Jeep->get_angle_wheel();
    std::cout<<theta<<std::endl;
    //Jeep->get_points_xy();

  //TEST UI TEAM
*/
    QApplication app(argc, argv);
    windows fenetre(100);
    fenetre.show();





    app.exec();
/*
  //TEST PHY TEAM

    //return a.exec();
    b2Vec2 gravity(0.0f, -10.0f);
    b2World *m_world = new b2World(gravity);

    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -20.0f);
    b2Body* groundBody = m_world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(500.0f, 17.0f);

    b2FixtureDef fdGround;
    fdGround.shape = &groundBox;
    fdGround.density = 0.0f;
    fdGround.friction = 0.9f;
    groundBody->CreateFixture(&fdGround);//shape, density
*/
/*
    b2BodyDef bd;
    bd.type = b2_dynamicBody;
    bd.position.Set(0.0f, 4.0f);

    b2Body* car = m_world->CreateBody(&bd);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(4.0f, 2.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    car->CreateFixture(&fixtureDef);


    b2CircleShape circle;
    circle.m_radius = 1.0f;
    b2FixtureDef fd;
    fd.shape = &circle;
    fd.density = 1.0f;
    fd.friction = 0.9f;

    b2Body* wheel1;
    b2Body* wheel2;

    bd.position.Set(-10.0f, 0.0f);
    wheel1 = m_world->CreateBody(&bd);
    wheel1->CreateFixture(&fd);

    wheel2 = m_world->CreateBody(&bd);
    wheel2->CreateFixture(&fd);


    // Liaison avant
    b2WheelJointDef joint;
    b2Vec2 axe(0.0f, 1.0f);
    joint.bodyA = car;
    joint.bodyB = wheel1;
    joint.localAnchorA.Set(2.0f, -1.0f);
    joint.localAnchorB.Set(0.0f, 0.0f);
    joint.motorSpeed = 0.5f;
    joint.maxMotorTorque = 20.0f;
    joint.enableMotor = true;
    joint.frequencyHz = 4.0f;
    joint.dampingRatio = 0.5f;
    joint.Initialize(car, wheel1, wheel1->GetPosition(), axe);

    b2WheelJoint* liaisonAvant;
    liaisonAvant = (b2WheelJoint*)m_world->CreateJoint(&joint);

    // Liaison arrière
    joint.bodyA = car;
    joint.bodyB = wheel2;
    joint.localAnchorA.Set(-2.0f, -1.0f);
    joint.localAnchorB.Set(0.0f, 0.0f);
    joint.motorSpeed = 0.5f;
    joint.maxMotorTorque = 20.0f;
    joint.enableMotor = false;
    joint.frequencyHz = 4.0f;
    joint.dampingRatio = 0.5f;
    joint.Initialize(car, wheel2, wheel2->GetPosition(), axe);

    Moteur* m = new Moteur(10.0);


    while (!m->toutesCarBloquees(5.0))
    {
        m->next(1.0/20.0);
        m->printPositions();
    //std::vector< std::array<float,4> > bidule = m->getPosition() ; //test de la fonction getPosition
    }

    // QVector<QPointF> vect;
    // vect.append(QPointF(10.0,10.0));
    // vect.append(QPointF(10.0,100.0));
    // vect.append(QPointF(200.0,150.0));
    // vect.append(QPointF(300.0,100.0));
    // vect.append(QPointF(200.0,50.0));
    // vect.append(QPointF(150.0,10.0));
    //
    // fenetre.displayFloor(vect);

    app.exec();

    std::cout << "Starting..." << std::endl;


    // TEST GEN TEAM

    // Tester la génération de nouvelles voitures à partir d'un ranking
    std::vector<double> angles;
    std::vector<Car> ranking;
    angles.push_back(3);
    angles.push_back(7);
    std::vector<double> distances;
    distances.push_back(3);
    distances.push_back(7.4);

    Car my_car1 = Car();
    Car my_car2 = Car();
    Car my_car3 = Car();

    std::vector<Car> cars;
    cars.push_back(my_car1);
    cars.push_back(my_car2);
    cars.push_back(my_car3);

    preprocessing preprocessor = preprocessing();

    std::cout << "Impression de trois voitures générées à partir d'un ranking" << std::endl;

    preprocessor.printVector(preprocessor.openCar(my_car1));
    preprocessor.printVector(preprocessor.openCar(my_car2));
    preprocessor.printVector(preprocessor.openCar(my_car3));

// Tester la génération d'une voiture aléatoire
    std::vector<double> means;
    std::vector<double> variances;
    means.push_back(1.6);
    means.push_back(2.6);
    means.push_back(3.6);
    means.push_back(4.6);
    means.push_back(22.6);
    means.push_back(22.6);
    means.push_back(22.6);
    means.push_back(22.6);
    means.push_back(22.6);
    means.push_back(22.6);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);
    variances.push_back(0.1);

    std::cout << "Impression d'une voiture générée aléatoirement" << std::endl;
    Car car = preprocessor.generateRandomCar(means, variances);
    car.printCar();

    std::cout << "Fin de l'affichage" << std::endl;
    // return a.exec();
    */
    return 0;

}

std::vector<Car> preprocessing::geneticMutation(std::vector< std::pair<Car,double> > cars){
    std::vector<Car> ans;
    return ans;
}
