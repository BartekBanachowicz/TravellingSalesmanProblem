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

	World(int xNumberOfPoints);
	World(std::string fileName);
	~World();

	void generator();
	void reader(std::string fileName);
	void greedyPathFinder();
	void antPathFinder(int xNumberOfAnts, int xAlpha, int xBeta, double xPheromoneEvaporation, double xPheromoneSprayingFactor);
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

