#pragma once
#include"antColony.h"

AntColony::AntColony(int xNumberOfAnts, int xNumberOfPoints)
{
	this->numberOfAnts = xNumberOfAnts;
	
	for (int i = 0; i < xNumberOfAnts; i++)
	{
		//std::cout << "\nMr�wka " << i << ": ";
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
			this->colony[antPointer].currentPositionID = pointsPointer;
			this->colony[antPointer].startPointID = pointsPointer;
			std::cout << colony[antPointer].currentPosition->readCoordinatesX() << " " << colony[antPointer].currentPosition->readCoordinatesY() << std::endl;
			this->colony[antPointer].setAntIndexSum(pointsPointer);
			this->colony[antPointer].setAntPathInOrder(0, pointsPointer);
			this->colony[antPointer].setAntPathByIndex(pointsPointer, 1);
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

int AntColony::decisionMaking(int antID, int xNumberOfPoints, Point *pointsMatrix, int alpha, int beta)
{
	int newPlaceID = -1;
	int maxID = 0;
	double max = 0;
	double tempValue = 0;
	double* attractivenessArray = new double[xNumberOfPoints];
	double* probabilityArray = new double[xNumberOfPoints];
	double attractivenessSum = 0;
	double probability;
	int pointer = 0;
	bool finalStep = true;
	double probabilitySum = 0;


	for (int i = 0; i < xNumberOfPoints; i++)
	{

		if (this->colony[antID].getAntPathByIndex(i) == 0)
		{
			tempValue = pow(this->getPheromone(this->colony[antID].currentPositionID, i), alpha) * pow((1 / this->colony[antID].currentPosition->p2pDistance(pointsMatrix[i])), beta);
			//tempValue = (this->getPheromone(this->colony[antID].currentPositionID, i) * alpha) + (beta / this->colony[antID].currentPosition->p2pDistance(pointsMatrix[i]));
			
			attractivenessArray[i] = tempValue;
			attractivenessSum += tempValue;
			
			finalStep = false;
		}
		else
		{
			attractivenessArray[i] = 0;
		}
	}

	if(!finalStep)
	{

		for (int i = 0; i < xNumberOfPoints; i++)
		{
			probabilityArray[i] = double(attractivenessArray[i]) / double(attractivenessSum);
			//std::cout << probabilityArray[i] << "\n";
			probabilitySum += probabilityArray[i];
		}

		//srand(time(0));
		probability = double(rand() % 100) / 100;
		//probability *= attractivenessSum;
		//std::cout << "\n\n"; //<< probability;

		if (probability == 0.0)
		{
			while (this->colony[antID].getAntPathByIndex(pointer) != 0) pointer++;
			newPlaceID = pointer;
		}
		else
		{
			while (probability > 0.0)
			{
				if (probability > probabilityArray[pointer])
				{
					probability -= probabilityArray[pointer];
					probabilityArray[pointer] = 0.0;
					pointer++;

				}
				else if(this->colony[antID].getAntPathByIndex(pointer) == 0)
				{
					newPlaceID = pointer;
					probability = 0;
					break; 
				}
				else
				{
					pointer = 0;
					while (this->colony[antID].getAntPathByIndex(pointer) != 0) pointer++;
					newPlaceID = pointer;
					break;
				}
			}
		}
	}
	else
	{
		
		/*std::cout << "\nSciezka: ";
		for (int i = 0; i < xNumberOfPoints; i++)
		{
			std::cout<< this->colony[antID].getAntPathByIndex(i) << " ";
		}*/
		
		
		newPlaceID = this->colony[antID].startPointID;
	}

	if (newPlaceID == -1)
	{
		std::cout << "Error_decisionMaking\n";
	}

	//std::cout << " --> " << newPlaceID << std::endl;

	delete[] attractivenessArray;
	delete[] probabilityArray;

	return newPlaceID;
}

int AntColony::getNumberOfAnts()
{
	return this->numberOfAnts;
}

void AntColony::makeMove(int antID, int xNumberOfPoints, Point* pointsMatrix, int alpha, int beta)
{
	int newPlaceID = decisionMaking(antID, xNumberOfPoints, pointsMatrix, alpha, beta);
	this->colony[antID].move(&pointsMatrix[newPlaceID], newPlaceID, this->pheromoneMatrix);
}

double AntColony::getDistance(int antID)
{
	return this->colony[antID].distance;
}

void AntColony::globalUpdate(int antID, double pathLenght, int xNumberOfPoints, double pheromoneEvaporation, double pheromoneSprayingFactor)
{	
	
	double tempPheromone = 0;
	int tempIndexSum;

	for (int i = 0; i < xNumberOfPoints; i++)
	{
		for (int j = 0; j < xNumberOfPoints; j++)
		{
			this->pheromoneMatrix[i][j] *= (1 - pheromoneEvaporation);
			this->pheromoneMatrix[j][i] *= (1 - pheromoneEvaporation);
		}
	}

	for (int i = 0; i < numberOfAnts; i++)
	{
		tempIndexSum = 0;

		for (int j = 0; j < xNumberOfPoints; j++)
		{
			tempIndexSum += j;
		}

		tempPheromone = double(pheromoneSprayingFactor) / this->colony[i].distance;

		for (int j = 1; j <= xNumberOfPoints; j++)
		{
			this->pheromoneMatrix[this->colony[i].getAntPathInOrder(j-1)][this->colony[i].getAntPathInOrder(j)] += tempPheromone;
			this->pheromoneMatrix[this->colony[i].getAntPathInOrder(j)][this->colony[i].getAntPathInOrder(j-1)] += tempPheromone;
		}
	}
}

void AntColony::cleaning(int xNumberOfPoints)
{
	for (int i = 0; i < this->getNumberOfAnts(); i++)
	{
		this->colony[i].currentStage = 0;
		this->colony[i].distance = 0.0;
		this->colony[i].setAntIndexSum(0);

		for (int j = 0; j <= xNumberOfPoints; j++)
		{
			if (j != xNumberOfPoints) this->colony[i].setAntPathByIndex(j, 0);
			this->colony[i].setAntPathInOrder(j, 0);
		}

		this->colony[i].setAntPathByIndex(this->colony[i].startPointID, 1);
		this->colony[i].setAntPathInOrder(0, this->colony[i].startPointID);
	}
}

int AntColony::getAntIndexSum(int antIndex)
{
	return this->colony[antIndex].getAntIndexSum();
}

int AntColony::getStartIndex(int antID)
{
	return this->colony[antID].startPointID;
}

int AntColony::getAntPath(int antID, int pointID)
{
	return this->colony[antID].getAntPathInOrder(pointID);
}

int AntColony::getCurrentIndex(int antID)
{
	return this->colony[antID].currentPositionID;
}