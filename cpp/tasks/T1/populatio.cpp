#include <iostream>
#include <cmath>

using namespace std;

void calculatePopulationWithLoop(double initialPopulation, double growthRate, int& years) {
    double population = initialPopulation;
    years = 0;
    while (population <= 1000000) {
        cout << "Year " << years << ": " << static_cast<int>(population) << endl;
        population *= (1 + growthRate);
        years++;
    }
}

int calculateYearsWithoutLoop(double initialPopulation, double growthRate) {
    return ceil(log(1000000.0 / initialPopulation) / log(1 + growthRate));
}

int main() {
    const double initialPopulation = 162100;
    const double growthRate = 0.065;
    int years;

    calculatePopulationWithLoop(initialPopulation, growthRate, years);
    cout << "It took " << years << " years for the population to surpass one million." << endl;

    int yearsNoLoop = calculateYearsWithoutLoop(initialPopulation, growthRate);
    cout << "Years required to surpass one million (calculated without loop): " << yearsNoLoop << endl;

    return 0;
}
