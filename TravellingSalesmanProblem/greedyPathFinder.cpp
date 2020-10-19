#include"World.h"
#include <iostream>
#include <limits>

void World::greedyPathFinder()
{

	int start = 0, head = start;
	for (int i = 0; i < this->numberOfPoints; i++) 
	{
		int minID = start;
		double min = DBL_MAX;
		std::cout << start << "\t";
		for (int j = 0; j < this->numberOfPoints; j++) 
		{
			if (this->pathWeights[start][j] > -1 && this->pathWeights[start][j] < min) 
			{
				minID = j;
				min = this->pathWeights[start][j];
			}
		}
		for (int j = 0; j < this->numberOfPoints; j++) 
		{
			this->pathWeights[j][start] = -1;
		}
		start = minID;
	}
	std::cout << head << std::endl;
}
