#include "Square.h"

bool Square :: check (Point2D* vertices) {

	double lado1 = Point2D :: distance (vertices [0], vertices [1]);
       	double lado2 = Point2D :: distance (vertices [1], vertices [2]);
	double lado3 = Point2D :: distance (vertices [2], vertices [3]);
	double lado4 = Point2D :: distance (vertices [3], vertices [0]);

	return (lado1 == lado2 && lado3 == lado4 & lado1 == lado3);

}

Square :: Square () {

	vs = new Point2D [N_VERTICES] { Point2D(-1.0, 1.0),
                Point2D( 1.0, 1.0),
                Point2D( 1.0,-1.0),
                Point2D(-1.0,-1.0)};

}

Square :: Square (string color, Point2D* vertices) {

	if (!check (vertices)) {

			throw invalid_argument ("Número de vertices no válido");

	}

	set_color (color);
	
	vs = new Point2D[N_VERTICES]{
		vertices[0],
		vertices[1],
		vertices[2],
		vertices[3]};

}

void Square :: set_vertices (Point2D* vertices) {

	if (!check (vertices)) {

		throw invalid_argument ("Número de vertices no válido");
	
	}

	for (int i = 0 ; i < N_VERTICES ; i ++) {

		vs [i] = vertices [i];

	}

}

ostream& operator << (ostream &out, const Square &square) {

  	out << "[Square: color = " << square.color << "; v0 = " << square[0] << "; v1 = " << square[1]
     	<< "; v2 = " << square[2] << "; v3 = " << square[3] << "]";

        return out;
}

double Square :: area () const {


        double lado1 = Point2D :: distance (vs [0], vs [1]);
        double lado3 = Point2D :: distance (vs[1], vs[2]);

        return (lado1 * lado3);

}

double Square :: perimeter () const {

        double lado1 = Point2D::distance(vs[0], vs[1]);
        double lado2 = Point2D::distance(vs[2], vs[3]);
        double lado3 = Point2D::distance(vs[1], vs[2]);
        double lado4 = Point2D::distance(vs[3], vs[0]);

        return lado1 + lado2 + lado3 + lado4;

}

void Square :: translate (double incX, double incY) {


        for (int i = 0; i < 4; i ++) {

                vs[i].x = vs[i].x + incX;
                vs[i].y = vs[i].y + incY;

        }

}

void Square :: print () {

	cout << *this;

}
