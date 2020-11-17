#include "Point.h"
#include <math.h>


	
Point::Point(double xX, double yY)
{
	this->x = xX;
	this->y = yY;
	this->visited = false;
}

Point::Point()
{
	this->x = 0;
	this->y = 0;
	this->visited = false;
}

Point::~Point()
{

}

	
void Point::setCoordinates(double xX, double yY)
{
	this->x = xX;
	this->y = yY;
}

double Point::p2pDistance(Point A)
{
	return sqrt(pow(this->x - A.x, 2) + pow(this->y - A.y, 2));
}

void Point::visit()
{
	this->visited = true;
}

void Point::resetVisited()
{
	this->visited = false;
}

bool Point::ifVisited() 
{
	return this->visited;
}

double Point::readCoordinatesX()
{
	return this->x;
}

double Point::readCoordinatesY()
{
	return this->y;
}
