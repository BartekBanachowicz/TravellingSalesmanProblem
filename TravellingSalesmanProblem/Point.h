#pragma once
class Point
{
private:

	double x;
	double y;

public:
	int pointID;
	void setCoordinates(double xX, double yY);
	double p2pDistance(Point A);

	Point(int xPointID, double xX, double yY);

};

