#include <iostream>
using namespace std;
///Creacion de la clase plantilla
template <class T>
class ContenedorPlantilla
{
    //atributos de la clase
	private:
		T a;
		T b;
	public:
	    //prototipos de funciones
		ContenedorPlantilla();
		ContenedorPlantilla(T,T);
		void modificaDato1(T);
		void modificaDato2(T);
		T obtenDato1();
		T obtenDato2();
		void imprimeDatos();
};
    ///Implementacion de las funciones de manera offline

	template <class T>
	ContenedorPlantilla<T>::ContenedorPlantilla() //constructor por default
	{ }

	template <class T>
	ContenedorPlantilla<T>::ContenedorPlantilla(T nuevoA, T nuevoB) //constructor sobrecargado
	{
		a = nuevoA;
		b = nuevoB;
	}

	template <class T>
	void ContenedorPlantilla<T>::modificaDato1(T _a) // funcion que modifica el primer dato
	{
		a = _a;
	}

	template <class T>
	void ContenedorPlantilla<T>::modificaDato2(T _b) //funcion que modifica el segundo dato
	{
		b = _b;
	}

	template <class T>
	T ContenedorPlantilla<T>::obtenDato1() //funcion que retorna el primer dato
	{
		return a;
	}

	template <class T>
	T ContenedorPlantilla<T>::obtenDato2() //funcion que retorna el segundo dato
	{
		return b;
	}

	template <class T>
	void ContenedorPlantilla<T>::imprimeDatos() //funcion que imprime en pantalla los datos
	{
		cout << "Dato 1: " << a << endl;
		cout << "Dato 2: " << b << endl;
	}

int main(){
    ///Creacion de los objetos
	ContenedorPlantilla <int> contEntero(2,5);
	contEntero.imprimeDatos();

	cout << "Modificacion de dato 1: " << endl;
	contEntero.modificaDato1(18);
	contEntero.imprimeDatos();
	cout << endl; 

	ContenedorPlantilla <float> contReal(1.33,3.4);
	contReal.imprimeDatos();

	cout << "Modificacion del dato 2: " << endl;
	contReal.modificaDato2(1.34);
	contReal.imprimeDatos();
	cout << endl;

	ContenedorPlantilla <char> contLetras('s','d');
	contLetras.imprimeDatos();
	cout << "El dato 1 es: " << contLetras.obtenDato1() << endl;
	cout << endl;

	ContenedorPlantilla <double> contDoble(1234567890,0);
	contDoble.imprimeDatos();
	cout << "El dato 2 es: " << contDoble.obtenDato2() << endl;
    
	return 0;
}