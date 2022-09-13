#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "SimulationSettings.h"
#include "io.h"
#include "tools.h"

int main(int argc, char** argv){

    SimulationSettings simulationSettings;

    ReadInputFile(simulationSettings, "input.txt");
    CoutSimulationSettings(simulationSettings);

    srand (simulationSettings.generatorSeed);

    CreateProgressCounter();
    CoutResults(CalculatingPI(simulationSettings), 30);
    return 0;
}