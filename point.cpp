#include <iostream>
#include "point.h"
#include "tools.h"
// #include "io.h"

// Funkcjom, ktore nie potrzebuja wszystkich informacji ze struktury z opcjami
// mozna przekazywac jedynie te parametry ktore sa im niezbedne.
// A w woli scislosci, cala strukture mozna by bylo rowniez przekazac do konstruktora.
// Nie bylo takiej mozliwosci gdy tworzona byla cala tablica obektow od razu.

Point::Point(double R) {
    // giving coordinates x and y pseudo-random values
    x = GenerateNumber(R);
    y = GenerateNumber(R);
    std::cout << "  created at " << x <<","<< y << std::endl;
}

Point::~Point() {
    std::cout << "destroyed at " << x <<","<< y << std::endl;
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
