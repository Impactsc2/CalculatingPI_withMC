#include <iostream>
#include "point.h"
#include "tools.h"
#include "io.h"


void Point::SetCoordiates(SimulationSettings simulationSettings) {
    // giving coordinates x and y pseudo-random values
    x = GenerateNumber(simulationSettings);
    y = GenerateNumber(simulationSettings);   
}

int Point::IsInsideCircle(SimulationSettings simulationSettings){
    // it returns 1 (true) if the point with coordinates (x , y) 
    // is inside the circle with the center coordinates (0 , 0) and the radius equal to 1 
    // and it returns 0 (false) if it's outside the circle
    return ((y*y <= simulationSettings.RAD_SQ - x*x) ? 1 : 0);
}

double Point::GenerateNumber(SimulationSettings simulationSettings) {
    // transforming a pseudo-random number from the interval [0 , 1] to a number from interval [0 , +RADUS]
    return urand() * simulationSettings.RADIUS; 
}