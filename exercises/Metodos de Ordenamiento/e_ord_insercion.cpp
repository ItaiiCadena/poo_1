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

int main() {
    cout << "***** ALGORITMO INSERCIÓN DIRECTA *****\n";
    int N = 7;
    int Arr[] = {6, 9, 12, 67, 3, 0, 2};
    //int Arr[] = {12, 42, 44, 55, 94, 18, 6, 67};

    cout << "Arreglo original\n";
    imprimeArreglo(Arr, N);

    cout << "\nOrdenando...\n";
    inserciondirecta(Arr, N);

    cout << "Arreglo ordenado\n";
    imprimeArreglo(Arr, N);

    return 0;
}