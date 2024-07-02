/*
	Programa que dada una lista de numeros y un numero N, retorna la suma
	de todos los N primeros elementos
*/
#include <iostream>
using namespace std;

int sumarN(int, int*); ///Definicion de la funcion

int main(){
	int n=3, numeros[] = {2,4,6,8,10,12};
	cout << "La suma de los primeros " << n << " elementos es: ";
	cout << sumarN(n-1,numeros); ///Invocacion de la funcion
}

int sumarN(int n, int numeros[]) ///Implementacion de la funcion
{
	if(n == 0) ///CASO BASE
		return numeros[n];
	return numeros[n] + sumarN(n-1,numeros); ///CASO GENERAL
}