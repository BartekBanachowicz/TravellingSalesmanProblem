#pragma once
#include"Point.h"
#include<iostream>

class Ant
{
	
public:
	Ant();
	Ant(int xNumberOfPoints);
	Point* currentPosition;
	void move(Point* newPlace, int newPlaceID, double** pheromoneMatrix);
	int* antPath;
	int currentStage = 1;
	int currentPositionID;
	int getAntPath(int ID);

};