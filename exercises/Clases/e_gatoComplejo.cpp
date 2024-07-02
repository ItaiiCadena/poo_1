#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class GatoComplejo{
	private:
		char *nombre; ///arreglo dinamico que contendra el nombre del gato
		int suEdad; /// atributo que almacenara la edad del gato
	public:
		///Prototipos de funciones
		GatoComplejo(); ///constructor por default
		GatoComplejo(int largo, int ed, char *nuevoNom); ///constructor sobrecargado
		~GatoComplejo(); ///destructor
		void mostrarDatos(); ///funcion para mostrar los datos del gato
};

///Implementacion de las funciones

GatoComplejo::GatoComplejo(){
	cout << "Se llamo al constructor.\n";
	nombre = new char[10]; ///creacion del arreglo de forma dinamica
	strcpy(nombre,"Gatito..."); ///funcion para copiar cadenas de caracteres
	suEdad = 1;
}


GatoComplejo::GatoComplejo(int largo, int ed, char *nuevoNom){
	cout << "Se llamo al constructor sobrecargado.\n";
	nombre = new char[largo]; ///creacion del arreglo de forma dinamica pasandole parametros
	strcpy(nombre,nuevoNom); ///funcion para copiar caena de caracteres
	suEdad  = ed;
}


GatoComplejo::~GatoComplejo(){
	cout << "Se llamo al destructor.\n";
	delete [] nombre; ///eliminacion del arreglo dinamico
}


void GatoComplejo::mostrarDatos(){ ///funcion para mostrar datos del objeto
	cout << "Mostrando datos de su mascota" << endl;
	cout << "Nombre: " << nombre << endl; ///muestra el arreglo. No es necesario recorrerlo para mostrarlo
	cout << "Edad: " << suEdad << endl; ///muestra la edad
}


int main(){
    int edad, longitud;
    char dummy;
    GatoComplejo gato1; ///creaccion del objeto con el constructor por default
    gato1.mostrarDatos(); ///mostrando datos de objeto
    cout << endl;
    
    cout << "Ingrese los siguientes datos: " << endl;
    cout << "Longitud del arreglo: ";
    cin >> longitud;
    char *suNombre = new char[longitud]; ///creacion de un nuevo arreglo dinamico para guardar el nombre que
    	                                    ///ingrese el usuario
    cout << "Edad del gato: ";
    cin >> edad;
    cout << "Nombre del gato: ";
    cin.get(dummy); ///para que se "coma" el \n\ antes del siguiente get y pueda leer el nombre, sin saltarlo
    cin.getline(suNombre,longitud);
    cout << endl;
    GatoComplejo *gato2 = new GatoComplejo(longitud,edad,suNombre); ///creacion de un objeto dinamico, con los parametros dados
																	   ///por el usuario
    gato2 -> mostrarDatos(); /// mostrando datos del objeto dinamico
    delete (gato2);

	return 0;
}