/*
	Implementacion del algortimo por  vibracion o bidireccional (SHAKE-SORT)
	variante del algoritmo de burbuja pero mejorado. Consiste en ir de izquierda
	a derecha "recordando" cual fue el ultimo intercambio realizado y asi 
	mover los elementos de valor menor a la izquierda y los de mayor
	a la derecha.
*/

#include <iostream>
using namespace std;

/// Función que muestra los elementos de un arreglo A de tamaño n
void imprimeArreglo(int A[], int n) {
    for (int i=0; i<n; i++) {
        cout << A[i];
        if ( i<n-1 )
            cout << "\t";
    }
    cout << endl;
}

/// Función que intercambia dos elementos (de un arreglo) usando apuntadores
void intercambiarA(int *A1, int *A2) {
    int tmp = *A1;
    *A1 = *A2;
    *A2 = tmp;
}

/// Función que intercambia dos elementos (de un arreglo)
void intercambiarB(int A[], int pos1, int pos2) {
    int tmp = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] =  tmp;
}

/*Procedimiento shakesort( A[], n )
Inicio
	left <- 1, right <- n-1, k <- n-1
	Repetir
		Para i<-right hasta left hacer
			Si A[i-1] > A[i] entonces
				Intercambiar( A[i-1], A[i] )
				k<-i
			Fin_si
		Fin_para
		left<-k+1
		Para j<-left hasta right hacer
			Si A[j-1] > A[j] entonces
				Intercambiar( A[j-1], A[j] )
				k<-j
			Fin_si
		Fin_para
		right<-k-1
	Hasta left > right
Fin_shakesort
*/

void shakesort(int A[], int n)
{
	int left = 1, right = n-1, k = n-1;
	do{
		for(int i=right; i>=left; i--){
			if(A[i-1] > A[i]){
				intercambiarA(&A[i-1],&A[i]);
				k=1;
			}
			imprimeArreglo(A,n);
		}
		cout << endl;
		left = k+1;
		for(int j=left; j<=right; j++){
			if(A[j-1] > A[j]){
				intercambiarA(&A[j-1],&A[j]);
				k=j;
			}
			imprimeArreglo(A,n);
		}
		cout << endl;
		right = k-1;
	}
	while(left <= right);
}

int main() {
    cout << "***** ALGORITMO SHAKE-SORT *****\n";

    int N = 7;
    int Arr[] = {6, 9, 12, 67, 3, 0, 2};

    cout << "Arreglo original\n";
    imprimeArreglo(Arr, N);

    cout << "\nOrdenando...\n";
    shakesort(Arr, N);

    cout << "Arreglo ordenado\n";
    imprimeArreglo(Arr, N);

    return 0;
}