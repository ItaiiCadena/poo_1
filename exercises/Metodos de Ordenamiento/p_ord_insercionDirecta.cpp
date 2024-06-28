#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void inserciondirecta(int A[], int n) {
    int aux, j;
    for (int i=1; i<n; i++) {
        aux = A[i];
        j = i;
        while (j>0 && aux < A[j-1]) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = aux;
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
	int N = 25000;
	int Arr[N];
	unsigned t0, t1;
	t0 = clock();
	///Invocacion del metodo de ordenamiento
	numbersFromFile(Arr, N, "numeros.txt"); //Para leer los datos
	inserciondirecta(Arr, N);
	//arrayToFile(Arr, N, "numerosOrdenados.txt"); ///Para escribir los datos
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "\nExecution Time: " << time << " (" << t1 << "-" << t0 << ")" << endl;
	return 0;
}