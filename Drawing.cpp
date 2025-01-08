#include <iostream>

#include "Drawing.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

#include "ListLinked.h"
#include "ListArray.h"

#include "Shape.h"



Drawing :: Drawing () {

	shapes = new ListArray <Shape*>; //Reserva memoria dinamica para shape en una lista shapes

}

Drawing :: ~Drawing() {

	delete shapes; //Libera la memoria dinamica reservada por shapes

}

void Drawing :: add_front (Shape* shape) {

	shapes -> prepend (shape); //Agrega el objeto shape al frente de la lista shapes

}

void Drawing :: add_back (Shape* shape) {

	shapes -> append (shape); //Agrega el objeto shape al fondo de la lista

}

void Drawing :: print_all () {

	cout << "Drawing Contents : " << endl;

	for (int i = 0 ; i < shapes -> size () ; i ++) { //Se recorren todas las figuras

		shapes -> get (i) -> print (); //Se obtiene el elemento de esa posicion y despues se imprime su info

		cout << endl;

	}

}

double Drawing :: get_area_all_circles () {
	
	double suma = 0.0;
	for (int i = 0 ; i < shapes -> size () ; i ++) { //Se recorren todos los elementos del array

		Circle* circlePtr = dynamic_cast <Circle*> (shapes -> get (i)); //Se verifica si el elemento en la posicion i es un objeto de tipo Circle.

		if (circlePtr != nullptr) {

			suma += shapes -> get (i) -> area ();

		}

	}

	return suma;

}

void Drawing :: move_squares (double incX, double incY) {

	for (int i = 0 ; i < shapes -> size () ; i ++) {

		Square* squarePtr = dynamic_cast <Square*> (shapes -> get (i));

		if (squarePtr != nullptr) {

			shapes -> get (i) -> translate (incX, incY); //Con get obtenemos el elemento y con translate lo movemos

		}

	}

}


