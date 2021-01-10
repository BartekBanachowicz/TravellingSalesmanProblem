#include"World.h"
#include<chrono>

void World::antPathFinder()
{
	double minimum = DBL_MAX, globalMinimum = DBL_MAX;
	int minimumID = -1;

	//Parameters
	int numberOfAnts = 20;
	double alpha = 0.1;
	int beta = 2;
	int numberOfIterations = 20;

	double max_time = 110.0;

	AntColony myColony(numberOfAnts, this->numberOfPoints);
	myColony.antsSpawning(this->numberOfPoints, this->pointsMatrix);

	std::chrono::duration<double> elapsed;
	double time = 0;
	auto finish = std::chrono::high_resolution_clock::now();
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < numberOfIterations; i++)
	{
		
		minimum = DBL_MAX;
		minimumID = -1;
		
		
		for (int j = 0; j < this->numberOfPoints; j++)
		{
			for (int k = 0; k < myColony.getNumberOfAnts(); k++)
			{
				myColony.makeMove(k, this->numberOfPoints, this->pointsMatrix, beta, q0);
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

		myColony.globalUpdate(minimumID, minimum, numberOfPoints, alpha, tau_0, 0.15);
		myColony.cleaning(this->numberOfPoints);


		if (i == 0)
		{
			finish = std::chrono::high_resolution_clock::now();
			elapsed = finish - start;
			time = elapsed.count();

			numberOfIterations = int(max_time / time);
		}
	}

	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	time = elapsed.count();

	std::cout << "\n\nGlobal minimum: " << globalMinimum << "  Czas: "<<time<<std::endl;

}

