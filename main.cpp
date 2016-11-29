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

int main(int argc, char *argv[])
{

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

    std::cout<<"Creation d'une nouvelle generation de voitures :" <<std::endl;
    std::vector<std::vector<double>> newMatrix;
    preprocessor.generate(&vec_tab,&newMatrix,3);

    std::cout << "Fin de l'affichage" << std::endl;
    // return a.exec();

    return 0;

}


//test
