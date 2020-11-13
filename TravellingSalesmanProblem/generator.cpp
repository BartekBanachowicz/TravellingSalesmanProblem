#include"World.h"

void World::generator()
{
	srand(time(0));
	int tempX, tempY;
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

		outputFile << i+1 << " " << tempX << " " << " " << tempY << std::endl;
	}

	outputFile.close();
}