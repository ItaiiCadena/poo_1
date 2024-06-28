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

int main() {
    cout << "***** ALGORITMO SHELL-SORT *****\n";
    int N = 7;
    int Arr[] = {6, 9, 12, 67, 3, 0, 2};
    //int Arr[] = {12, 42, 44, 55, 94, 18, 6, 67};

    cout << "Arreglo original\n";
    imprimeArreglo(Arr, N);

    cout << "\nOrdenando...\n";
    shellsort(Arr, N);

    cout << "Arreglo ordenado\n";
    imprimeArreglo(Arr, N);

    return 0;
}
