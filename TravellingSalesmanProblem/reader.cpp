#include "World.h"

void World::reader(std::string fileName)
{
	int tempNumberOfPoints, xID;
	double xX, xY, tempDist=0.0;
	
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

	this->distanceMatix = new double* [this->numberOfPoints];
	for (int i = 0; i < this->numberOfPoints; i++)
	{
		this->distanceMatix[i] = new double[this->numberOfPoints];
	}


	for (int i = 0; i < this->numberOfPoints; i++)
	{
		for (int j = i; j < this->numberOfPoints; j++)
		{
			if (i != j)
			{
				tempDist = this->pointsMatrix[i].p2pDistance(this->pointsMatrix[j]);
				this->distanceMatix[i][j] = tempDist;
				this->distanceMatix[j][i] = tempDist;
			}
		}
	}

	std::cout << "Poprawnie wczytano dane z pliku" << std::endl;
	inputFile.close();
}