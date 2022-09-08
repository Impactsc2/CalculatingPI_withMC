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

    srand (simulationSettings.generatorSeed);

    std::cout.precision(20);
    std::cout << std::fixed << CalculatingPI(simulationSettings) << std::endl;


    return 0;
}
