#pragma once
#include"ant.h"
#include<cstdlib>
#include<iostream>
#include<vector>

class AntColony : public Ant
{

	int numberOfAnts;
	std::vector<Ant> colony;
	double** pheromoneMatrix;

public:

	AntColony(int xNumberOfAnts, int xNumberOfPoints);
	void antsSpawning(int xNumberOfPoints, Point* pointsMatrix);

};