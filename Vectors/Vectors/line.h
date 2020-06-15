#ifndef H_LINE_H
#define H_LINE_H
#include "vector.h"

class Line : public Vector
{
protected:
	Point p1;
	Point p2;
    Vector v1;
public:
    Line();
    Line(Point&, Vector&);
    Line(Point&, Point&);
    Line(Line&);


    Point& getP1();
    Point& getP2();
    Vector& getV1();

    void setP1(Point&);
    void setP2(Point&);
    void setV1(Vector&);


    //Operations
    bool operator +(Point& p1);
    bool operator ||(Line& l2);
    bool operator ==(Line& l2);
    bool operator &&(Line& l2);
    bool operator !=(Line& l2);
    bool operator |(Line& l2);


    Vector getDirection(Point&, Point&);
    Vector normalVector();

    double angle(Line&);
    bool lineParCheck(Line&);


    friend std::ostream& operator <<(std::ostream&, const Line&);
};

#endif