#pragma once
#include"Point.h"
#include<iostream>

class Ant
{

private:
	int antIndexSum;
	int* antPathByIndex;
	int* antPathInOrder;
	
public:
	Ant();
	Ant(int xNumberOfPoints);
	//~Ant();
	Point* currentPosition;
	void move(Point* newPlace, int newPlaceID, double** pheromoneMatrix);
	void setAntIndexSum(int number);
	int getAntIndexSum();
	int currentStage;
	int currentPositionID;
	int startPointID;
	double distance;
	void setAntPathByIndex(int ID, int number);
	void setAntPathInOrder(int ID, int number);
	int getAntPathByIndex(int ID);
	int getAntPathInOrder(int ID);

};