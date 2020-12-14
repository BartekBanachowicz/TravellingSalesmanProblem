#include"ant.h"
#include<iostream>

Ant::Ant(int xNumberOfPoints)
{
	currentPosition = nullptr;
	currentPositionID = -2;
	antPath = new int[xNumberOfPoints];
	for (int i = 0; i < xNumberOfPoints; i++)
	{
		antPath[i] = 0;
		//std::cout << i << " ";
	}
}

Ant::Ant()
{
	currentPosition = nullptr;
}

void Ant::move(Point* newPlace, int newPlaceID, double** pheromoneMatrix)
{
	double Tau0 = 1.0;
	double alpha = 0.1;
	double newPheromone;

	this->currentPosition = newPlace;
	this->currentStage++;
	this->antPath[newPlaceID] = this->currentStage;
	

	newPheromone = ((1 - alpha) * pheromoneMatrix[this->currentPositionID][newPlaceID]) + (alpha * Tau0);
	pheromoneMatrix[this->currentPositionID][newPlaceID] = newPheromone;
	pheromoneMatrix[newPlaceID][this->currentPositionID] = newPheromone;


	this->currentPositionID = newPlaceID;
}

int Ant::getAntPath(int ID)
{
	//std::cout<<"Done\n";
	return this->antPath[ID];
}