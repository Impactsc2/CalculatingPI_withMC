#ifndef POINT_H
#define POINT_H
#include "SimulationSettings.h"

class Point{
    public:
        void SetCoordiates(SimulationSettings simulationSettings);
        double GenerateNumber(SimulationSettings simulationSettings);
        int IsInsideCircle(SimulationSettings simulationSettings);

    private:
        double x;
        double y;
};

#endif