#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>
#include <iostream>

using namespace std;

class Point2D {
	
	public :

		//Atributos
		double x;  //Coordenada x
		double y;  //Coordenada y

		//Nétodos
		Point2D (double x = 0 , double y = 0); //Método constructor. Por defecto los ejes tomarán el valor 0.
		static double distance (const Point2D &a , const Point2D &b); //Calcula la distancia euclidiana entre dos puntos a y b.
		friend bool operator == (const Point2D &a, const Point2D &b); //Sobrecarga global del operador ==
		friend bool operator != (const Point2D &a, const Point2D &b); //Sobrecarga global del operador !=
		friend ostream& operator << (ostream &out, const Point2D &p); //Sobrecarga global del operador <<
			

};

#endif
