#pragma once
#include <iostream>
#include <math.h>
#include <fstream>
#include "World.h"
#include "Point.h"

int main()
{
    std::cout << "Welcome in TSP\n";
    
    //Tworzenie swiata
    std::string inFile = "tsp1000.txt";
    World firstWorld(inFile);

    //World firstWorld(250, 1000);
    
    //Szukanie rozwiazania

    //firstWorld.greedyPathFinder();
    firstWorld.antPathFinder(80, 1, 9, 0.4, 1, 30);


    //Wizualizacja
    std::string filename = "networkGraphVisualization.py";
    std::string outFile = "outputVis.txt";
    std::string command = "python ";
    command += filename + " " + inFile + " " + outFile;
    system(command.c_str());
    
}
