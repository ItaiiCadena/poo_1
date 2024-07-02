/*
	Programa que dada una lista de numeros y un elemento, retorna otra lista
	igual a la original, pero sin el elemento dado. En dado caso de que elemento
	aparezca multiples veces, lo remueve en todas la ocasiones.
*/
#include <iostream>
using namespace std;

int* removerTodos(int*, int); ///Definicion de la funcion
int i=0;

int main(){
	int lista[] = {1,2,3,6,6,7,1,9,1};
	int i=0;
	int* copia = removerTodos(lista,1); ///Invocacion de la funcion
	for(int i=0; i<6; i++)
		cout << copia[i] << " "; ///Impresion en pantalla
	return 0;
}

int* removerTodos(int lista[], int elemento) ///Implementacion de la funcion
{
	static int* newList = new int[10];
	if(i == 10)
		return newList; //Retorno del nuevo arreglo sin el elemento
	else{
		if(lista[i] != elemento) ///Caso base
			newList[i-1] = lista[i];	
		else
			newList[i-1] = lista[i+1]; ///Caso general
		i++;
		return removerTodos(lista,elemento); 
	}
} 