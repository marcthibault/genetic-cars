#include "preprocessing.h"
#include "car.h"
#include <vector>

preprocessing::preprocessing()
{
    double* open(Car car){

        return null;
    }

    vector<double> generate_coef(int N){ // Function that takes the ranking of the race and generates the coefficients
        vector<double> coeffs = new vector<double>();
        for (i=0;i<N;i++){
           coeffs.push_back(computeCoeffs(i));
        }
        return coeffs;
    }

}
