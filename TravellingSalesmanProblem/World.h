#pragma once
class World
{

public:
	World(int xNumberOfPoints);
	void generator();
	void greedyPathFinder();

private:
	int numberOfPoints;
	double** pathWeights;
};

