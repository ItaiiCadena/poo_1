/*
    Rellenar un array de 10 numeros, posteriormente utilizando punteros
    indica cuales son numeros pares y su posicion en memoria
*/
#include <iostream>
using namespace std;

int main() {
    int numeros[10], *dir_num;

    for(int i = 0; i < 10; i++){
        cout << "Digite un numero[" << i << "]: ";
        cin >> numeros[i];
    }

    dir_num = numeros; //Posicion de memoria en que comienza numeros

    for(int i = 0; i < 10; i++){
        if(*dir_num % 2 == 0){
            cout << "El numero " << *dir_num << " es par" << endl;
            cout << "Posicion: " << dir_num << endl;
        }
        dir_num++;
        //1. [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        //	El numero 2 es par --- manda dir en memoria
        // El numero 4 es par --- manda dir en memoria
    }


    return 0;
}