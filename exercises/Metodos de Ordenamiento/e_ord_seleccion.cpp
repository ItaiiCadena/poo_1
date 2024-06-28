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

void selecciondirecta(int A[], int n) {
    int aux, k;
    for (int i=0; i<n-1; i++) {
        aux = A[i];
        k = i;
        for (int j=i+1; j<n; j++) {
            if ( A[j]<aux ) {
                k = j;
                aux = A[k];
            }
        }
        A[k] = A[i];
        A[i] = aux;
    }
}

int main() {
    cout << "***** ALGORITMO SELECCIÓN DIRECTA *****\n";
    int N = 7;
    int Arr[] = {6, 9, 12, 67, 3, 0, 2};
    //int Arr[] = {12, 42, 44, 55, 94, 18, 6, 67};

    cout << "Arreglo original\n";
    imprimeArreglo(Arr, N);

    cout << "\nOrdenando...\n";
    selecciondirecta(Arr, N);

    cout << "Arreglo ordenado\n";
    imprimeArreglo(Arr, N);

    return 0;
}