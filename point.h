#ifndef POINT_H
#define POINT_H

class Point{
    public:
        // constructor:
        Point(double R);

        double GenerateNumber(double R);
        int IsInsideCircle(double RSQ);

    private:
        double x;
        double y;
};

#endif