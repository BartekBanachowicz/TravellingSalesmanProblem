#include"World.h"

void World::antPathFinder()
{
	int temp = 1 * this->numberOfPoints;


	AntColony myColony(temp, this->numberOfPoints);
	myColony.antsSpawning(this->numberOfPoints, this->pointsMatrix);

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < this->numberOfPoints; j++)
		{
			for (int k = 0; k < myColony.getNumberOfAnts(); k++)
			{
				myColony.makeMove(k, this->numberOfPoints, this->pointsMatrix);
			}
		}

		for (int j = 0; j < myColony.getNumberOfAnts(); j++)
		{
			std::cout << "\nDistance mrowka " << j << ": " << myColony.getDistance(j);
		}

	}

}

