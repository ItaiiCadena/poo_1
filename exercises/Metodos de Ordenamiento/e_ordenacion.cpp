/*
    Programa de ejemplo que ordena numeros de un archivo
    y los coloca en un nuevo archivo ya ordenados
*/

#include <iostream>
#include <fstream>
using namespace std;

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

int main(){
    int N;
    int Arr[N]; 
    
	numbersFromFile(Arr, N, "numeros.txt"); //Para leer los datos
	arrayToFile(Arr, N, "numerosOrdenados.txt"); ///Para wscribir los datos
}