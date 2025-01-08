#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

using namespace std;
class Rectangle : public Shape {

	protected : 

		Point2D* vs; //Puntero a un array de 4 elementos de tipo Point2D que seran los vertices del rectangulo
	
	private : 

		static bool check (Point2D* vertices); //Comprueba si segun esos vertices se conforma un rectangulo
	
	public :

		static int const N_VERTICES = 4; //Constante con el numero de vertices de un rectangulo

		Rectangle (); //Metodo constructor por defecto
		
		Rectangle (string color, Point2D* vertices); //Metodo constructor que recibe los vertices y el color

		Rectangle (const Rectangle &r); //Constructor de copia

		~Rectangle(); //Metodo destructor

		Point2D get_vertex (int ind) const; //Devuelve el Point2D del rectangulo que ocupa el indice ind

		Point2D operator [] (int ind) const; //Sobrecarga del operador []

		virtual void set_vertices (Point2D* vertices); //Metodo virtual que modifica los vertices del rectangulo
							      
		Rectangle& operator=(const Rectangle &r); //Sobrecarga global del operador =
							  
		friend ostream& operator<<(ostream &out, const Rectangle &r); //Sobrecarga global del operador <<

		//Metodos abstractos de shape

                double area () const override;

                double perimeter () const override ;

                void translate (double incX, double incY) override;

                void print () override;

};


#endif
