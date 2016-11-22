#include <QCoreApplication>
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

int main(int argc, char *argv[])
{
  //TEST CAR TEAM
   // QCoreApplication a(argc, argv);

    Car* Jeep= new Car();
    double theta= Jeep->get_angle_wheel();
    std::cout<<theta<<std::endl;
    //Jeep->get_points_xy();

  //TEST UI TEAM

    QApplication app(argc, argv);
    windows fenetre(500);
    fenetre.show();
    /*return */app.exec();

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

    b2WheelJoint* liaisonArriere;
    liaisonArriere = (b2WheelJoint*)m_world->CreateJoint(&joint);
*/
    b2Body* m_car;
    b2Body* m_wheel1;
    b2Body* m_wheel2;

    float32 m_hz;
    float32 m_zeta;
    float32 m_speed;
    b2WheelJoint* m_spring1;
    b2WheelJoint* m_spring2;




    b2PolygonShape chassis;
    b2Vec2 vertices[8];
    vertices[0].Set(-1.5f, -0.5f);
    vertices[1].Set(1.5f, -0.5f);
    vertices[2].Set(1.5f, 0.0f);
    vertices[3].Set(0.0f, 0.9f);
    vertices[4].Set(-1.15f, 0.9f);
    vertices[5].Set(-1.5f, 0.2f);
    chassis.Set(vertices, 6);

    b2CircleShape circle;
    circle.m_radius = 0.4f;

    b2BodyDef bd;
    bd.type = b2_dynamicBody;
    bd.position.Set(0.0f, 1.0f);
    m_car = m_world->CreateBody(&bd);
    m_car->CreateFixture(&chassis, 1.0f);

    b2FixtureDef fd;
    fd.shape = &circle;
    fd.density = 1.0f;
    fd.friction = 0.9f;

    bd.position.Set(-1.0f, 0.35f);
    m_wheel1 = m_world->CreateBody(&bd);
    m_wheel1->CreateFixture(&fd);

    bd.position.Set(1.0f, 0.4f);
    m_wheel2 = m_world->CreateBody(&bd);
    m_wheel2->CreateFixture(&fd);

    b2WheelJointDef jd;
    b2Vec2 axis(1.0f, 0.0f);

    jd.Initialize(m_car, m_wheel1, m_wheel1->GetPosition(), axis);
    jd.motorSpeed = -10.0f;
    jd.maxMotorTorque = 60.0f;
    jd.enableMotor = true;
    jd.frequencyHz = m_hz;
    jd.dampingRatio = m_zeta;
    m_spring1 = (b2WheelJoint*)m_world->CreateJoint(&jd);

    jd.Initialize(m_car, m_wheel2, m_wheel2->GetPosition(), axis);
    jd.motorSpeed = 0.0f;
    jd.maxMotorTorque = 60.0f;
    jd.enableMotor = false;
    jd.frequencyHz = 4.0f;
    jd.dampingRatio = 0.5;
    m_spring2 = (b2WheelJoint*)m_world->CreateJoint(&jd);
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 20;
    int32 positionIterations = 20;
    for (int32 i = 0; i < 600; i++)
    {
        m_world->Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = m_car->GetPosition();
        float32 angle = m_car->GetAngle();
        std::cout << " X : " << position.x << " \t Y : " << position.y << " \t Angle : " << angle << std::endl;
    }
    //return 0;

//  QCoreApplication a(argc, argv);
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

    return 0;

}

std::vector<Car> preprocessing::geneticMutation(std::vector< std::pair<Car,double> > cars){
    std::vector<Car> ans;
    return ans;
}
