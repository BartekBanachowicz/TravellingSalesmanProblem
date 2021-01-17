#include"ant.h"
#include<iostream>

Ant::Ant(int xNumberOfPoints)
{
	antIndexSum = 0;
	currentPosition = nullptr;
	antPathByIndex = new int[xNumberOfPoints];
	antPathInOrder = new int[xNumberOfPoints + 1];
	currentStage = 0;
	currentPositionID = -2;
	startPointID = -2;
	distance = 0;
	
	for (int i = 0; i <= xNumberOfPoints; i++)
	{
		if(i < xNumberOfPoints) antPathByIndex[i] = 0;
		antPathInOrder[i] = 0;
	}
}

Ant::Ant()
{
	antIndexSum = 0;
	currentPosition = nullptr;
	currentStage = 0;
	currentPositionID = -2;
	startPointID = -2;
	distance = 0;
	antPathByIndex = nullptr;
	antPathInOrder = nullptr;
}

Ant::~Ant()
{
	/*delete[] antPathByIndex;
	delete[] antPathInOrder;*/
}

void Ant::move(Point* newPlace, int newPlaceID, double** pheromoneMatrix)
{

	this->distance += this->currentPosition->p2pDistance(*newPlace);

	this->currentPosition = newPlace;
	this->currentStage++;
	
	this->currentPositionID = newPlaceID;

	this->antIndexSum += newPlaceID;

	//new
	this->antPathByIndex[newPlaceID] = 1;
	this->antPathInOrder[currentStage] = newPlaceID;
}

void Ant::setAntIndexSum(int number)
{
	this->antIndexSum = number;
}

int Ant::getAntIndexSum()
{
	return this->antIndexSum;
}

void Ant::setAntPathByIndex(int ID, int number)
{
	this->antPathByIndex[ID] = number;
}

void Ant::setAntPathInOrder(int ID, int number)
{
	this->antPathInOrder[ID] = number;
}

int Ant::getAntPathByIndex(int ID)
{
	return this->antPathByIndex[ID];
}

int Ant::getAntPathInOrder(int ID)
{
	return this->antPathInOrder[ID];
}