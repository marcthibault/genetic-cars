#ifndef STRATEGY_H
#define STRATEGY_H


class strategy
{
public:
    strategy();
    std::vector<vector<double>> generateCoeffsRandom(std::vector<vector<double>> cars);
    std::vector<vector<double>> generateCoeffs(std::vector<vector<double>> carsAndDistance);
    std::pair<int,int> selectParents(std::vector<double> & distances);
    std::vector<double> generateRandomVector(std::vector<std::vector<double>> cars);

};

#endif // STRATEGY_H
