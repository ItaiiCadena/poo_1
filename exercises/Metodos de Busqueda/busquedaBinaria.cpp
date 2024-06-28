/*
	Programa que realiza la busqueda de un elemento en un arreglo mediante busqueda binaria.
	Para poder utilizar este algoritmo, es necesario que los elemntos esten ordenados para acelarar
	el proceso de busqueda. Este proceso consiste en inspeccionar un elemento elegido al azar
	por ejemplo A[m] y compararlo con el elemento de busqueda. Si es igual a X, la busqueda termina,
	de otra forma si es menor a X, se infiere que todos los elemntos con indices menores o iguales a m
	pueden ser eliminados, y la busqueda se centrara ahora en los demas elementos.
	Para este sistema ocupamos el algoritmo de ordenamiento shellsort por su rapidez.
*/
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

int busquedaBinaria(int A[], int n, int x)
{
	int left = 0, right = n-1, pos = n;
	bool found = false;
	while(left <= right && !(found))
	{
		int m = ((left + right)/2);
		if(A[m] = x){
			found = true;
			pos = m;
		}	
		else{
			if(A[m] < x){
				left = m + 1;
			}
			else{
				right = m;
			}
		}
	}
	return pos;
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
//Inserta en A[] los primeros N numeros, leidos desde el archivo filename
void numbersFromFile(int A[], int N, char *filename){
	ifstream fin;
	fin.open(filename);
	
	for(int i=0; i<N; i++){
		fin >> A[i];
	}
	
	fin.close(); 
}

//Lee de A[] los primeros N numeros y los escribe en el archivo filename
void arrayToFile(int A[], int N, char *filename){
	ofstream fout;
	fout.open(filename);
	
	for(int i=0; i<N; i++){
		fout << A[i] << " ";
		if((i+1)%20 == 0)
			fout << endl;
	}
	
	fout.close();
}

void intercambiar(int *A1, int *A2) {
    int tmp = *A1;
    *A1 = *A2;
    *A2 = tmp;
}

void shellsort(int A[], int n) {
    int j, inc = n;
    do {
        inc = inc/2;
        for (int k=0; k<inc; k++) {
            for (int i=inc+k; i<n; i=i+inc) {
                j = i;
                while ( j-inc>=0 && A[j]<A[j-inc] ) {
                    intercambiar(&A[j], &A[j-inc]);
                    j = j-inc;
                }
            }
        }
    }while( inc>0 );
}

int main(){
	/* PRUEBA 1, ON UNA ARREGLO DE MENOR DIMENSION
	int tam = 7;
	int arreglo[]= {6,9,12,67,3,0,2};
	shellsort(arreglo,tam);
	int posicion = busquedaBinaria(arreglo,tam,9);
	cout << "El numero se encuentra en la posicion " << posicion << " del arreglo" << endl;
	*/

	///PRUEBA 2, CON ARREGLOS DE DISTINTAS DIMENSIONES CONTENIDOS EN ARCHIVOS .TXT
	cout << "Prueba con archivo *numerosD.txt* " << endl;
	int N = countNumbersFromFile("numerosD.txt"); ///Para contabilizar el total de datos
	cout << "Total de datos: " << N << endl;
	int Arr[N];
	unsigned t0, t1;
	t0 = clock();
		numbersFromFile(Arr,N,"numerosD.txt"); ///Para leer los datos en el arreglo
		shellsort(Arr,N);
		arrayToFile(Arr, N, "numD.txt");
		int posicion = busquedaBinaria(Arr, N, 7); ///Invocacion de la funcion de busqueda
		cout << "El numero se encuentra en la posicion " << posicion << " del arreglo\n";
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution time: " << time << "( " << t1 << "-" << t0 << ")" << endl; ///Para el tiempo de ejecucion del programa
	return 0;
}
