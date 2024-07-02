/*

    Un puntero es una variable que almacena la direccion 
    de memoria donde se almacena otra variable.
    &n = La direccion de n
    *n = la variables cuya direccion esta almacenada en n, es decir, lo que hay dentro de la posicion de memoria

*/
#include <iostream>
using namespace std;

int main(){
    int num, *dir_num;

    num = 20;
    dir_num = &num; //Se esta asignando la direccion de memoria de num

    cout << "Numero: " << num << endl;
    cout << "Direccion de mem: " << &num << endl;

    cout << "MOSTRANDO DIRECCION DE MEMORIA CON PUNTEROS" << endl;

    cout << "Numero: " << *dir_num << endl;
    cout << "Direccion de mem: " << dir_num << endl;
    cout << "Direccion: " << &dir_num << endl; //Esta es la direccion de dir_num


    return 0;
}