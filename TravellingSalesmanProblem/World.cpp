#include "World.h"
#include "Point.h"


World::World(int xNumberOfPoints)
{
	this->numberOfPoints = xNumberOfPoints;
	pathWeights = new int* [numberOfPoints];

	for (int i = 0; i < numberOfPoints; i++)
	{
			pathWeights[i] = new int[numberOfPoints];
	}

	this->generator();
}
