#include "segment.h"

Segment::Segment() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Segment::Segment(Point& pt1, Point pt2) {
    p1 = pt1;
    p2 = pt2;
}

Segment::Segment(Segment& s1, Segment& s2) {
    this->p1 = s2.p1;
    this->p2 = s2.p2;
    this->v1 = s2.v1;
}


Segment::Segment(Point& pt1, Vector& vect1, double it1, double it2) {
    if (t1 < 0 || t2 > 1) { throw SIE(); }
    t1 = it1;
    t2 = it2;
    p1.setX(pt1.getX() + vect1.getX() * t1);
    p1.setY(pt1.getY() + vect1.getY() * t1);
    p1.setZ(pt1.getZ() + vect1.getZ() * t1);

    p2.setX(pt1.getX() + vect1.getX() * t2);
    p2.setY(pt1.getY() + vect1.getY() * t2);
    p2.setZ(pt1.getZ() + vect1.getZ() * t2);
}

//Getters and setters
Vector& Segment::getV1() {
    return this->v1;
}


Point& Segment::getP1() {
    return this->p1;
}

Point& Segment::getP2() {
    return this->p2;
}

double Segment::getT1() {
    return this->t1;
}

double Segment::getT2() {
    return this->t2;
}



void Segment::setV1(Vector& v1) {
    this->v1 = v1;
}


void Segment::setP1(Point& p1) {
    this->p1 = p1;
}

void Segment::setP2(Point& p2) {
    this->v1 = v1;
}


void Segment::setT1(double t1) {
    this->t1 = t1;
}

void Segment::setT2(double t2) {
    this->t2 = t2;
}




//Segment length
double Segment::segLen() {
    return sqrt(pow((p1.getZ() - p2.getZ()), 2)
        + pow((p1.getX() - p2.getX()), 2)
        + pow((p1.getY() - p2.getY()), 2));
}


//Segment middle
Point Segment::segMid() {
    Point ptMid;
    ptMid.setX((p2.getX() + p1.getX()) / 2);
    ptMid.setY((p2.getY() + p1.getY()) / 2);
    ptMid.setZ((p2.getZ() + p1.getZ()) / 2);
    return ptMid;
}

//Operators
bool Segment::operator ==(const Point& pC) {
    Segment AC(p1, pC);
    Segment BC(p2, pC);
    return segLen() == AC.segLen() + BC.segLen();
}

double Segment::operator *(Segment& s2)
{
    Segment& s1 = *this;
    return ((s1.p1 * s2.p1) + (s1.p2 * s2.p2));
}

std::ostream& operator <<(std::ostream& out, const Segment& s1) {
    out << '(' << s1.p1.getX() << ',' << s1.p1.getY() << ',' << s1.p1.getZ() <<
        "),(" << s1.p2.x << ',' << s1.p2.y << ',' << s1.p2.getZ() << "),["
        << s1.t1 << ',' << s1.t2 << ']';
    return out;
}

std::istream& operator >>(std::istream& input, Segment& s) {
    input >> s.p1 >> s.p2 >> s.t1 >> s.t2;
    return input;
}