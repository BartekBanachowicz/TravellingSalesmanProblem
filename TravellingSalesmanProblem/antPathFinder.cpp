#include"World.h"

void World::antPathFinder()
{
	
	double minimum = DBL_MAX, globalMinimum = DBL_MAX;
	int minimumID = -1;

	int numberOfAnts = 60;
	int alpha = 1;
	int beta = 11;
	double pheromoneEvaporation = 0.15;
	double pheromoneSprayingFactor = 1;


	AntColony myColony(numberOfAnts, this->numberOfPoints);
	myColony.antsSpawning(this->numberOfPoints, this->pointsMatrix);

	for (int i = 0; i < 3600; i++)
	{
		
		minimum = DBL_MAX;
		minimumID = -1;
		
		//std::cout << "Done\n";
		
		for (int j = 0; j < this->numberOfPoints; j++)
		{
			for (int k = 0; k < myColony.getNumberOfAnts(); k++)
			{
				myColony.makeMove(k, this->numberOfPoints, this->pointsMatrix, alpha, beta);
			}
		}

		for (int j = 0; j < myColony.getNumberOfAnts(); j++)
		{
			//std::cout << "\nDistance mrowka " << j << ": " << myColony.getDistance(j);
			
			//if(true)
			if ((myColony.getAntIndexSum(j) != this->indexSum) && (myColony.getCurrentIndex(j) != myColony.getStartIndex(j)))
			{
				std::cout << "\n---\nError: " << myColony.getAntIndexSum(j) << ", instead of: "<<this->indexSum<<" index: "<<myColony.getStartIndex(j)<<"\n";
			}
			
			
			
			//if(true)
			/*if (myColony.getDistance(j) < 7542)
			{
				
				std::cout << "Sciezka: ";
				for (int k = 0; k <= this->numberOfPoints; k++)
				{
					std::cout << myColony.getAntPath(j, k) << " ";
				}
				
				std::cout << "  " << myColony.getStartIndex(j) << " " << myColony.getCurrentIndex(j);
				std::cout << "\n";
			}*/
			
			
			
			
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

		myColony.globalUpdate(minimumID, minimum, numberOfPoints, pheromoneEvaporation, pheromoneSprayingFactor);
		myColony.cleaning(this->numberOfPoints);

	}

	std::cout << "\n\nGlobal minimum: " << globalMinimum << std::endl;

}

