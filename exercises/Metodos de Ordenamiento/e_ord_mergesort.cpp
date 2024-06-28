/*
	Programa que utiliza el metodo de ordenamiento por mezcla (o merge-sort en ingles) para ordenar un arreglo de
	enteros mediante la tecnica DIVIDE Y VENCERAS. Este metodo consiste en llamar recursivamente la funcion
	que divide la lista (o arreglo) a la mitad de tal forma que se van ordenando para finalmente mezclar las listas
	para obtener el arreglo completamente ordenado.
*/
#include <iostream>
using namespace std;
///Definicion de las funciones
void imprimirArreglo(int *, int);
void mergeSort(int *, int);
void merge(int *, int *, int *, int);

int main(){

	cout << "***** ALGORITMO MERGE-SORT *****\n";
    int N = 7;
    int Arr[] = {6, 9, 12, 67, 3, 0, 2};

    cout << "Arreglo original\n";
    imprimirArreglo(Arr, N);

    cout << "\nOrdenando...\n";
    mergeSort(Arr, N); ///Invocacion de la funcion

    cout << "\nArreglo ordenado\n";
    imprimirArreglo(Arr, N);

    return 0;
}

///Implementacion de las funciones
void imprimirArreglo(int A[], int n) //Funcion que imprime el arreglo en pantalla
{
	for (int i=0; i<n; i++) {
        cout << A[i];
        if ( i<n-1 )
            cout << "\t";
    }
    cout << endl;
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