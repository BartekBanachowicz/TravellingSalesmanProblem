#include"ant.h"

Ant::Ant(int xNumberOfPoints)
{
	currentPosition = nullptr;
	antPath = new int[xNumberOfPoints];
	for (int i = 0; i < xNumberOfPoints; i++)
	{
		antPath[i] = 0;
	}
}

Ant::Ant()
{
	currentPosition = nullptr;
}

void Ant::move(Point* newPlace, int newPlaceID)
{
	this->currentPosition = newPlace;
	this->currentStage++;
	this->antPath[newPlaceID] = this->currentStage;
}