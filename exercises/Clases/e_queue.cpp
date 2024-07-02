#include <iostream>
using namespace std;

//Definicion de la clase Cola  
class Cola{
	private: ///Atributos
		int *queue; ///Arreglo con memoria dinamica
		int *frente, *fondo; ///Indices o apuntadores para el manejo de funciones
		int min, max; ///Variables para el manejo de funciones
	public: ///Definicion de funciones miembro de la clase
		Cola(int);
		void inserta(int);
		int elimina();
		void mostrarCola();
		bool colaLlena();
		bool colaVacia();
		~Cola();
};
///Implementacion de funciones miembro de la clase
Cola::Cola(int tam){ ///Constructor
	queue = new int[tam]; ///Creacion del arreglo de manera dinamica
	frente = new int(0); ///Creacion e inicializacion de apuntador
	fondo = new int(0); ///Creacion e inicializacion de apuntador
	min = 0;///Inicializacion de variables
	max = tam - 1;
}

void Cola::inserta(int dato){ ///Funcion que inserta dentro de la cola un dato
	if(*fondo <= max){
		queue[*fondo] = dato;
		*fondo = *fondo + 1;
	}
}

int Cola::elimina(){ ///Funcion que elimina datos dentro de la cola, retorna dicho dato o el valor auxiliar
	int  dato = 2147483647; ///Valor auxiliar
	if(*frente < *fondo){
		dato = queue[*frente];
		*frente = *frente + 1;
		if(*frente == *fondo){
			*fondo = min;
			*frente = *fondo;
		}
	}
	return dato;
}

bool Cola::colaLlena(){ ///Funcion que retorna true si la cola esta llena o false si no lo esta
	if(*fondo > max)
		return true;
	else
		return false;
}

bool Cola::colaVacia(){ ///Funcion que retorna true si la cola esta vacia o false si no lo esta
	if(*frente == *fondo)
		return true;
	else
		return false;
}

void Cola::mostrarCola(){ ///Funcion que muestra los datos dentro de la cola
	if(colaLlena() == true){
		cout << "\nLa cola esta llena" << endl; ///Si la cola esta llena mostrara en pantalla este mensaje
	}
	else if(colaVacia() == true){
		cout << "\nLa cola esta vacia" << endl; ///De otro modo informara que la cola esta vacia
	}
	cout << "| ";
    for(int i=*frente; i<=*fondo-1; i++){
        cout << queue[i] << " ";
    }
    cout << "|\n";
}

Cola::~Cola(){ ///Destructor para liberar memoria
	delete[]queue;  ///Elimina el arreglo
	delete frente; ///Elimina los apuntadores
	delete fondo;
}

int main() {
    Cola c1(5); ///Creacion del objeto de la clase cola
        ///Prueba de funciones
    c1.mostrarCola();

    /// SE LLENA LA COLA
    cout << "\nSe inserta 1";   c1.inserta(1);
    cout << "\nSe inserta 2";   c1.inserta(2);
    cout << "\nSe inserta 3";   c1.inserta(3);
    cout << "\nSe inserta 4";   c1.inserta(4);
    cout << "\nSe inserta 5";   c1.inserta(5);

    cout << endl;
    c1.mostrarCola();

    /// SE INTENTA INSERTAR UN DATO CON LA COLA LLENA
    cout << "\nSe inserta 6";   c1.inserta(6);
    c1.mostrarCola();

    /// SE ELIMINAN 3 DATOS
    cout << "\nDato borrado: " << c1.elimina();
    cout << "\nDato borrado: " << c1.elimina();
    cout << "\nDato borrado: " << c1.elimina();

    cout << endl;
    c1.mostrarCola();

    /// SE ELIMINAN 2 DATOS
    cout << "\nDato borrado: " << c1.elimina();
    cout << "\nDato borrado: " << c1.elimina();
    /// SE ELIMINA 1 DATO CON LA COLA VACÍA
    cout << "\nDato borrado: " << c1.elimina();

    cout << endl;
    c1.mostrarCola();

    /// SE VUELVE A LLENAR LA COLA
    cout << "\nSe inserta 7";   c1.inserta(7);
    cout << "\nSe inserta 8";   c1.inserta(8);
    cout << "\nSe inserta 9";   c1.inserta(9);
    cout << "\nSe inserta 10";  c1.inserta(10);
    cout << "\nSe inserta 11";  c1.inserta(11);

    cout << endl;
    c1.mostrarCola();

    /// SE ELIMINAN 2 DATOS
    cout << "\nDato borrado: " << c1.elimina();
    cout << "\nDato borrado: " << c1.elimina();

    cout << endl;
    c1.mostrarCola();

    /// SE INSERTAN 2 DATOS EN LAS POSICIONES DESOCUPADAS
    cout << "\nSe inserta 12";   c1.inserta(12);
    cout << "\nSe inserta 13";   c1.inserta(13);

    cout << endl;
    c1.mostrarCola();
    c1.~Cola();

    return 0;
}
