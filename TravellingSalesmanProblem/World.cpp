#include "World.h"
#include "Point.h"


World::World(int xNumberOfPoints)
{
	this->numberOfPoints = xNumberOfPoints;
	this->generator();
	this->greedyPathFinder();
}

World::World(std::string fileName)
{
	this->reader(fileName);
	std::cout << "Poprawnie utworzono swiat" << std::endl;
	this->readWorld();
	this->greedyPathFinder();
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
