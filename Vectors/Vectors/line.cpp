#include "line.h"

Line::Line() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Line::Line(Point& p1, Point& p2) {
    this->p1 = p1;
    this->p2 = p2;

    this->v1.setX(p2.getX() - p1.getX());
    this->v1.setY(p2.getY() - p1.getY());
    this->v1.setX(p2.getZ() - p1.getZ());

}

Line::Line(Point& p1, Vector& v1) {
    this->p1 = p1;
    this->p2 = Point(p1.getX() + v1.getX(), p1.getY() + v1.getY(), p1.getZ() + v1.getZ());

    this->v1 = v1;
}

Line::Line(Line& l2) {
    Line& l1 = *this;
    Point& p1 = l2.getP1();
    Point& p2 = l2.getP2();

    l1.setP1(p1);
    l1.setP2(p2);
}



//Getters and setters
Point& Line::getP1() {
    return this->p1;
}

Point& Line::getP2() {
    return this->p2;
}

Vector& Line::getV1() {
    return this->v1;
}


void Line::setP1(Point& p1) {
    this->p1 = p1;
}

void Line::setP2(Point& p2) {
    this->p2 = p2;
}

void Line::setV1(Vector& v1) {
    this->v1 = v1;
}



//===============
//===============
//  Operations
//===============
//===============
bool Line::operator +(Point& p) {
    Line& l = *this;
    double x = l.getP1().getX();
    double y = l.getP1().getY();
    double z = l.getP1().getZ();

    Point first = l.getP1();
    double x1 = first.getX();
    double y1 = first.getY();
    double z1 = first.getZ();

    Point second = l.getP2();
    double x2 = second.getX();
    double y2 = second.getY();
    double z2 = second.getZ();

    double AB = sqrt(pow((x2 - x1), 2) +
        pow((y2 - y1), 2) +
        pow((z2 - z1), 2));

    double AP = sqrt(pow((x - x1), 2) +
        pow((y - y1), 2) +
        pow((z - z1), 2));

    double PB = sqrt(pow((x2 - x), 2) +
        pow((y2 - y), 2) +
        pow((z2 - z), 2));
    if (AB == AP + PB)
    {
        return true;
    }
    else {
        return false;
    }
}

bool Line::operator ||(Line& l2) {
    Line& l1 = *this;
    if (l1.lineParCheck(l2)) return true;
    else return false;
}

bool Line::operator ==(Line& l2) {
    Line& l1 = *this;

    Vector dir_vec_1 = l1.getV1();
    double dir_vec_x1 = dir_vec_1.getX();
    double dir_vec_y1 = dir_vec_1.getY();
    double dir_vec_z1 = dir_vec_1.getZ();
    Vector dir_vec_2 = l1.getV1();
    double dir_vec_x2 = dir_vec_2.getX();
    double dir_vec_y2 = dir_vec_2.getY();
    double dir_vec_z2 = dir_vec_2.getZ();
    double x1 = l1.getX();
    double y1 = l1.getY();
    double z1 = l1.getZ();
    double x2 = l2.getX();
    double y2 = l2.getY();
    double z2 = l2.getZ();

    if ((dir_vec_x1 / dir_vec_x2) == (dir_vec_y1 / dir_vec_y2) == (dir_vec_z1 / dir_vec_z2) &&
        ((x1 == x2) || (y1 == y2) || (z1 == z2)))
    {
        return true;
    }
    else {
        return false;
    }
}

bool Line::operator &&(Line& l2) {
    Line& l1 = *this;

    double x1 = l1.getX();
    double y1 = l1.getY();
    double z1 = l1.getZ();
    double x2 = l2.getX();
    double y2 = l2.getY();
    double z2 = l2.getZ();
    if ((x1 == x2) || (y1 == y2) || (z1 == z2))return true;
    else return false;
}

bool Line::operator !=(Line& l2) {
    Line& l1 = *this;

    Point first = l2.getP1();
    double x1 = first.getX();
    double y1 = first.getY();
    double z1 = first.getZ();

    Point second = l2.getP2();
    double x2 = second.getX();
    double y2 = second.getY();
    double z2 = second.getZ();

    Vector dirVec1 = l1.getV1();
    double dirVec1X = dirVec1.getX();
    double dirVec1Y = dirVec1.getY();
    double dirVec1Z = dirVec1.getZ();

    Vector dirVec2 = l2.getV1();
    double dirVec2X = dirVec2.getX();
    double dirVec2Y = dirVec2.getY();
    double dirVec2Z = dirVec2.getZ();

    double det = (x2 - x1) * ((dirVec1Y * dirVec2Z) - (dirVec1Z * dirVec2Y)) -
        (y2 - y1) * ((dirVec1X * dirVec2Z) - (dirVec1Z * dirVec2X)) -
        (z2 - z1) * ((dirVec1Z * dirVec2Z) - (dirVec1Z * dirVec2Z));
    if (det != 0) return true;
    else return false;
}

bool Line::operator |(Line& l2) {
    Line l1 = *this;
    Vector dirVec1 = l1.getV1();
    double dirVec1X = dirVec1.getX();
    double dirVec1Y = dirVec1.getY();
    double dirVec1Z = dirVec1.getZ();

    Vector dirVec2 = l2.getV1();
    double dirVec2X = dirVec2.getX();
    double dirVec2Y = dirVec2.getY();
    double dirVec2Z = dirVec2.getZ();
    double dot_equation = (dirVec1X * dirVec2X) + (dirVec1Y * dirVec2Y) + (dirVec1Z * dirVec2Z);
    if (dot_equation == 0)return true;
    else return false;
}



//===============
//===============
//    Methods
//===============
//===============

Vector Line::normalVector() {
    Line& l1 = *this;
    Vector dir_vec_1 = l1.getV1();
    double l = dir_vec_1.getX();
    double m = dir_vec_1.getY();
    double n = dir_vec_1.getZ();
    Point first = l1.getP1();
    double x1 = first.getX();
    double y1 = first.getY();
    double z1 = first.getZ();
    double k = -(l * x1 + m * y1 + n * z1) / (pow(l, 2) + pow(m, 2) + pow(n, 2));
    double nmvX = (l * k) + x1;
    double nmvY = (m * k) + y1;
    double nmvZ = (n * k) + z1;
    Vector nmv(nmvX, nmvY, nmvZ);
    return nmv;
}

double Line::angle(Line& l2) {
    Line& l1 = *this;

    Vector dir_vec_1 = l1.getV1();
    double dir_vec_x1 = dir_vec_1.getX();
    double dir_vec_y1 = dir_vec_1.getY();
    double dir_vec_z1 = dir_vec_1.getZ();
    Vector dir_vec_2 = l2.getV1();
    double dir_vec_x2 = dir_vec_2.getX();
    double dir_vec_y2 = dir_vec_2.getY();
    double dir_vec_z2 = dir_vec_2.getZ();

    double cosOfAngle = ((dir_vec_x1 * dir_vec_x2) + (dir_vec_y1 * dir_vec_y2) + (dir_vec_z1 * dir_vec_z2)) / sqrt(pow(dir_vec_x1, 2) + pow(dir_vec_y1, 2) + pow(dir_vec_z1, 2)) * sqrt(pow(dir_vec_x2, 2) + pow(dir_vec_y2, 2) + pow(dir_vec_z2, 2));
    double angleRad = acos(cosOfAngle) * 180.0 / PI;
    return angleRad;
}

bool Line::lineParCheck(Line& l2) {
    Line& l1 = *this;
    if (((l1.x / l2.x) == (l1.y / l2.y) == (l1.z / l2.z))) return true;
    else return false;
}

std::ostream& operator <<(std::ostream& out, Line& l1) {
    out << "First point: " << l1.getP1() << " | Second point: " << l1.getP2();

    return out;
}