#pragma once
#include"antColony.h"
#include<cmath>

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
			this->colony[antPointer].startPointID = pointsPointer;
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

int AntColony::decisionMaking(int antID, int xNumberOfPoints, Point* pointsMatrix, int beta, int alpha)
{
	int newPlaceID = -1;
	int q = 0;
	int maxID = 0;
	double max = 0;
	double tempValue = 0;
	double* attractivenessArray = new double[xNumberOfPoints];
	double* probabilityArray = new double[xNumberOfPoints];
	double attractivenessSum = 0;
	double probability;
	int pointer = 0;
	bool finalStep = true;
	//int alpha = 1;


	for (int i = 0; i < xNumberOfPoints; i++)
	{

		if (this->colony[antID].getAntPath(i) == 0)
		{
			//tempValue = this->getPheromone(this->colony[antID].currentPositionID, i) * (pow((1 / this->colony[antID].currentPosition->p2pDistance(pointsMatrix[i])), beta));
			
			//New method - new equation

			tempValue = (pow(this->getPheromone(this->colony[antID].currentPositionID, i), alpha)) * (pow((1 / this->colony[antID].currentPosition->p2pDistance(pointsMatrix[i])), beta));
			attractivenessSum += tempValue;


			//std::cout << "Wykonano\n";
			attractivenessArray[i] = tempValue;
			if (tempValue != 0) finalStep = false;

			
		}
		else
		{
			attractivenessArray[i] = 0;
		}
	}

	//std::cout << "Mrowka " << antID << ": ";
	//for(int i=0; i < xNumberOfPoints; i++) std::cout << attractivenessArray[i] <<" ";

	/*q = rand() % 100;
	probability = double(q) / 100;*/
	
	/*for (int i = 0; i < xNumberOfPoints; i++)
	{
		probabilityArray[i] = (attractivenessArray[i] / attractivenessSum);
	}

	
	if (!finalStep)
	{
		while (probability > 0)
		{
			if (probabilityArray[pointer] >= probability)
			{
				probability = 0;
				newPlaceID = pointer;
			}
			else
			{
				probability -= probabilityArray[pointer];
				pointer++;
			}
		}
	}
	else
	{
		newPlaceID = this->colony[antID].startPointID;
	}*/
	




	/*if ((q <= q0) && !finalStep)
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
	}*/

	if(!finalStep)
	{
		/*attractivenessSum = 0;
		for (int i = 0; i < xNumberOfPoints; i++)
		{
			attractivenessSum += attractivenessArray[i];
		}*/

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
	else
	{
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

void AntColony::makeMove(int antID, int xNumberOfPoints, Point* pointsMatrix, int beta, int q0)
{
	int newPlaceID = decisionMaking(antID, xNumberOfPoints, pointsMatrix, beta, q0);
	this->colony[antID].move(&pointsMatrix[newPlaceID], newPlaceID, this->pheromoneMatrix);
}

double AntColony::getDistance(int antID)
{
	return this->colony[antID].distance;
}

void AntColony::globalUpdate(int antID, double pathLenght, int xNumberOfPoints, double alpha, double tau_0, double evaporationFactor)
{	

	int* path = new int[xNumberOfPoints];
	double tempPheromone = 0;

	for (int i = 0; i < xNumberOfPoints; i++)
	{
		for (int j=0; j < xNumberOfPoints; j++)
		{
			this->pheromoneMatrix[i][j] = this->pheromoneMatrix[i][j] * (1 - evaporationFactor);
		}
		
	}
	
	
	for (int i = 0; i < numberOfAnts; i++)
	{
		//path = new int[xNumberOfPoints];
		tempPheromone = 0;

		for (int j = 0; j < xNumberOfPoints; j++)
		{
			//std::cout<<i<<":"<<this->colony[antID].getAntPath(i)<<"  ";

			path[this->colony[i].getAntPath(j) - 1] = j;
		}

		path[0] = this->colony[i].startPointID;


		for (int j = 1; j < xNumberOfPoints; j++)
		{
			tempPheromone = 1/this->colony[i].distance;
			this->pheromoneMatrix[path[j - 1]][path[j]] += tempPheromone;
			this->pheromoneMatrix[path[j]][path[j - 1]] += tempPheromone;
		}

		//delete[] path;
	}
	
	//delete[] path;
	
	///OLD-Method
	
	//std::cout << "\n\nStartPoint: "<<this->colony[antID].startPointID<<" Kolejnosc: ";
	/*for (int i = 0; i < xNumberOfPoints; i++)
	{
		//std::cout<<i<<":"<<this->colony[antID].getAntPath(i)<<"  ";
		
		path[this->colony[antID].getAntPath(i) - 1] = i;
	}

	path[0] = this->colony[antID].startPointID;*/

	/*std::cout << "\n\nKroki: ";
	for (int i = 0; i < xNumberOfPoints; i++)
	{
		std::cout << path[i] << " ";
	}*/
	/*
	for (int i = 1; i < xNumberOfPoints; i++)
	{
		tempPheromone = ((1 - alpha) * this->getPheromone(path[i - 1], path[i])) + (alpha * tau_0);
		this->pheromoneMatrix[path[i - 1]][path[i]] = tempPheromone;
		this->pheromoneMatrix[path[i]][path[i - 1]] = tempPheromone;
	}
	*/
}

void AntColony::cleaning(int xNumberOfPoints)
{
	for (int i = 0; i < this->getNumberOfAnts(); i++)
	{
		this->colony[i].currentStage = 0;
		this->colony[i].distance = 0;

		for (int j = 0; j < xNumberOfPoints; j++)
		{
			this->colony[i].antPath[j] = 0;
		}

		this->colony[i].currentStage = 1;
		this->colony[i].antPath[this->colony[i].currentPositionID] = this->colony[i].currentStage;

	}

}