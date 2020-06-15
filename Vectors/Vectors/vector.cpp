#include "vector.h"

Vector::Vector() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}


Vector::Vector(Point& p1, Point& p2) {
	this->x = p2.getX() - p1.getX();
	this->y = p2.getY() - p1.getY();
	this->z = p2.getZ() - p1.getZ();
}

Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}


Vector::Vector(const Vector& v2) {
	Vector& v1 = *this;

	v1.x = v2.x;
	v1.y = v2.y;
	v1.z = v2.z;
}



//Operations
//Addition
Vector Vector::operator +(const Vector& v3) {
	Vector v1;
	Vector& v2 = *this;

	v1.x = v2.x + v3.x;
	v1.y = v2.y + v3.y;
	v1.z = v2.z + v3.z;

	return v1;
}

//Substraction
Vector Vector::operator -(const Vector& v3) {
	Vector v1;
	Vector& v2 = *this;

	v1.x = v2.x - v3.x;
	v1.y = v2.y - v3.y;
	v1.z = v2.z - v3.z;

	return v1;
}



//Scalar multiplication
Vector Vector::operator *(double a) {
	double x = this->x * a;
	double y = this->y * a;
	double z = this->z * a;

	return Vector(x, y, z);
}


//Dot product
double Vector::operator *(const Vector& v2)
{
	Vector& v1 = *this;
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}


//Cross product
Vector Vector::operator ^(const Vector& v2)
{
	Vector& v1 = *this;

	double x = v1.y * v2.z - v1.z * v2.y;
	double y = v1.z * v2.x - v1.x * v2.z;
	double z = v1.x * v2.y - v1.y * v2.x;

	return Vector(x, y, z);
}


//Mixed product
double Vector::operator()(Vector& v2, Vector& v3) {
	Vector& v1 = *this;

	return v1 * (v2 ^ v3);
}



//Methods
double Vector::length() {
	return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}



Vector Vector::getDirection() {
	Vector& v1 = *this;
	double len = v1.length();

	if (!len) {
		throw VLE();
	}

	double x = v1.x / len;
	double y = v1.y / len;
	double z = v1.z / len;

	return Vector(x, y, z);
}

bool Vector::isNull() {
	Vector& v1 = *this;

	return (x == 0) && (y == 0) && (z == 0);
	//return (v1.getX() == v1.getY() == v1.getZ() == 0);
}


bool Vector::paralellismCheck(Vector& v2) {
	Vector& v1 = *this;

	if ( (!v1.length()) || (!v2.length()) ) {
		throw VLE();
	}

	return ((v1.x / v2.x) == (v1.y / v2.y) == (v1.z / v2.z));
}

bool Vector::ortogonalityCheck(Vector& v2) {
	Vector& v1 = *this;

	if ( (v1.isNull()) || (v2.isNull()) ) {
		throw VLE();
	}

	return (v1 * v2) == 0;
}


std::ostream& operator <<(std::ostream& out, const Vector& v1) {
	out << '(' << v1.x << ',' << v1.y << ',' << v1.z << ')';
	return out;
}