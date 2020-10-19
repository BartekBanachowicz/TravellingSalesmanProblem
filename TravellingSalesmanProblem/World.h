#pragma once
class World
{

public:
	World(int xNumberOfPoints);
	void generator();
	void greedyPathFinder();
	int** pathWeights;

private:
	int numberOfPoints;
	
};

