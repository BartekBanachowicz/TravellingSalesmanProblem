#pragma once
class Point
{
private:

	double x;
	double y;
	bool visited;

public:
	void setCoordinates(double xX, double yY);
	double p2pDistance(Point A);
	double readCoordinatesX();
	double readCoordinatesY();
	void visit();
	void resetVisited();
	bool ifVisited();

	Point();
	Point(double xX, double yY);
	~Point();
};

