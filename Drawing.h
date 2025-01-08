#include "Shape.h"
#include "List.h"

using namespace std;

class Drawing {

	private : 

		List<Shape*>* shapes; //Lista de figuras representadas en el dibujo

	public :

		Drawing (); //Metodo constructor. Reserva memoria dinamica para shape
			    
		~Drawing(); //Metodo destructor. Libera la memoria dinamica reservada por shape

		void add_front (Shape* shape); //Añade la figura shape al frente del dibujo

		void add_back (Shape* shape); //Añade la figura shape al fondo del dibujo

		void print_all (); //Muestra por pantalla informacion de todas las figuras del dibujo

		double get_area_all_circles (); //Devuelve el area ocupada por todos los circulos presentes en el dibujo

		void move_squares (double incX, double incY); //Mueve todos los cuadrados del dibujo, aplicando los inc
	
};
