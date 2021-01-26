#include"World.h"

void World::antPathFinder()
{
	int temp = 1 * this->numberOfPoints;
	double minimum = DBL_MAX, globalMinimum = DBL_MAX;
	int minimumID = -1;


	AntColony myColony(temp, this->numberOfPoints);
	myColony.antsSpawning(this->numberOfPoints, this->pointsMatrix);

	for (int i = 0; i < 20; i++)
	{
		
		minimum = DBL_MAX;
		minimumID = -1;
		
		
		for (int j = 0; j < this->numberOfPoints; j++)
		{
			for (int k = 0; k < myColony.getNumberOfAnts(); k++)
			{
				myColony.makeMove(k, this->numberOfPoints, this->pointsMatrix);
			}
		}

		for (int j = 0; j < myColony.getNumberOfAnts(); j++)
		{
			//std::cout << "\nDistance mrowka " << j << ": " << myColony.getDistance(j);
			
			if (myColony.getDistance(j) < minimum)
			{
				minimum = myColony.getDistance(j);
				minimumID = j;
			}
		}

		//std::cout << "\nShortest path: " << minimum << " for ant: " << minimumID << std::endl;

		if (minimum < globalMinimum)
		{
			globalMinimum = minimum;
		}

		myColony.globalUpdate(minimumID, minimum, numberOfPoints);
		myColony.cleaning(this->numberOfPoints);

	}

	std::cout << "\n\nGlobal minimum: " << globalMinimum << std::endl;

}

