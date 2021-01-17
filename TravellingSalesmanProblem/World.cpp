#include "World.h"


World::World(int xNumberOfPoints)
{
	this->numberOfPoints = xNumberOfPoints;
	this->indexSum = 0;
	this->generator();
}

World::World(std::string fileName)
{
	this->indexSum = 0;
	this->reader(fileName);
	std::cout << "Poprawnie utworzono swiat" << std::endl;
	this->readWorld();
}

World::~World()
{

}

void World::createPointsMatrix()
{
	pointsMatrix = new Point[numberOfPoints];
}

void World::readWorld()
{
	std::cout << "-----\nIlosc punktow: " << this->numberOfPoints << std::endl;
	for (int i = 0; i < this->numberOfPoints; i++)
	{
		std::cout << i + 1 << " " << this->pointsMatrix[i].readCoordinatesX() << " " << this->pointsMatrix[i].readCoordinatesY() << std::endl;
	}
	std::cout << "-----\n";
}

int World::readNumberOfPoints()
{
	return this->numberOfPoints;
}
