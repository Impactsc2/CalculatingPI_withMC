#include <stdlib.h>
#include <iostream>
#include "tools.h"
#include "point.h"
#include  "io.h"


double urand(){
    // generating pseudo-random double type number from the interval [0 , 1]
    return ((double) rand() / (double) RAND_MAX);
}

int CountingPointsInsideCircle(SimulationSettings simulationSettings){

    int counter = 0;
    long int interval = simulationSettings.numberOfPoints / 10;

    // signal that counting starts
    CoutProgress();

    // This loop is counting how many generated points are inside the circle
    for (int i = 1 ; i <= simulationSettings.numberOfPoints ; i++){
        Point *point = new Point(simulationSettings.RADIUS);

        counter += point->IsInsideCircle(simulationSettings.RAD_SQ);

        delete point;

        if (! (i % interval)) {CoutProgress();}
    }
    return counter;
}

double CalculatingPI(SimulationSettings simulationSettings){
    // points inside the circle to all points ratio is equal to PI / 4 
    return ((double) CountingPointsInsideCircle(simulationSettings) / (double) simulationSettings.numberOfPoints) * 4;
}