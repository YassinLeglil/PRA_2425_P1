#include <iostream>
#include <ostream>
#include "List.h"
#include "Node.h"
using namespace std;

template <typename T>
class ListLinked : public List <T> {

        private :

                Node <T>* first; //Puntero al primer nodo de la secuencia enlazada
                int n; //Número de elementos que contiene la lista

        public :

                ListLinked () { //Método constructor
                        first = nullptr;
                        n = 0;
                }

                ~ListLinked () { //Método destructor
                         while (first != nullptr) {
                                //Se eliminará cada nodo hasta que first apunte a nullptr es decir que este vacio
                                Node <T>* aux = first -> next;
                                delete first;
                                first = aux;
                                n--;
                        }
                }

                T operator [] (int pos) { //Devuelve el elemento situado en la posición pos
                        if (pos < 0 || pos > size ()) {
                                throw out_of_range ("Posición invalida : Fuera del intervalo");
                        }

                        return get (pos);
                }

                friend ostream& operator << (ostream &out, const ListLinked <T> &List) { //Sobrecarga global del operador <<
                        out << "List => [" << endl;
                        Node <T>* aux = List.first;
                        while (aux != nullptr) {
                        out << "        " << aux -> data << endl;
                                aux = aux -> next;
                        }

                        out << "        ]" << endl;
                        delete aux;
                        return out;

                }

                int size () {
                        return n; //Devuelve el número de elementos
                }

                void insert (int pos, T e) { //Inserta el elemento e en la posición pos
                        if (pos < 0 || pos > size ()) {
                                throw out_of_range ("Posición inválida : Fuera del intervalo");
                        }

                        if (pos == 0) { //Si hay 0 elementos
                                Node <T>* nuevo = new Node (e);
                                nuevo -> next = first;
                                first = nuevo;

                        }else {

                                Node <T>* prev; //Puntero que apunta al nodo anterior
                                Node <T>* newNode; //Puntero que apunta a un nuevo nodo que se va a agregar
                                prev = first;

                                for (int i = 0 ; i < pos - 1; i ++) {
                                        prev = prev -> next;
                                }

                                //Tenemos que crear un nuevo nodo en la posición desseada
                                newNode = new Node <T> (e, prev -> next);
                                prev -> next = newNode;
                        }

                        n++;
                }

                void append (T e) { //Inserta el elemento e al final
                        insert (size () , e);
                }

                void prepend (T e) { //Inserta el elemento e al inicio
                        insert (0 , e);
                }

                T remove (int pos) { //Elimina y devuelve el elemento situado en la posición pos
                        if (pos < 0 || pos >= size ()) {
                                throw out_of_range ("Posición no válida : Fuera del intervalo");
                        }

                        if (empty()) {
                                throw out_of_range ("La lista esta vacía");
                        }

                        if (pos == 0) {
                                Node <T>* aux = first; //Nodo auxiliar
                                first = first -> next; //First apunta al nodo siguiente
                                n--;
                                T data = aux -> data;
                                delete aux;
                                return data;
                        }

                        //Si pos != 0
                        Node <T>* prev = first;

                        for (int i = 0 ; i < pos - 1 ; i ++) { //Se recorren todos los nodos
                                prev = prev -> next;
                        }

                        Node <T>* data_remove = prev -> next; //Nodo a eliminar
                        T remove = data_remove -> data;
                        prev -> next = data_remove -> next; //Actualiza prev -> next para que apunte al siguiente
                        delete data_remove;
                        n--;
                        return remove;
                }

                T get (int pos) { //Devuelve el elemento situado en la posición pos
                        if (pos < 0 || pos >= size ()) {
                                throw out_of_range ("Posición inválida : Fuera del intervalo");
                        }

                        if (empty()) {
                                throw out_of_range ("La lista esta vacia");
                        }

                        Node <T>* recorrer = first;
                        for (int i = 0 ; i < pos ; i ++) {
                                recorrer = recorrer -> next;
                        }
                        T data = recorrer -> data;
                        return data;

                }

                int search (T e) { //Devuelve la posición en la que se encuentra el elemento e
                        Node <T>* prev = first;

                        for (int i = 0 ; i < size () ; i ++) {
                                if (prev -> data == e) {
                                        return i;
                                }
                                prev = prev -> next;
                        }

                        return -1;

                }

                bool empty () {

                        return (first == nullptr);
                }

};




