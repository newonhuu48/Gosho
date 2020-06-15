#ifndef H_POINT_H
#define H_POINT_H
#include "element.h"

class Point : public Element
{
protected:
	double x, y, z;
public:

	Point();
	Point(double, double, double);
	Point(Point&);

	//Getters
	double getX();
	double getY();
	double getZ();

	void setX(double);
	void setY(double);
	void setZ(double);

	friend bool operator ==(Point&, Point&);
	friend std::ostream& operator <<(std::ostream&, Point);
	friend std::istream& operator >>(std::istream&, Point);

};

#endif