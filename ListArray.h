#include <ostream>
#include "List.h"
#include <iostream>
using namespace std;

//Implementará la estructura de datos lista mediante una representación de secuencias de memoria contigua con arrays
template <typename T> class ListArray : public List <T> {
	private :
		T* arr; //Puntero al inicio del array que almacenará los elementos de la lista.
		int max; //Tamaño actual del array.
		int n; //Número de elementos que contiene la lista
		static const int MINSIZE = 2; //Tamaño mínimo del array. Deberá inicializarse a 2.
		 void resize (int new_size) {
			 //Se encarga de redimensionar el array al tamaño especificado.
			 //Crea un nuevo array dinámico de new_size elementos
			 T* new_array = new T[new_size];

			 //Copia el contenido del array actual en el nuevo
			 
			 for (int i = 0 ; i < min (max, new_size) ; i++) {
				 new_array [i] = arr [i];
			 }

			 //Se liberan los recursos de memoria que ocupa arr

			 delete [] arr;
			
			 //Actualiza el puntero arr para que apunte a la dirección de memoria de new_array

			 arr = new_array;

			 //Actualizamos max

			 max = new_size;
		}




	
	public :
		//Metodos de List <T>
		void insert (int pos, T e) {
			//Lanza una excepción si pos no esta en el intervalo
			if (pos < 0 || pos > size()) {
				throw out_of_range ("Posición fuera del intervalo");
			}

			//Si el tamaño del arreglo es igual o menor que el número de elementos
			if (size() >= max) {
				resize (max * 2);
			}
			
			if (pos == n) {
				arr [pos] = e;
			} else {
				for (int i = n; i >= pos; i--) {
					arr[i] = arr [i - 1];
				}
			}

			arr[pos] = e;
			n++;
		}

		void append (T e) {
			arr[n] = e;
			n++;
		}

		void prepend (T e) {
			insert (0, e);
		}

		T remove (int pos) {
			if (pos < 0 || pos > size()) {
				throw out_of_range ("Posición no válida, fuera del intervalo");
			}
			//Guardamos el elemento de arr [pos]
			T guarda = arr[pos];
			//Eliminamos el elemento
			for (int i = pos; i < n - 1; i++) {
				arr [i] = arr [i + 1];
			}

			n--;
			//Devolvemos el valor que hemos eliminado 
			return guarda;
		}

		T get (int pos) {
			if (pos < 0 || pos > size()) {
				 throw out_of_range ("Posición no válida, fuera del intervalo");
			} else {
				return arr[pos];
			}
		}

		int search (T e) {
		//Recorrerá todo el array hasta encontrar la ocurrencia
			for (int i = 0 ; i <= n ; i++) {
				if (arr[i] == e) {
					return i;
				}
			}
		//Si lo ha recorrido entero y no la ha encontrado dará -1

			return -1;
		}

		bool empty () {
		//Devolverá true si esta vacio
			return size() == 0;
		}

		int size () {
			return n;
		}
		//Métodos de ListArray
		ListArray () {
		       	//Método constructor
			arr = new T [MINSIZE];
			max = MINSIZE;
			n = 0;
		}

		~ListArray () {
		       	//Método destructor
			delete [] arr;
		}

		T operator [] (int pos) {
		       	//Sobrecarga del operador []. Devuelve el elemento situado en la posicion pos.
			return get (pos);
		}

		friend ostream& operator<<(ostream &out, const ListArray<T> &list) {
		       	//Sobrecarga del operador << 
			out << " List => [" << endl;
			//Hasta que haya escrito el array entero
			for (int i = 0; i < list.n; i++) {
				out <<"\n" << "  " << list.arr[i] << endl ;
			}

			out << "\n" << "]" << endl;
			return out;
		}
};
		





