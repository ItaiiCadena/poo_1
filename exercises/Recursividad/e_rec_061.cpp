#include <iostream>
#include <algorithm>
using namespace std;
///Programa recursivo que busca el elemento menor en un arreglo
int menorElemento(int *,int,int); ///Definicion de la funcion

int main(){
	int n = 10;
	int datos[10] = {2,33,6,1,3,0,-2,11,5,15}; ///Creacion del arreglo
	cout << "Elemento menor: " << menorElemento(datos,n-1,datos[n-1]); ///Invocacion de la funcion e
	return 0;                                                          ///Impresion en pantalla
}


///Implementacion de funcion
int menorElemento(int arr[], int n, int menor){
	if(n==0) ///Caso base
		return menor = arr[n];
	else if (n>0) ///Caso general
		return menor = menorElemento(arr, n-1, arr[n]);
}