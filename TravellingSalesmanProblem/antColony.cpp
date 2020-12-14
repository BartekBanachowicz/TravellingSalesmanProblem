#pragma once
#include"antColony.h"

AntColony::AntColony(int xNumberOfAnts, int xNumberOfPoints)
{
	this->numberOfAnts = xNumberOfAnts;
	
	for (int i = 0; i < xNumberOfAnts; i++)
	{
		//std::cout << "\nMrówka " << i << ": ";
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
			pheromoneMatrix[i][j] = 1;
		}
	}
}

void AntColony::antsSpawning(int xNumberOfPoints, Point* pointsMatrix)
{
	int antPointer = 0, pointsPointer=0;
	int tempRand;

	while (antPointer != this->numberOfAnts)
	{
		
		tempRand = rand() % 100;

		if (tempRand > 50)
		{
			this->colony[antPointer].currentPosition = &pointsMatrix[pointsPointer];
			this->colony[antPointer].antPath[pointsPointer] = this->colony[antPointer].currentStage;
			this->colony[antPointer].currentPositionID = pointsPointer;
			std::cout << colony[antPointer].currentPosition->readCoordinatesX() << " " << colony[antPointer].currentPosition->readCoordinatesY() << std::endl;
			antPointer++;
		}
		
		pointsPointer++;
		pointsPointer = pointsPointer % xNumberOfPoints;

	}
	
	std::cout << antPointer<<std::endl;

}

double AntColony::getPheromone(int x, int y)
{
	return this->pheromoneMatrix[x][y];
}

int AntColony::decisionMaking(int antID, int xNumberOfPoints, Point *pointsMatrix)
{
	int newPlaceID = -1;
	int q0 = 50;
	int q = 0;
	double beta = 1.0;
	int maxID = 0;
	double max = 0;
	double tempValue = 0;
	double* attractivenessArray = new double[xNumberOfPoints];
	double* probabilityArray = new double[xNumberOfPoints];
	double attractivenessSum = 0;
	double probability;
	int pointer = 0;


	for (int i = 0; i < xNumberOfPoints; i++)
	{

		if (this->colony[antID].getAntPath(i) == 0)
		{
			tempValue = this->getPheromone(this->colony[antID].currentPositionID, i) * (1 / this->colony[antID].currentPosition->p2pDistance(pointsMatrix[i]));
			//ToDO - Add beta parameter

			std::cout << "Wykonano\n";
			attractivenessArray[i] = tempValue;
		}
		else
		{
			attractivenessArray[i] = 0;
		}
	}

	std::cout << "Mrowka " << antID << ": ";
	for(int i=0; i < xNumberOfPoints; i++) std::cout << attractivenessArray[i] <<" ";

	q = rand() % 100;

	if (q <= q0)
	{
		max = 0;
		for (int i = 0; i < xNumberOfPoints; i++)
		{
			if (attractivenessArray[i] > max)
			{
				max = attractivenessArray[i];
				maxID = i;
			}
		}

		newPlaceID = maxID;
	}
	else
	{
		attractivenessSum = 0;
		for (int i = 0; i < xNumberOfPoints; i++)
		{
			attractivenessSum += attractivenessArray[i];
		}

		for (int i = 0; i < xNumberOfPoints; i++)
		{
			probabilityArray[i] = double(attractivenessArray[i]) / double(attractivenessSum);
		}

		probability = double(rand() % 100) / 100;

		if (probability == 0.0)
		{
			while (probabilityArray[pointer] == 0) pointer++;
			newPlaceID = pointer;
		}
		else
		{
			while (probability > 0.0)
			{
				if (probability > probabilityArray[pointer])
				{
					probability -= probabilityArray[pointer];
					probabilityArray[pointer] = 0;
					pointer++;
				}
				else
				{
					newPlaceID = pointer;
					break;
				}
			}
		}
		

	}

	if (newPlaceID == -1)
	{
		std::cout << "Error_decisionMaking\n";
	}

	std::cout << " --> " << newPlaceID << std::endl;

	return newPlaceID;
}

int AntColony::getNumberOfAnts()
{
	return this->numberOfAnts;
}

void AntColony::makeMove(int antID, int xNumberOfPoints, Point* pointsMatrix)
{
	int newPlaceID = decisionMaking(antID, xNumberOfPoints, pointsMatrix);
	this->colony[antID].move(&pointsMatrix[newPlaceID], newPlaceID, this->pheromoneMatrix);
}