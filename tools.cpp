#include <stdlib.h>
#include <iostream>
#include "tools.h"
#include "point.h"


double urand(){
    // generating pseudo-random double type number from the interval [0 , 1]
    return ((double) rand() / (double) RAND_MAX);
}

int CountingPointsInsideCircle(SimulationSettings simulationSettings){

    int counter = 0;
    
    Point *point = new  Point[simulationSettings.numberOfPoints];

    // This loop is counting how many generated points are inside the circle
    for (int i = 0 ; i < simulationSettings.numberOfPoints ; i++){
        point[i].SetCoordiates(simulationSettings);
        counter += point[i].IsInsideCircle(simulationSettings);
    }
    return counter;
}

double CalculatingPI(SimulationSettings simulationSettings){
    // points inside the circle to all points ratio is equal to PI / 4 
    return ((double) CountingPointsInsideCircle(simulationSettings) / (double) simulationSettings.numberOfPoints) * 4;
}