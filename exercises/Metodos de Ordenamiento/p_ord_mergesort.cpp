//Programa de prueba del algoritmo Merge Sort

#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void merge(int *left, int *right, int *A, int n) ///Funcion principal que mezcla los arreglos
{
	int i=0, j=0, k=0;
	while((i < (n/2)) && (j < (n - n/2)))
	{
		if(left[i] <= right[j])
		{
			A[k] = left[i];
			i++;
		}
		else
		{
			A[k] = right[j];
			j++;
		}
		k++;
	}
	while(i < n/2)
	{
		A[k] = left[i];
		i++;
		k++;
	}
	while(j < (n - n/2))
	{
		A[k] = right[j];
		j++;
		k++;
	}
}

void mergeSort(int A[], int n) //Funcion recursiva
{
	if(n == 1) {return ;} //CASO BASE
	///CASO GENERAL
	int middle = n/2;
	//Nuevos arreglos que guardan los datos contenidos en nuestra lista inicial
	int *left = new int[middle];
	int *right = new int[n-middle];
	for(int i=0; i<middle; i++) ///Para llenar el arreglo con los elementos
		left[i] = A[i];
	for(int i=middle; i<n; i++)
		right[i-middle] = A[i];
	mergeSort(left,middle); ///Llamada recursiva de la funcion para el primer arreglo
	mergeSort(right,n-middle); ///Llamada recursiva de la funcion para el segundo arreglo
	merge(left,right,A,n); //Mezcla de ambos arreglos
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

int main(){
	int N = 50000;
	int Arr[N];
	unsigned t0, t1;
	t0 = clock();
	///Invocacion del metodo de ordenamiento
	numbersFromFile(Arr, N, "numeros.txt"); //Para leer los datos
	mergeSort(Arr, N);
	arrayToFile(Arr, N, "numerosOrdenados.txt"); ///Para escribir los datos
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "\nExecution Time: " << time << " (" << t1 << "-" << t0 << ")" << endl;
	return 0;
}