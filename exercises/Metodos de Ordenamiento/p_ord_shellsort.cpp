//Programa de prueba del algoritmo shellsort
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

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
	numbersFromFile(Arr, N, "numerosD.txt"); //Para leer los datos
	shellsort(Arr, N);
	arrayToFile(Arr, N, "numD.txt"); ///Para escribir los datos
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "\nExecution Time: " << time << " (" << t1 << "-" << t0 << ")" << endl;
	return 0;
}