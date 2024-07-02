#include <iostream>
using namespace std;
///Creacion de funciones con plantillas
template <class m> 
m numeroMinimo(int tam, m arreglo[]) // funcion que devuelve el valor minimo de un arreglo
{
	m minimo; // almacenara el valor minimo
	minimo = arreglo[0]; // se iguala a la primera posicion del arreglo
	for(int i=0; i < tam; i++) //recorrido en el arreglo
	{
		if(arreglo[i] < minimo) //comparacion de valores
		{
			minimo = arreglo[i]; //cambios
		}
	}
	return minimo; //retorno del valor minimo
}//fin de la funcion

template <class M>
M numeroMaximo(int tam, M arreglo[]) //Funcion que retorna el valor maximo en un arreglo
{
	M maximo;  //almacenara el valor maximo
	maximo = arreglo[0]; //se iguala a la primera posicio del arreglo
	for(int i=0; i < tam; i++) //recorrido por el arreglo
	{
		if(arreglo[i] > maximo) //comparacion de valores
		{
			maximo = arreglo[i]; //cambios
		}
	}
	return maximo; //retorno del numero maximo
}

int main(){
	int tam=9; //dimension del arreglo
	int arr[] = {1,2,3,4,0,5,4,12,11}; //arreglo inicializado
	///Invocacion de las funciones
	cout << "El valor maximo del arreglo es: " << numeroMaximo(tam,arr);
	cout << "\nEl valor minimo del arreglo es: " << numeroMinimo(tam,arr);
	cout << endl;
	char arra[] = {'a','b','c','d','.','A','B','C','D'};
	cout << "El valor maximo del arreglo es: " << numeroMaximo(tam,arra);
	cout << "\nEl valor minimo del arreglo es: " << numeroMinimo(tam,arra);
	return 0;
}