#include "Floor.h"

/* Permet de créer un sol de test où tous les blocs sont plats*/
Floor::Floor(){
    this->length=1.0;
    this->variance=0.1;
    this->p=new std::list<b2Vec2> ();
    for(int i=0;i<101;i++){
        p->push_back(b2Vec2(i*length-10.0,-2.0));
    }
}

/* Permet de créer un sol sont on peut fixer les paramètres des blocs*/
Floor::Floor(double l, double v){
    this->length=l;
    this->variance=v;
    this->p=new std::list<b2Vec2>();
}

double Floor::getLength(){
    return this->length;
}

double Floor::getVariance(){
    return this->variance;
}

void  Floor::createArrayb2Vec2(int N){
    double a = 0.0;
    double x = -10.0;
    double y = -2.0;
    p->push_back(b2Vec2(x, y));

    for(int i =1;i<N;i++){
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(a,this->variance*i);
        a = distribution(generator);
        x=x+this->length*cos(a);
        y=y+this->length*sin(a);
        p->push_back(b2Vec2(x, y));
    }
}

// assigne le sol (comme succession des points à notre univers
void Floor::floorInitialize(b2World* world){
    // objet b2box du sol
    b2Body* ground = NULL;

    // on l'assigne au monde
    b2BodyDef bd;
    ground = world->CreateBody(&bd);

    // chaque morceau de notre sol est une edge
    b2EdgeShape edge;

    // on donne les caractéristique du sol (utilisé pour chaque morceau ajouté)
    b2FixtureDef fd;
    fd.shape = &edge;
    fd.density = 0.0f;
    fd.friction = 0.9f;

    // on parcourt la liste des points en ajoutant une à une les edges
    while(p->size() > 2){
        // on récupère les deux premiers points
        b2Vec2 q1 = p->front();
        p->pop_front();
        b2Vec2 q2 = p->front();

        // on crée le fixture de l'edge suivant et on l'ajoute
        edge.Set(q1, q2);
        ground->CreateFixture(&fd);
    }
}

/*
void Floor::extend(){
    //TO DO :
    Si le sol est trop court par rapport à la distance déjà parcourue par la meilleure voiture prolonger le sol
        Méthode peut être facultative, il suffit peut être de le créer assez grand au départ
        }
*/
