#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "SimulationSettings.h"
#include "io.h"
// #include "point.h"
#include "tools.h"

int main(){

    SimulationSettings simulationSettings;
    ReadInputFile(simulationSettings);

    std::cout << simulationSettings.RADIUS  << std::endl;
    std::cout << simulationSettings.RAD_SQ  << std::endl;
    std::cout << simulationSettings.generatorSeed  << std::endl;
    std::cout << simulationSettings.numberOfPoints  << std::endl;

    srand (simulationSettings.generatorSeed);

    std::cout.precision(20);
    std::cout << std::fixed << CalculatingPI(simulationSettings) << std::endl;


    return 0;
}
