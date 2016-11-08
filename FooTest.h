#ifndef FOOTEST_H
#define FOOTEST_H

class FooTest : public Test
{
public:
    FooTest() {
        
        b2BodyDef groundBodyDef;
        groundBodyDef.position.Set(0.0f, -10.0f);
        b2Body* groundBody = m_world->CreateBody(&groundBodyDef);
        b2PolygonShape groundBox;
        groundBox.SetAsBox(500.0f, 100.0f);
        groundBody->CreateFixture(&groundBox, 0.0f);
        
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
        
        bd.position.Set(2.0f, 2.0f);
        wheel1 = m_world->CreateBody(&bd);
        wheel1->CreateFixture(&fd);
        
        bd.position.Set(-2.0f, -2.0f);
        wheel2 = m_world->CreateBody(&bd);
        wheel2->CreateFixture(&fd);
        
        b2WheelJointDef joint;
        b2Vec2 axe(0.0f, 1.0f);
        
        joint.Initialize(car, wheel1, wheel1->GetPosition(), axe);
        joint.motorSpeed = 0.5f;
        joint.maxMotorTorque = 20.0f;
        joint.enableMotor = true;
        joint.frequencyHz = 4.0f;
        joint.dampingRatio = 0.5f;
        
        
        b2WheelJoint* liaisonAvant;
        b2WheelJoint* liaisonArriere;
        
        liaisonAvant = (b2WheelJoint*)m_world->CreateJoint(&joint);
        
        joint.Initialize(car, wheel2, wheel2->GetPosition(), axe);
        joint.motorSpeed = 0.5f;
        joint.maxMotorTorque = 20.0f;
        joint.enableMotor = false;
        joint.frequencyHz = 4.0f;
        joint.dampingRatio = 0.5f;
        
        liaisonArriere = (b2WheelJoint*)m_world->CreateJoint(&joint);
        
        
    } //do nothing, no scene yet
    
    void Step(Settings* settings)
    {
        //run the default physics and rendering
        Test::Step(settings);
        
        //show some text in the main screen
        m_debugDraw.DrawString(5, m_textLine, "Now we have a foo test");
        m_textLine += 15;
    }
    
    static Test* Create()
    {
        return new FooTest;
    }
};

#endif
