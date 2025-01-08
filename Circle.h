#include <iostream>
#include <ostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape {

	private : //Atributos
		
		Point2D center; //Centro del circulo
		double radius; //Radio del circulo
	
	public :

		//Metodos abstractos de shape

		double area () const override;

		double perimeter () const override ;

		void translate (double incX, double incY) override;

		void print () override;

		//Funciones de la clase Circle
		
		Circle (); //Metodo constructor por defecto
		Circle (string color, Point2D center, double radius); //Constructor con parametros
		Point2D get_center () const; //Metodo consultro del atributo center
		void set_center (Point2D p); //Metodo modificador del atributo center
		double get_radius () const; //Metodo consultor del atributo radius
		void set_radius (double r); //Metodo modificador del atributo radius

		friend ostream& operator << (ostream &out, const Circle &c); //Sobrecargador global del operador <<

};

