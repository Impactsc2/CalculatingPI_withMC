#ifndef POINT_H
#define POINT_H
// #include "SimulationSettings.h"

class Point{
    public:

        /* Ta domyslna wartosc pozwoli wykonac konstruktor bez parametru
         * co umozliwilo by deklaracje calej tablicy obiektow, tak jak Pan mial
         * to zrobione. W moim podejsciu jest to zbedne
         */
        Point(double R = 1e0);
        ~Point();
        double GenerateNumber(double RSQ);
        int IsInsideCircle(double R);

    private:
        double x;
        double y;
};

#endif
