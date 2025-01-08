#include <cmath>
#include "Rectangle.h"

using namespace std;

bool Rectangle :: check (Point2D* vertices) {

	//Conseguimos las distancias entre cada lado
	
	double lado1 = Point2D :: distance (vertices [0], vertices [1]);
	double lado2 = Point2D :: distance (vertices [2], vertices [3]);
	double lado3 = Point2D :: distance (vertices[1], vertices[2]);
	double lado4 = Point2D :: distance (vertices[3], vertices[0]);

	return lado1 == lado2 && lado3 == lado4;

}


Rectangle :: Rectangle () {

	vs = new Point2D [N_VERTICES] { Point2D(-1.0, 0.5), 
		Point2D( 1.0, 0.5),
		Point2D( 1.0,-0.5),
		Point2D(-1.0,-0.5)};

}

Rectangle :: Rectangle (string color, Point2D* vertices) {
	
	if (check (vertices)) {
		vs = vertices;
		set_color (color);
	
	} else {
		
		throw invalid_argument ("Vertices no validos");

	}

}

Rectangle :: Rectangle (const Rectangle &r) {

	vs = new Point2D[N_VERTICES]{
		r.vs[0],
		r.vs[1],
		r.vs[2],
		r.vs[3]
	};

	set_color (r.color);

}

Rectangle :: ~Rectangle() {

	delete [] vs;

}

Point2D Rectangle :: get_vertex (int ind) const {

	if (ind < 0 || ind > N_VERTICES) {

		throw out_of_range ("Indice fuera del intervalo");

	}

	return vs [ind];

}

Point2D Rectangle :: operator [] (int ind) const{ 

	if (ind < 0 || ind > N_VERTICES - 1) {

		throw out_of_range ("Indice fuera del intervalo");

	}

	return get_vertex (ind);

}

void Rectangle :: set_vertices (Point2D* vertices) {
	
	if (!check (vertices)) {

		throw invalid_argument ("Vertices no validos");

	}

	for (int i = 0 ; i < 4 ; i ++) {

		vs [i] = vertices [i];

	}

} 

Rectangle& Rectangle::operator=(const Rectangle &r) {
    // Copiar los datos de r a this
	for(int i=0; i< N_VERTICES; i++){
		vs[i] = r.vs[i];
	}
	set_color(r.color);
	return *this;  
}

ostream& operator << (ostream &out, const Rectangle &r) {

		out << "[Rectangle: color = " << r.color << "; v0 = " << r[0] << "; v1 = " << r[1]
		<< "; v2 = " << r[2] << "; v3 = " << r[3];

	return out;
}

double Rectangle :: area () const { 
	
	                                                                              
        double lado1 = Point2D :: distance (vs [0], vs [1]);                                
       	double lado3 = Point2D :: distance (vs[1], vs[2]);

	return (lado1 * lado3);

}

double Rectangle :: perimeter () const {

	double lado1 = Point2D::distance(vs[0], vs[1]);
	double lado2 = Point2D::distance(vs[2], vs[3]);
	double lado3 = Point2D::distance(vs[1], vs[2]);
	double lado4 = Point2D::distance(vs[3], vs[0]);

	return lado1 + lado2 + lado3 + lado4;

}

void Rectangle :: translate (double incX, double incY) {


        for (int i = 0; i < 4; i ++) {

		vs[i].x = vs[i].x + incX;
		vs[i].y = vs[i].y + incY;

	}

}

void Rectangle :: print () {

	cout << *this;

}





