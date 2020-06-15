#ifndef H_SEGMENT_H
#define H_SEGMENT_H
#include "line.h"

class Segment : public Line
{
    Point p1, p2;
    Vector v1;
    double t1, t2;
    double x, y, z;
public:
    Segment();
    Segment(Point&, Vector&, double, double);
    Segment(Point& pt1, Point pt2);
    Segment(Segment&, Segment&);

    Vector& getV1();
    Point& getP1();
    Point& getP2();

    double getT1();
    double getT2();

    double getX();
    double getY();
    double getZ();


    void setV1(Vector&);
    void setP1(Point&);
    void setP2(Point&);

    void setT1(double);
    void setT2(double);

    void setX(double);
    void setY(double);
    void setZ(double);

    //Operators
    bool operator ==(const Point&);
    double operator *(Segment&);

    //Methods
    double segLen();
    Point segMid();
    bool segPointCheck();
    double shortDistance();
    

    Vector getVect();
    std::istream& ext(std::istream&)const;
    std::ostream& ins(std::ostream&)const;
    
    friend std::ostream& operator <<(std::ostream&, const Segment&);
    friend std::istream& operator >> (std::istream&, Segment&);
};

#endif