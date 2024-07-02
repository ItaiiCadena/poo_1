/*
	Programa que ordena los elementos de un arreglo mediante el metodo de  ordenamiento de insercion binaria
*/
#include <iostream>
using namespace std;

///Funcion que imprime loa elementos del arreglo
void imprimirArreglo(int A[], int n)
{
	for (int i=0; i<n; i++) {
        cout << A[i];
        if ( i<n-1 )
            cout << "\t";
    }
    cout << endl;
}

///Metodo de ordenamiento
void insercionBinaria(int A[], int n)
{
	int aux, left, right, middle;
    for (int i=1; i<=n-1; i++) {
        aux = A[i];
        left = 0;
        right = i;
        while (left < right)
		{
            middle = ((left + right)/2);
            if(A[middle] <= aux)
            {
            	left = left + 1;
            }
            else
            	right = middle;
        }
        for(int j = i; j >= right + 1; j--)
        {
        	A[j] = A[j-1];
        }
        A[right] = aux;
        imprimirArreglo(A,n);
    }
}

int main(){
	cout << "***** ALGORITMO INSERCION BINARIA *****\n";
    int N = 7;
    int Arr[] = {6, 9, 12, 67, 3, 0, 2};
    ///int Arr[] = {12, 42, 44, 55, 94, 18, 6, 67};

    cout << "Arreglo original\n";
    imprimirArreglo(Arr, N);

    cout << "\nOrdenando...\n";
    insercionBinaria(Arr, N); ///Invocacion de la funcion

    cout << "\nArreglo ordenado\n";
    imprimirArreglo(Arr, N);
    return 0;
}