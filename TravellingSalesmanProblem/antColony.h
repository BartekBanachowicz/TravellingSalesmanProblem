#pragma once
#include"ant.h"
#include<cstdlib>
#include<iostream>
#include<vector>
#include<math.h>
#include<cstdlib>

class AntColony : public Ant
{

	int numberOfAnts;
	std::vector<Ant> colony;
	double** pheromoneMatrix;

public:

	AntColony(int xNumberOfAnts, int xNumberOfPoints);
	void antsSpawning(int xNumberOfPoints, Point* pointsMatrix);
	int decisionMaking(int antID, int xNumberOfPoints, Point* pointsMatrix, double** distanceMatrix, int alpha, int beta);
	double getPheromone(int x, int y);
	int getNumberOfAnts();
	void makeMove(int antID, int xNumberOfPoints, Point* pointsMatrix, double** distanceMatrix, int alpha, int beta);
	double getDistance(int antID);
	void globalUpdate(int antID, double pathLenght, int xNumberOfPoints, double pheromoneEvaporation, double pheromoneSprayingFactor);
	void cleaning(int xNumberOfPoints);
	int getAntIndexSum(int antIndex);
	int getStartIndex(int antID);
	int getCurrentIndex(int antID);
	int getAntPath(int antID, int pointID);
	void antCleaning();
};