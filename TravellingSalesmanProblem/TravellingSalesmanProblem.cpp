#include <iostream>
#include <math.h>
#include "World.h"
#include "Point.h"

int main()
{
    std::cout << "Welcome in TSP\n";
    World firstWorld(5);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::printf("%d ", firstWorld.pathWeights[i][j]);
        }
        std::printf("\n");
    }

    firstWorld.greedyPathFinder();

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::printf("%d ", firstWorld.pathWeights[i][j]);
        }
        std::printf("\n");
    }

}
