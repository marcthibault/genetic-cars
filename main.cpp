<<<<<<< HEAD
//#include <QCoreApplication>
//#include <Box2D/Box2D.h>
//#include <QApplication>
//#include <QCoreApplication>
#include "car.h"
#include "preprocessing.h"
#include <iostream>
//#include "windows.h"
//#include <QWidget>
//#include <QTimer>
//#include <QGraphicsScene>
//#include <QGraphicsView>
//#include <QPolygonF>
//#include <QPointF>
//#include <utility>
=======
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
#include <math.h>

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
    windows fenetre(40);

    fenetre.show();


  //TEST TEAM PHY
    //Car(int N, double r1, double d1, double r2, double d2, double D, double d, vector<pair<double, double> > angles_distances); //constructeur
    vector < pair < double, double > > sommetsPolaire; // création d'une voiture rectangulaire de largeur 4 et de hauteur 2
    sommetsPolaire.push_back( std::make_pair(M_PI/4, 2*sqrt(2)) );
    sommetsPolaire.push_back( std::make_pair(3*M_PI/4, 2*sqrt(2)) );

//    sommetsPolaire.push_back( std::make_pair(0, 2) );
//    sommetsPolaire.push_back( std::make_pair(M_PI, 2) );
//    sommetsPolaire.push_back( std::make_pair(M_PI/6, 2) );
//    sommetsPolaire.push_back( std::make_pair(2*M_PI/6, 2) );
//    sommetsPolaire.push_back( std::make_pair(3*M_PI/6, 2) );
//    sommetsPolaire.push_back( std::make_pair(4*M_PI/4, 2) );


    Car c (4, 0.4 ,1, 0.4,1, 4, 1, sommetsPolaire);
  //  Car c;
    double angle = c.get_angle_wheel();
    vector<pair<double,double> > pos = c.get_points();
    vector< pair < double, double > > posXY = c.get_points_xy();

   //Moteur* m = new Moteur(10.0);
   Moteur* m = new Moteur(10.0, c);


    app.exec();

    //à virer ?
    // while (!m->toutesCarBloquees(5.0))
    // {
    //     m->next(1.0/20.0);
    //     m->printPositions();
    //     //std::vector< std::array<float,4> > bidule = m->getPosition() ; //test de la fonction getPosition
    // }

    // QVector<QPointF> vect;
    // vect.append(QPointF(10.0,10.0));
    // vect.append(QPointF(10.0,100.0));
    // vect.append(QPointF(200.0,150.0));
    // vect.append(QPointF(300.0,100.0));
    // vect.append(QPointF(200.0,50.0));
    // vect.append(QPointF(150.0,10.0));
    //
    // fenetre.displayFloor(vect);

    /*

    app.exec();

    std::cout << "Starting..." << std::endl;


    // TEST GEN TEAM

    /* Pipeline :
     * 1. Création d'une première génération.
     * 2. Pour chaque génération :
     *  a. Transformer les résultats de la course en matrice (carsToMatrix)
     *  b. Générer les nouvelles voitures à l'aide des résultats :
     *     i. Générer des coefficients à l'aide de plusieurs stratégies (fonctions de la classe strategy)
     *     ii. Pour chacune des stratégies, créer des voitures à partir des coefficient (generate)
     *  c. Transformer cette matrice en vecteur de voitures (matrixToCars)
     */
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
    // Tester la génération d'une voiture aléatoire
    std::vector<double> means = {1.6, 2.6, 3.6, 4.6, 22.6, 22.6, 22.6, 22.6, 22.6, 22.6};
    std::vector<double> variances = {0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1};

    std::cout << "Generation de voitures générées aléatoirement" << std::endl;
    Car car = preprocessor.generateRandomCar(means, variances);
    Car car2 = preprocessor.generateRandomCar(means, variances);
    Car car3 = preprocessor.generateRandomCar(means, variances);
    std::cout << "Impression d'un voiture" << std::endl;
    std::vector<double> vec = preprocessor.openCar(&car);
    preprocessor.printVector(&vec);
    vec = preprocessor.openCar(&car2);
    preprocessor.printVector(&vec);
    vec = preprocessor.openCar(&car3);
    preprocessor.printVector(&vec);
    std::cout << "Test de CarsToMatrix" << std::endl;
    std::pair<Car,double> p1 (car,1.);
    std::pair<Car,double> p2 (car2,2.);
    std::pair<Car,double> p3 (car3,3.);
    std::vector<std::pair<Car,double>> cars = { p1,p2,p3};
    std::vector<std::vector<double>> vec_tab = preprocessor.carsToMatrix(&cars);
    preprocessor.printVector(&vec_tab[0]);

    strategy strat = strategy();
    std::cout<<"Creation d'une nouvelle generation de voitures :" <<std::endl;
    std::vector<std::vector<double>> newMatrix;
    preprocessor.generate(strat, &vec_tab,&newMatrix,3);

    std::cout << "Fin de l'affichage" << std::endl;
    // return a.exec();
    return 0;



}

std::vector<Car> preprocessing::geneticMutation(std::vector< std::pair<Car,double> > cars){
    std::vector<Car> ans;
    return ans;
}
