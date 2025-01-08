#include <iostream>
#include <ostream>
#include <cmath>
#include "Circle.h"


using namespace std;

double Circle :: area () const {

	return (M_PI * pow (radius,2));

}

double Circle :: perimeter () const {

	return (2 * M_PI * radius);

}

void Circle :: translate (double incX, double incY) {

	center.x += incX;
	center.y += incY;

}

void Circle :: print () {
	cout << *this;
}

Circle :: Circle () { 
	
	center = Point2D (0,0);
	radius = 1.0;

}

Circle :: Circle (string color, Point2D center, double radius) {

	set_color (color);
	this -> center = center;
	this -> radius = radius;

}

Point2D Circle :: get_center () const {

	return center;

}

void Circle :: set_center (Point2D p) {

	center = p;

}

double Circle :: get_radius () const {

	return radius;

}

void Circle :: set_radius (double r) {

	radius = r;

}

ostream& operator << (ostream &out, const Circle &c) {

	out << "[Circle: color = " << c.color << "; center = (" 
		<< c.center.x << ", " << c.center.y << "); radius = " 
		<< c.radius << "]";

	return out;

}

