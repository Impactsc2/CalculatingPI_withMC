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
    
    /*Tu tworzy Pan cala tablice obektow jednoczesznie. Z uzyciem konstruktora
    tak nie mozna zrobic, bo do kazdego obiektu 'i' zostanie wykonny domyslny konstruktor
    (bez parametrowy). Zadeklarowalem 'nasz' konstruktor w taki sposob ze da
    sie ta tablice utworzyc i zostawiam ja zeby Pan zobaczyl dlaczego nie jest
    to dobry pomysl (nie jest aktualnie uzywana w obliczeniach)*/
    Point *points = new  Point[simulationSettings.numberOfPoints];

    /* Nie musimu przechowywac w pamiecy calej tablicy punktow. Mozna je po kolei
     * tworzyc, sprawdzac czy sa wewnatrz okregu i usuwac. W ten sposob dowolnie duze N
     * punktow mozna sprawdzic za pomoca jednego obiektu
     */

    // This loop is counting how many generated points are inside the circle
    for (int i = 0 ; i < simulationSettings.numberOfPoints ; i++){
        Point *point = new Point(simulationSettings.RADIUS);
        // Poniewaz point jest wskaznikiem nalezy uzyc operatora dostepu posredniego '->'
        // zamiast bezposredniego '.'
        counter += point->IsInsideCircle(simulationSettings.RAD_SQ);
        // Wszystko utworzone operatorem new musi byc usuniete
        delete point;
    }

    /*
     * dodalem do konstruktora i destruktora cout, zeby w konsoli bylo widac co jest
     * tworzone i co usuwane. Jak widac obiekty z tablicy points sa tworzone z doyslnym konstruktorem (R=1)
     * ale nie sa usuwane nigdzie a moj pojedynczy obiekt jest tworzony i usuwany z zadanym R
     * ale co wazniejsze, nie zostaje w pamieci po zakonczeniu programu.
     * Nie zwolniona pamiec zaalokowana dynamicznie przez 'new' zostaje po zakoczeniu programu
     * i nadal jest w systemie widziana jako zajeta. To jest tak zwane ciekniecie pamieci (memory leak)
     */
    return counter;
}

double CalculatingPI(SimulationSettings simulationSettings){
    // points inside the circle to all points ratio is equal to PI / 4 
    return ((double) CountingPointsInsideCircle(simulationSettings) / (double) simulationSettings.numberOfPoints) * 4;
}
