#include "b2Car.h"

b2Car::b2Car()
{
}

void b2Car::initializeTestCar(b2World* m_world){

    float m_hz = 4.0f;
    float m_zeta = 0.7f;

    nom = "Voiture de test";
    tempsStagnation = 0;
    positionMaximale = new b2Vec2(0.0, 0.0);
    classement = -1;

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
    b2FixtureDef fd_car;
    fd_car.shape = &chassis;
    fd_car.density = 1.0f;
    fd_car.friction = 0.9f;
    fd_car.filter.groupIndex = -1;
    m_car = m_world->CreateBody(&bd);
    m_car->CreateFixture(&fd_car);

    b2FixtureDef fd;
    fd.shape = &circle;
    fd.density = 1.0f;
    fd.friction = 0.9f;
    fd.filter.groupIndex = -1;

    b2Body* m_wheel1;
    bd.position.Set(-1.0f, 0.35f);
    m_wheel1 = m_world->CreateBody(&bd);
    m_wheel1->CreateFixture(&fd);

    b2Body* m_wheel2;
    bd.position.Set(1.0f, 0.4f);
    m_wheel2 = m_world->CreateBody(&bd);
    m_wheel2->CreateFixture(&fd);

    b2WheelJointDef jd;
    b2Vec2 axis(0.0f, 1.0f);

    jd.Initialize(m_car, m_wheel1, m_wheel1->GetPosition(), axis);
    jd.motorSpeed = -5.0f;
    jd.maxMotorTorque = 20.0f;
    jd.enableMotor = true;
    jd.frequencyHz = m_hz;
    jd.dampingRatio = m_zeta;
    b2WheelJoint* m_spring1 = (b2WheelJoint*)m_world->CreateJoint(&jd);

    jd.Initialize(m_car, m_wheel2, m_wheel2->GetPosition(), axis);
    jd.motorSpeed = 0.0f;
    jd.maxMotorTorque = 10.0f;
    jd.enableMotor = false;
    jd.frequencyHz = m_hz;
    jd.dampingRatio = m_zeta;
    b2WheelJoint* m_spring2 = (b2WheelJoint*)m_world->CreateJoint(&jd);
}

void b2Car::initializeTestCarNulle(b2World* m_world){

    float m_hz = 4.0f;
    float m_zeta = 0.7f;

    nom = "Voiture de test nulle";
    tempsStagnation = 0;
    positionMaximale = new b2Vec2(0.0, 0.0);
    classement = -1;

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
    b2FixtureDef fd_car;
    fd_car.shape = &chassis;
    fd_car.density = 1.0f;
    fd_car.friction = 0.9f;
    fd_car.filter.groupIndex = -1;
    m_car = m_world->CreateBody(&bd);
    m_car->CreateFixture(&fd_car);

    b2FixtureDef fd;
    fd.shape = &circle;
    fd.density = 1.0f;
    fd.friction = 0.9f;
    fd.filter.groupIndex = -1;

    b2Body* m_wheel1;
    bd.position.Set(-1.0f, 0.35f);
    m_wheel1 = m_world->CreateBody(&bd);
    m_wheel1->CreateFixture(&fd);

    b2Body* m_wheel2;
    bd.position.Set(1.0f, 0.4f);
    m_wheel2 = m_world->CreateBody(&bd);
    m_wheel2->CreateFixture(&fd);

    b2WheelJointDef jd;
    b2Vec2 axis(0.0f, 1.0f);

    jd.Initialize(m_car, m_wheel1, m_wheel1->GetPosition(), axis);
    jd.motorSpeed = -2.0f;
    jd.maxMotorTorque = 20.0f;
    jd.enableMotor = true;
    jd.frequencyHz = m_hz;
    jd.dampingRatio = m_zeta;
    b2WheelJoint* m_spring1 = (b2WheelJoint*)m_world->CreateJoint(&jd);

    jd.Initialize(m_car, m_wheel2, m_wheel2->GetPosition(), axis);
    jd.motorSpeed = 0.0f;
    jd.maxMotorTorque = 10.0f;
    jd.enableMotor = false;
    jd.frequencyHz = m_hz;
    jd.dampingRatio = m_zeta;
    b2WheelJoint* m_spring2 = (b2WheelJoint*)m_world->CreateJoint(&jd);
}

void b2Car::printPosition(){
    b2Vec2 position = this->m_car->GetPosition();
    float32 angle = this->m_car->GetAngle();
    std::cout << " X : " << position.x << " \t Y : " << position.y << " \t Angle : " << angle << "\t Temps de stagnation : " << tempsStagnation << "Classement :" << classement <<  std::endl;
}

bool b2Car::bloquee(float tempsStagnationMax){
    return tempsStagnation > tempsStagnationMax;
}

//b2Car::b2Car(Car car){
//    //constructeur qui crée la forme + les joints + les roues etc ...
//}
