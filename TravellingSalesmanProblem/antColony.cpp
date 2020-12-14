#pragma once
#include"antColony.h"

AntColony::AntColony(int xNumberOfAnts, int xNumberOfPoints)
{
	this->numberOfAnts = xNumberOfAnts;
	
	for (int i = 0; i < xNumberOfAnts; i++)
	{
		this->colony.push_back(Ant(xNumberOfPoints));
	}
	
	this->pheromoneMatrix = new double* [xNumberOfPoints];
	for (int i = 0; i < xNumberOfPoints; i++)
	{
		pheromoneMatrix[i] = new double[xNumberOfPoints];
	}

	for (int i = 0; i < xNumberOfPoints; i++)
	{
		for (int j = 0; j < xNumberOfPoints; j++)
		{
			pheromoneMatrix[i][j] = 0;
		}
	}
}

void AntColony::antsSpawning(int xNumberOfPoints, Point* pointsMatrix)
{
	int antPointer = 0;
	int tempRand;

	for (int i = 0; i < xNumberOfPoints; i++)
	{
		tempRand = rand() % ((this->numberOfAnts - antPointer) / (xNumberOfPoints - i));

		for (int j = 0; j < tempRand; j++)
		{
			this->colony[antPointer].currentPosition = &pointsMatrix[i];
			this->colony[antPointer].antPath[i] = this->colony[antPointer].currentStage;
			std::cout << colony[antPointer].currentPosition->readCoordinatesX()<<" "<<colony[antPointer].currentPosition->readCoordinatesY()<<std::endl;
			antPointer++;
		}

	}

}