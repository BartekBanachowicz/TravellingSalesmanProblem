#pragma once
#include"Point.h"
#include"antColony.h"
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
	void antPathFinder();
	void createPointsMatrix();
	void readWorld();
	int readNumberOfPoints();

private:
	int numberOfPoints;
	Point* pointsMatrix;

};

