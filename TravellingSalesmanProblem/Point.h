#pragma once
class Point
{
private:

	int x;
	int y;
	bool visited;

public:
	void setCoordinates(int xX, int yY);
	double p2pDistance(Point A);
	void visit();
	void resetVisited();
	bool ifVisited();

	Point();
	Point(int xX, int yY);
	~Point();
};

