#pragma once
#include"Point.h"

class Ant
{
	
public:
	Ant();
	Ant(int xNumberOfPoints);
	Point* currentPosition;
	void move(Point* newPlace, int newPlaceID);
	int* antPath;
	int currentStage = 1;

};