#pragma once
class Point
{
private:

	int x;
	int y;

public:
	void setCoordinates(int xX, int yY);
	double p2pDistance(Point A);

	Point();
	Point(int xX, int yY);
	~Point();
};

