#ifndef SQUARE_H
#define SQUARE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"
#include <ostream>
#include "Rectangle.h"

using namespace std;

class Square : public Rectangle {

	private :

		static bool check (Point2D* vertices); //Comprobara los vertices

	public :

		Square (); //Metodo constructor por defecto

		Square (string color, Point2D* vertices); //Metodo constructor

		void set_vertices (Point2D* vertices) override; //Pondrá los vertices nuevos

		friend ostream& operator << (ostream &out, const Square &square); //Sobrecarga global del operador <<
		
                double area () const override;

                double perimeter () const override ;

                void translate (double incX, double incY) override;

		void print () override;

};

#endif
