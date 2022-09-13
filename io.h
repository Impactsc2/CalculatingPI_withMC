#ifndef IO_H
#define IO_H
#include "SimulationSettings.h"

void ReadInputFile(SimulationSettings &simulationSettings, std::string fileName);
void CoutSimulationSettings(SimulationSettings simulationSettings);
void CoutResults(double PI, int precision);
void CoutProgress();
void CreateProgressCounter();

#endif