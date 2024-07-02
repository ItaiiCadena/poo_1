/**
    IMPLEMENTACIÓN 2 DEL ALGORITMO DE BURBUJA (BUBLE-SORT)

    NOTA:
        En esta versión los datos más grandes
        se mueven hacia la derecha.
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

/// Función que intercambia dos elementos (de un arreglo) usado apuntadores
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

/// ALGORITMO ORDENAMIENTO POR BURBUJA (v2)
/*
Procedimiento burbuja2( A[], n )
Inicio
    Para i n-1 hasta 1 hacer
        Para j 0 hasta i-1 hacer
            Si A[j].clave > A[j+1].clave entonces
                Intercambiar( A[j], A[j+1] )
            Fin_si
        Fin_para
    Fin_para
Fin_burbuja
*/
void bubblesort2(int A[], int n) {
    for (int i=n-1; i>=1; i--) {
        for (int j=0; j<=i-1; j++) {
            if ( A[j] > A[j+1] )
                intercambiarA(&A[j], &A[j+1]);

            imprimeArreglo(A, n);
        }
        cout << endl;
    }
}

int main() {
    cout << "***** ALGORITMO BUBBLE-SORT (V2) *****\n";

    int N = 7;
    int Arr[] = {6, 9, 12, 67, 3, 0, 2};

    cout << "Arreglo original\n";
    imprimeArreglo(Arr, N);

    cout << "\nOrdenando...\n";
    bubblesort2(Arr, N);

    cout << "Arreglo ordenado\n";
    imprimeArreglo(Arr, N);

    return 0;
}