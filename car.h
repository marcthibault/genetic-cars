#ifndef CAR_H
#define CAR_H


class Car
{
public :
    double rayon1;
    double rayon2;
    vector<pair<double, double>> haut;
    vector<pair<double, double>> bas;

    Car();
    Car(double rayon1, double rayon2);
};

#endif // CAR_H
