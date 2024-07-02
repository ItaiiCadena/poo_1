#include <iostream>
using namespace std;
///Programa que dado un numero inicial y otro final retorna la sucesion
///numerica entre ambos numeros de manera recursiva.

int rango(int,int); ///Definicion de la funcion

int main(){
	int n=5, N=10;
	//for(int i=0; i<n; i++) //Para la funcion que retorna el arreglo
	//cout << rango(n,N) << " ";
	rango(n,N); ///Invocacion de la funcion
	return 0;
}

///Implementacion de la funcion
int rango(int desde, int hasta)
{
	cout << desde << " "; ///Impresion en pantalla
	if(hasta == desde) ///Caso Base
 		return desde;
	return rango(desde+1,hasta); ///Caso general
}


// Funcion que retorna un arreglo (solo imprime el ultimo digito de 
// la sucesion en todas las posiciones del arreglo)
/*int i=0;
int rango(int desde, int hasta)
{
	int arr[hasta-desde];
	if(hasta == desde)
 		return arr[i] = desde;
	return arr[i] = rango(desde+1,hasta);
	i++;
}
*/