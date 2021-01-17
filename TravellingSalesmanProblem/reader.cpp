#include "World.h"

void World::reader(std::string fileName)
{
	int tempNumberOfPoints, xID;
	double xX, xY;
	
	std::ifstream inputFile;
	inputFile.open(fileName);
	std::cout << "Poprawnie otwarto plik" << std::endl;

	inputFile >> tempNumberOfPoints;
	this->numberOfPoints = tempNumberOfPoints;
	this->createPointsMatrix();

	while (!inputFile.eof())
	{
		inputFile >> xID >> xX >> xY;
		this->pointsMatrix[xID - 1].setCoordinates(xX, xY);
		this->indexSum += (xID - 1);
	}

	std::cout << "Poprawnie wczytano dane z pliku" << std::endl;
	inputFile.close();
}