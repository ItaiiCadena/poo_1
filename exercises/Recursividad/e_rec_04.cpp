/*
	Programa que tal que "x" pertenece a "una lista" y "y" pertenece a "otra lista"
	ambos reaparecen unidos en un arreglo de estructuras u objetos.
*/
#include <iostream>
using namespace std;

struct newList{
	int *numeros;
	char *letras;
	char* aparear(int *, char*);
}nuevoArreglo;
int i=0;
char* aparear(int numeros[], char letras[])
{
	static char* newList = new char[10];
	if(i == 10)
		return newList;
	else{
		newList[i] = numeros[i],letras[i];
		i++;
	}
	
}

int main(){
	char dummy;
	for(int i=0; i<3; i++){
		cout << "Lista 1: ";
		cin >> nuevoArreglo.numeros[i];
	}
	cin.get(dummy);
	for(int i=0; i<3; i++){
		cout << "Lista 2: ";
		cin >> nuevoArreglo.letras[i];
	}
	cout << "\nNuevo arreglo: " << endl;
	cout << nuevoArreglo.aparear(nuevoArreglo.numeros,nuevoArreglo.letras);

	return 0;
}
