#include"World.h"

void World::antPathFinder()
{
	int temp = 5 * this->numberOfPoints;


	AntColony myColony(temp, this->numberOfPoints);
	myColony.antsSpawning(this->numberOfPoints, this->pointsMatrix);

}

