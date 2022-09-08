#include <fstream>
#include <iostream>
#include "io.h"


void ReadInputFile(SimulationSettings &simulationSettings){
    std::string trash;
    std::ifstream file;

    // input file format is:
    // RADIUS:
    // (RADIUS value)
    // numberOfPoints:
    // (numberOfPoints value)
    // generatorSeed:
    // (generatorSeed value)
    file.open("input.txt");
    file >> trash;
    file >> simulationSettings.RADIUS;
    file >> trash;
    file >> simulationSettings.numberOfPoints;
    file >> trash;
    file >> simulationSettings.generatorSeed;
    file.close();
    simulationSettings.RAD_SQ = simulationSettings.RADIUS*simulationSettings.RADIUS;
}
