#include "World.h"
#include "Point.h"


World::World(int xNumberOfPoints)
{
	this->numberOfPoints = xNumberOfPoints;
	this->generator();
}

World::World(std::string fileName)
{
	this->reader(fileName);
}

World::~World()
{

}

void World::createPointsMatrix()
{
	pointsMatrix = new Point[numberOfPoints];
}
