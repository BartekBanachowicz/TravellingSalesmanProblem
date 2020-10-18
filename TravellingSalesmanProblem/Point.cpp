#include "Point.h"
#include <math.h>


	
Point::Point(int xPointID, double xX, double yY)
{
	this->x = xX;
	this->y = yY;
	this->pointID = xPointID;
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
