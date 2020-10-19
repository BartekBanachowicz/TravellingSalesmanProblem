#include"World.h"
#include<cstdlib>
#include<ctime>
#include<stdio.h>

void World::generator()
{
	srand(time(0));
	
	for (int i = 0; i < this->numberOfPoints; i++)
	{
		for (int j = 0; j < this->numberOfPoints; j++)
		{
			this->pathWeights[i][j] = 0;
		}
	}


	for (int i = 0; i < this->numberOfPoints; i++)
	{
		for (int j = i; j < this->numberOfPoints; j++)
		{
			if (i != j)
			{
				this->pathWeights[i][j] = rand() % 10 + 1;
				this->pathWeights[j][i] = this->pathWeights[i][j];
			}

		}

	}
}