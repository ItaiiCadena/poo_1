//Programa de prueba del algoritmo quicksort
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void intercambiar(int *A1, int *A2) {
    int tmp = *A1;
    *A1 = *A2;
    *A2 = tmp;
}

void quicksort(int A[], int left, int right) {
    int i = left;
    int j = right;
    int pivote = A[(i+j)/2];
    do {
        while( A[i]<pivote ) {
            i++;
        }
        while( pivote<A[j] ) {
            j--;
        }
        if ( i<=j ) {
            intercambiar(&A[i], &A[j]);
            i++;
            j--;
        }
    }while( i<=j );
    if ( left<j ) {
        quicksort(A, left, j);
    }
    if ( i<right ) {
        quicksort(A, i, right);
    }
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
	quicksort(Arr, 0, N-1);
	//arrayToFile(Arr, N, "numerosOrdenados.txt"); ///Para escribir los datos
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "\nExecution Time: " << time << " (" << t1 << "-" << t0 << ")" << endl;
	return 0;
}