#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

class Shape {

	protected : 

		string color; //Color de la figura
	
	public : 

		Shape (); //Constructor por defecto, creara una figura color rojo
		Shape (string color); //Crea una figura del color especifico

		string get_color () const; //Devuelve el color de relleno de la figura
		void set_color (string c); //Modifica el color de relleno de la figura

		virtual double area () const = 0; //Metodo virtual puro, calcula el area de una figura
		virtual double perimeter () const = 0; //Metodo virtual puro, calcula el perimetro de una figura
		virtual void translate (double incX, double incY) = 0; //Método virtual puro. Traslada la figura sobre el espacio con los incrementos
		virtual void print () = 0; //Metodo virtual puro, imprimira informacion basica sobre la figura
					   
	
};

#endif



