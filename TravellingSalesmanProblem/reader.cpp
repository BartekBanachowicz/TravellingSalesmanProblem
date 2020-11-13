#include "World.h"

void World::reader(std::string fileName)
{
	int tempNumberOfPoints, xID, xX, xY;
	
	std::ifstream inputFile;
	inputFile.open(fileName);

	inputFile >> tempNumberOfPoints;
	this->numberOfPoints = tempNumberOfPoints;
	this->createPointsMatrix();

	while (!inputFile.eof())
	{
		inputFile >> xID >> xX >> xY;
		this->pointsMatrix[xID - 1].setCoordinates(xX, xY);
	}

	inputFile.close();
}