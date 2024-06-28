#include <iostream>
using namespace std;

void imprimeArreglo(int A[], int n) {
    for (int i=0; i<n; i++) {
        cout << A[i];
        if ( i<n-1 )
            cout << "\t";
    }
    cout << endl;
}

/// Esta función imprime los datos del arreglo en el
/// rango de inicio a fin especificado
void imprimeArreglo2(int A[], int ini, int fin) {
    for (int i=ini; i<=fin; i++) {
        cout << A[i];
        if ( i<=fin-1 )
            cout << "\t";
    }
    cout << endl;
}

void intercambiar(int *A1, int *A2) {
    int tmp = *A1;
    *A1 = *A2;
    *A2 = tmp;
}

void quicksort(int A[], int left, int right) {
    int i = left;
    int j = right;
    int pivote = A[(i+j)/2];
    cout << "\nPivote: " << pivote << "\n";
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
            imprimeArreglo2(A, left, right);
        }
    }while( i<=j );
    if ( left<j ) {
        quicksort(A, left, j);
    }
    if ( i<right ) {
        quicksort(A, i, right);
    }
}

int main() {
    cout << "***** ALGORITMO QUICK-SORT *****\n";
    int N = 7;
    int Arr[] = {6, 9, 12, 67, 3, 0, 2};
    //int Arr[] = {12, 42, 44, 55, 94, 18, 6, 67};

    cout << "Arreglo original\n";
    imprimeArreglo(Arr, N);

    cout << "\nOrdenando...\n";
    quicksort(Arr, 0, N-1);

    cout << "Arreglo ordenado\n";
    imprimeArreglo(Arr, N);

    return 0;
}