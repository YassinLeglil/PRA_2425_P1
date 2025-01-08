#include <ostream>
#include <iostream>
#include <cmath>
#include "Point2D.h"

using namespace std;

Point2D::Point2D (double x, double y) {
	
	this -> x = x;
	this -> y = y;
}


double Point2D::distance (const Point2D &a, const Point2D &b) { //Calcula la distancia euclidiana entre dos puntos
	
	return sqrt (pow((a.x - b.x),2) + pow((a.y - b.y),2));

}

bool operator==(const Point2D &a, const Point2D &b) { //Sobrecarga global del operador ==
	
	return (a.x == b.x && a.y == b.y);

}

bool operator!=(const Point2D &a, const Point2D &b) { //Sobrecarga global del operador !=
								
	return (a.x != b.x || a.y != b.y);

}


ostream& operator<<(ostream &out, const Point2D &p) { //Sobrecarga global del operador <<
								  
	out << "(" << p.x << "," << p.y << ")";
	return out;

}

