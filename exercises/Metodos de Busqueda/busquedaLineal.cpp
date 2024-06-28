/*
	Programa que realiza la busqueda de elementos de manera lineal en datos desordenados.
	Es decir, cuendo los elemntos no llevan un orden o no hay informacion sobre ellos
	se utiliza busqueda lineal, comparando uno a uno los elementos hasta encontrar el deseado.
*/
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

///Funcion de busqueda 
int busquedaLineal(int A[], int n, int x)
{
	int i = 0;
	while(i < n && A[i] != x)
	{
		i = i + 1;
	}
	return i;
}

///Funcion que contabiliza el numero de elementos contenidos en un archivo de extension .txt
int countNumbersFromFile(char *filename)
{
	ifstream fin;
	fin.open(filename);
	int dato, i = 0;
	
	do{
		fin >> dato; ///Se saca dato del buffer (necesario para vaciar el buffer)
		i++; ///Se contabiliza el dato obtenido
	} while(!fin.eof()); ///Se verifica si es fin de archivo (end of file)
	
	fin.close();
	
	return i;
}

///Funcion que lee los datos contenidos en un archivo de extension .txt y los pasa a un arreglo vacio
void numbersFromFile(int A[], int N, char *filename)
{
	ifstream fin;
	fin.open(filename);
	
	for(int i = 0; i < N; i++)
	{
		fin >> A[i];
	}
	fin.close();
}


int main(){
	/* Prueba 1, con un arreglo de menor dimension
	int tam = 7;
	int arreglo[]= {6,9,12,67,3,0,2};
	int posicion = busquedaLineal(arreglo,tam,67);
	cout << "El numero se encuentra en la posicion " << posicion << " del arreglo" << endl;
	*/ 

	///PRUEBA 2, CON ARREGLOS DE DISTINTAS DIMENSIONES CONTENIDOS EN ARCHIVOS .TXT
	cout << "Prueba con archivo *numerosD.txt*" << endl; 
	int N = countNumbersFromFile("numerosD.txt"); ///Para contabilizar el total de datos
	cout << "Total de datos: " << N << endl;
	int Arr[N];
	unsigned t0, t1;
	t0 = clock();
		numbersFromFile(Arr,N,"numerosD.txt"); ///Para leer los datos en el arreglo
		int posicion = busquedaLineal(Arr, N, 7); ///Invocacion de la funcion de busqueda
		cout << "El numero se encuentra en la posicion " << posicion << " del arreglo\n";
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution time: " << time << "( " << t1 << "-" << t0 << ")" << endl; ///Para el tiempo de ejecucion del programa
	return 0; 
}