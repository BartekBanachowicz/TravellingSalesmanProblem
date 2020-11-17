#pragma once
#include"Point.h"
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<fstream>
#include<iostream>

class World
{

public:

	World(int xNumberOfPoints);
	World(std::string fileName);
	~World();

	void generator();
	void reader(std::string fileName);
	void greedyPathFinder();
	void createPointsMatrix();
	void readWorld();

private:
	int numberOfPoints;
	Point* pointsMatrix;

};

