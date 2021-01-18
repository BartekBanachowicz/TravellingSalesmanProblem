#pragma once
#include <iostream>
#include <math.h>
#include "World.h"
#include "Point.h"

int main()
{
    std::cout << "Welcome in TSP\n";
    
    //Tworzenie swiata
    
    //World firstWorld(10);
    World firstWorld("tsp250.txt");
    
    
    //Szukanie rozwiazania

    //firstWorld.greedyPathFinder();
    firstWorld.antPathFinder(150, 1, 10, 0.15, 1);
    
}
