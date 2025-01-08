#include <ostream>
using namespace std;

template <typename T>
class Node {
	public :
		T data = 0; //El elemento almacenado de tipo genérico T  
		Node <T>* next; //Puntero al siguiente nodo de la secuencia
		Node (T data, Node <T>* next = nullptr) {
		       	//Método constructor next será null en caso de que no se propocione
			this -> data = data;
			this -> next = next;
		}
		friend ostream& operator<<(ostream &out, const Node <T> &node) {
		       	//Sobrecarga del operador << para imprimir una instancia de Node
			out << node.data;
			return out;
		}

};
