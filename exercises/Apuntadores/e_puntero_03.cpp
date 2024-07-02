/*
    Correspondencia entre arrays y punteros
*/
#include <iostream>
using namespace std;

int main(){
    int numeros[] = {1,2,3,4,5};
    int *dir_num;

    //dir_num = &numeros[0]; //Se iguala a la primera posicion del array
    //Otra forma de hacerlo es
    dir_num = numeros; // Significa lo mismo que el anterior
    //Al ser una estructura estatica, el espacio de memoria que se reserva es contiguo o adyacente
    //Lo que significa que si nuestro arreglo[0] esta en la direccion 0x0001, el arreglo[1] estara
    //en la direccion 0x0002 y asi sucesivamente.

    for(int i = 0; i < 5; i++){
        cout << "Elemento del vector [" << i << "]: " << *dir_num++ << endl; //Significa un aumento de 4 bytes
    }

    //Comprobación de que aumenta solo 4bytes
    for(int i = 0; i < 5; i++){
        cout << "Posicion de memoria " << numeros[i] << " es: " << dir_num++ << endl;
    }


    return 0;
}
