#include <fstream>
#include <iostream>
#include "io.h"


void ReadInputFile(SimulationSettings &simulationSettings, std::string fileName){
    std::string trash;
    std::ifstream file;

    // input file format is:
    // RADIUS:
    // (RADIUS value)
    // numberOfPoints(must be divisible by 100):
    // (numberOfPoints value)
    // generatorSeed:
    // (generatorSeed value)
    file.open(fileName);
    file >> trash;
    file >> simulationSettings.RADIUS;
    file >> trash;
    file >> trash;
    file >> trash;
    file >> trash;
    file >> trash;
    file >> simulationSettings.numberOfPoints;
    file >> trash;
    file >> simulationSettings.generatorSeed;
    file.close();
    simulationSettings.RAD_SQ = simulationSettings.RADIUS*simulationSettings.RADIUS;
}

void CoutSimulationSettings(SimulationSettings simulationSettings){
    std::cout << std::endl;
    std::cout << "Simulation Settings:" << std::endl;
    std::cout << "RADIUS:" << simulationSettings.RADIUS << std::endl;
    std::cout << "RAD_SQ:" << simulationSettings.RAD_SQ << std::endl;
    std::cout << "NumberOfPoints:" << simulationSettings.numberOfPoints << std::endl;
    std::cout << "generatorSeed:" << simulationSettings.generatorSeed << std::endl << std::endl;
}

void CoutResults(double PI, int precision){
    std::cout << std::endl;
    std::cout.precision(precision);
    std::cout << std::fixed << "Calculated PI:" << PI <<std::endl;
}

void CreateProgressCounter(){
    std::cout << "Progres in 10%:" << std::endl;
    for (int i = 0; i <= 10 ; i++) {std::cout << i << " ";}
    std::cout << std::endl;
}

void CoutProgress(){
    std::cout << "| "; 
}
