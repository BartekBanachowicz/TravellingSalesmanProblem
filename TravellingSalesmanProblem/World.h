#pragma once
#include"Point.h"
#include"antColony.h"
#include<cstdlib>
#include<ctime>
#include<stdio.h>
#include<fstream>
#include<iostream>
#include <limits>
#include<chrono>

class World
{

public:

	World(int xNumberOfPoints, int locationRange);
	World(std::string fileName);
	~World();

	void generator(int locationRange);
	void reader(std::string fileName);
	void greedyPathFinder();
	void antPathFinder(int xNumberOfAnts, int xAlpha, int xBeta, double xPheromoneEvaporation, double xPheromoneSprayingFactor, int xIterations);
	void createPointsMatrix();
	void readWorld();
	void openOutputFile(std::string fileName);
	void closeOutputFile();
	int readNumberOfPoints();

private:
	int numberOfPoints;
	Point* pointsMatrix;
	int indexSum;
	std::ofstream outputFile;
	double** distanceMatix;

};

