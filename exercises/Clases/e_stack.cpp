#include <iostream>
using namespace std;
///Definicion de la clase pila
class Pila{
	private: ///Atributos
		int *stack; ///Arreglo con memoria dinamica
		int *tope, max; ///Indice y variable para funciones
	public: ///Definicion de metodos de la clase
		Pila(int);
		void push(int);
		int pop();
		void mostrarPila();
		bool pilaLlena();
		bool pilaVacia();
		~Pila();
};


///Implementacio de metodos de la clase
Pila::Pila(int tam){ ///Constructor
	stack = new int[tam]; ///Creacion del arreglo de manera dinamica
	tope = new int(0); ///Creacion e inicializacion del apuntador
	max = tam-1; ///Inicializacion de variable
}

void Pila::push(int dato){ ///Funcion que inserta un dato en la pila si y solo si la pila no esta llena
	if(*tope <= max){
		stack[*tope] = dato;
		*tope = *tope + 1;
	}
}

int Pila::pop(){ ///Funcion que elimina datos de la pila, retorna el dato o valor auxiliar
	int dato = 2147483647; ///Valor auxiliar
	if(*tope > 0){
		*tope = *tope - 1;
		dato = stack[*tope];
	}
	return dato;
}

bool Pila::pilaLlena(){ ///Funcion que retorna true si la pila esta llena o false si no es asi
	if(*tope > max)
		return true;
	else
		return false;
}

bool Pila::pilaVacia(){ ///Funcion que retorna true si la pila esta vacia o false si no lo esta
	if(*tope < 0)
		return true;
	else
		return false;
}

void Pila::mostrarPila(){ ///Funcion que muestra en pantalla los datos contenidos en la pila
	if(pilaLlena() == true){
		cout << "\nLa Pila esta llena" << endl; ///Si la pila esta llena mostrara en pantalla este mensaje
	}
	else if(pilaVacia() == true){
		cout << "\nLa Pila esta vacia" << endl; ///De lo contrario informara que esta se encuentra vacia
	}
	cout << "____\n" << endl;
	for(int i = *tope-1; i>=0; i--){
		cout << stack[i] << endl;
	}
	cout << "____" << endl;
}

Pila::~Pila(){ ///Destructor para liberar memoria
	delete[]stack; ///Elimina arreglo
	delete tope; ///Elimina apuntador
}

int main() {
    Pila p1(5);

    p1.mostrarPila();

    cout << "\nSe inserta 1";   p1.push(1);
    cout << "\nSe inserta 2";   p1.push(2);
    cout << "\nSe inserta 3";   p1.push(3);
    cout << "\nSe inserta 4";   p1.push(4);
    cout << "\nSe inserta 5";   p1.push(5);

    cout << endl;
    p1.mostrarPila();

    /// SE PONER INSERTAR CON LA PILA LLENA
    cout << "\nSe inserta 6";   p1.push(6);

    cout << endl;
    p1.mostrarPila();

    /// SE SACA HASTA VACIAR LA PILA
    cout << "\nDato borrado: " << p1.pop();
    cout << "\nDato borrado: " << p1.pop();
    cout << "\nDato borrado: " << p1.pop();
    cout << "\nDato borrado: " << p1.pop();
    cout << "\nDato borrado: " << p1.pop();

    /// SE INTENTA SACAR CON LA PILA VACÍA
    cout << "\nDato borrado: " << p1.pop();

    cout << endl;
    p1.mostrarPila();

    /// SE MEDIO LLENA LA PILA
    cout << "\nSe inserta 7";   p1.push(7);
    cout << "\nSe inserta 8";   p1.push(8);

    cout << endl;
    p1.mostrarPila();

    /// SE LLENA COMPLETAMENTE LA PILA
    cout << "\nSe inserta 9";   p1.push(9);
    cout << "\nSe inserta 10";  p1.push(10);
    cout << "\nSe inserta 11";  p1.push(11);

    cout << endl;
    p1.mostrarPila();

    /// SE SACAN 2 ELEMENTOS DE LA PILA
    cout << "\nDato borrado: " << p1.pop();
    cout << "\nDato borrado: " << p1.pop();

    cout << endl;
    p1.mostrarPila();

    /// SE PONEN 2 ELEMENTOS LA PILA
    cout << "\nSe inserta 12";  p1.push(12);
    cout << "\nSe inserta 13";  p1.push(13);

    cout << endl;
    p1.mostrarPila();
    p1.~Pila();

    return 0;
}