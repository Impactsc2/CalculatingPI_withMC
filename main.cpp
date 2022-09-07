#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <math.h>

double urand(){
    // generating pseudo-random double type number from the interval [0 , 1]
    return ((double) rand() / (double) RAND_MAX);
}

struct SimulationSettings{
    double RADIUS;
    long int numberOfPoints;
    void ReadingInputFile();
} simulationSettings;

void SimulationSettings::ReadingInputFile(){
    std::string trash;
    std::ifstream file;

    // input file format is:
    // RADIUS:
    // (RADIUS value)
    // numberOfPoints:
    // (numberOfPoints value)
    file.open("input.txt");
    file >> trash;
    file >> simulationSettings.RADIUS;
    file >> trash;
    file >> simulationSettings.numberOfPoints;
    file.close();
}

class Point{
    public:
        double x;
        double y;
        Point();
        double GenerateNumber();
        int IsInsideCircle();
};

Point::Point() {
    // giving coordinates x and y pseudo-random values
    x = GenerateNumber();
    y = GenerateNumber();
}

int Point::IsInsideCircle(){
    // it returns 1 (true) if the point with coordinates (x , y) 
    // is inside the circle with the center coordinates (0 , 0) and the radius equal to 1 
    // and it returns 0 (false) if it's outside the circle
    return ((y*y <= simulationSettings.RADIUS*simulationSettings.RADIUS - x*x) ? 1 : 0);
}

double Point::GenerateNumber() {
    // transforming a pseudo-random number from the interval [0 , 1] to a number from interval [0 , +RADUS]
    return urand() * simulationSettings.RADIUS; 
}

int CountingPointsInsideCircle(){

    int counter = 0;
    
    Point *point = new  Point[simulationSettings.numberOfPoints];

    // This loop is counting how many generated points are inside the circle
    for (int i = 0 ; i < simulationSettings.numberOfPoints ; i++){
        counter += point[i].IsInsideCircle();
    }

    return counter;
}

double CalculatingPI(){
    // points inside the circle to all points ratio is equal to PI / 4 
    return ((double) CountingPointsInsideCircle() / (double) simulationSettings.numberOfPoints) * 4;
}

int main(){
    srand (780428172);
    
    simulationSettings.ReadingInputFile();

    std::cout.precision(20);
    std::cout << std::fixed << CalculatingPI() << std::endl;


    return 0;
}