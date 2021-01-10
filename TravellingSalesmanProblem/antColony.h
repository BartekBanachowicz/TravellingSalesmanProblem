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
	int decisionMaking(int antID, int xNumberOfPoints, Point* pointsMatrix, int beta, int q0);
	double getPheromone(int x, int y);
	int getNumberOfAnts();
	void makeMove(int antID, int xNumberOfPoints, Point* pointsMatrix, int beta, int q0);
	double getDistance(int antID);
	void globalUpdate(int antID, double pathLenght, int xNumberOfPoints, double alpha, double tau_0, double evaporationFactor);
	void cleaning(int xNumberOfPoints);

};