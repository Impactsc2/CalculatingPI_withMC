#include <iostream>
#include "point.h"
#include "tools.h"

Point::Point(double R){
    x = GenerateNumber(R);
    y = GenerateNumber(R);
}

int Point::IsInsideCircle(double RSQ){
    // it returns 1 (true) if the point with coordinates (x , y) 
    // is inside the circle with the center coordinates (0 , 0) and the radius equal to 1 
    // and it returns 0 (false) if it's outside the circle
    return ((y*y <= RSQ - x*x) ? 1 : 0);
}

double Point::GenerateNumber(double R) {
    // transforming a pseudo-random number from the interval [0 , 1] to a number from interval [0 , +RADUS]
    return urand() * R; 
}