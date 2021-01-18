#include"World.h"

void World::generator()
{
	srand(time(0));
	int tempX, tempY;
	double tempDist = 0.0;
	std::ofstream outputFile;
	std::string outputFileNameS;

	std::cout << "Provide output file name:" << std::endl;
	std::cin >> outputFileNameS;
	
	outputFile.open(outputFileNameS);
	outputFile << numberOfPoints << std::endl;

	this->createPointsMatrix();

	for (int i = 0; i < this->numberOfPoints; i++)
	{
		tempX = rand() % 500;
		tempY = rand() % 500;
		this->pointsMatrix[i].setCoordinates(tempX, tempY);
		this->indexSum += i;

		outputFile << i+1 << " " << tempX << " " << tempY << std::endl;
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

	outputFile.close();
}