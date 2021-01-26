#include"World.h"

void World::antPathFinder(int xNumberOfAnts, int xAlpha, int xBeta, double xPheromoneEvaporation, double xPheromoneSprayingFactor, int xIterations)
{
	
	double minimum = DBL_MAX, globalMinimum = DBL_MAX;
	int minimumID = -1;

	/*int numberOfAnts = 60;
	int alpha = 1;
	int beta = 11;
	double pheromoneEvaporation = 0.15;
	double pheromoneSprayingFactor = 1;*/

	int numberOfAnts = xNumberOfAnts;
	int alpha = xAlpha;
	int beta = xBeta;
	double pheromoneEvaporation = xPheromoneEvaporation;
	double pheromoneSprayingFactor = xPheromoneSprayingFactor;
	int iterations = xIterations;

	int* path = new int[this->numberOfPoints+1];

	AntColony myColony(numberOfAnts, this->numberOfPoints);
	myColony.antsSpawning(this->numberOfPoints, this->pointsMatrix);

	std::chrono::duration<double> elapsed;
	double time = 0;
	auto finish = std::chrono::high_resolution_clock::now();
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < iterations; i++)
	{
		
		minimum = DBL_MAX;
		minimumID = -1;
		
		//std::cout << "Done\n";
		
		for (int j = 0; j < this->numberOfPoints; j++)
		{
			for (int k = 0; k < myColony.getNumberOfAnts(); k++)
			{
				myColony.makeMove(k, this->numberOfPoints, this->pointsMatrix, this->distanceMatix, alpha, beta);
			}
		}

		for (int j = 0; j < myColony.getNumberOfAnts(); j++)
		{
			//std::cout << "\nDistance mrowka " << j << ": " << myColony.getDistance(j);
			
			//if(true)
			/*if ((myColony.getAntIndexSum(j) != this->indexSum) && (myColony.getCurrentIndex(j) != myColony.getStartIndex(j)))
			{
				std::cout << "\n---\nError: " << myColony.getAntIndexSum(j) << ", instead of: "<<this->indexSum<<" index: "<<myColony.getStartIndex(j)<<"\n";
			}*/
			
			
			
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

		/*if (true)
		{
			std::cout << "\nShortest path: " << minimum << " for ant: " << minimumID;

			for (int j = 0; j < this->numberOfPoints; j++)
			{
				std::cout << " " << myColony.getAntPath(minimumID, j);
			}

			std::cout << std::endl;
		}*/

		if (minimum < globalMinimum)
		{
			globalMinimum = minimum;
			for (int j = 0; j < this->numberOfPoints + 1; j++)
			{
				path[j] = myColony.getAntPath(minimumID, j);
			}
			
			
		}

		myColony.globalUpdate(minimumID, minimum, numberOfPoints, pheromoneEvaporation, pheromoneSprayingFactor);
		myColony.cleaning(this->numberOfPoints);

	}

	

	finish = std::chrono::high_resolution_clock::now();
	elapsed = finish - start;
	time = elapsed.count();

	//myColony.antCleaning();

	//this->outputFile << numberOfAnts << ";" << alpha << ";" << beta << ";" << pheromoneEvaporation << ";" << pheromoneSprayingFactor << ";" << time <<";"<<globalMinimum << std::endl;
	std::cout << "\n\nGlobal minimum: " << globalMinimum <<" time: "<<time<<std::endl;

	std::ofstream outputFile;
	outputFile.open("outputVis.txt");

	for (int i = 1; i < this->numberOfPoints + 1; i++)
	{
		outputFile << path[i-1]+1 << " " << path[i]+1<<"\n";
	}

	outputFile.close();

	delete[] path;

}

