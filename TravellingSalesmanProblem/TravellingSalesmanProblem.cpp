#pragma once
#include <iostream>
#include <math.h>
#include "World.h"
#include "Point.h"

int main()
{
    std::cout << "Welcome in TSP\n";
    //World firstWorld(10);
    World firstWorld("tsp500.txt");
    //firstWorld.greedyPathFinder();
    firstWorld.antPathFinder();
}
