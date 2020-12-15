#include "World.h"
#include <iostream>


void World::greedyPathFinder()
{
	double shortestTotal = DBL_MAX;
	for (int h = 0; h < this->numberOfPoints; h++)
	{
		//std::cout << "\nStarting with point no " << h + 1 << std::endl;
		//std::cout << "Greedy path found:\n";

		int start = h, head = start;
		int minID = start;
		double min = DBL_MAX, distance, distanceTotal = 0;

		for (int i = 0; i < this->numberOfPoints - 1; i++)
		{
			this->pointsMatrix[start].visit();
			distance = 0;
			//std::cout << start + 1 << "\t";

			for (int j = 0; j < this->numberOfPoints; j++)
			{
				if (!this->pointsMatrix[j].ifVisited())
				{
					distance = this->pointsMatrix[start].p2pDistance(this->pointsMatrix[j]);
					//std::cout << start + 1 << " -> " << j + 1 << ": " << distance << std::endl;
					if (distance < min) {
						minID = j;
						min = distance;
					}
				}
			}
			this->pointsMatrix[minID].visit();
			distanceTotal += min;
			start = minID;
			min = DBL_MAX;
		}
		//std::cout << minID + 1 << "\t" << head + 1 << std::endl;		
		distanceTotal += this->pointsMatrix[minID].p2pDistance(this->pointsMatrix[head]);
		//std::cout << "Distance total: " << distanceTotal << std::endl << std::endl;

		if (distanceTotal < shortestTotal)
			shortestTotal = distanceTotal;

		// cleanup
		for (int i = 0; i < this->numberOfPoints; i++)
			this->pointsMatrix[i].resetVisited();

	}
	std::cout << "Length of the shortest greedy path found: " << shortestTotal << std::endl << std::endl;
}

