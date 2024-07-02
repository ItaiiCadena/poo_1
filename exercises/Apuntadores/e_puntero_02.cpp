/*
    Comprobar si un numero es par o impar, y mostrar
    la posicion de memoria donde se esta guardando el numero.
    CON PUNTEROS
*/
#include <iostream>
using namespace std;

int main(){
    int numero, *dir_num;
    
    //Pedimos numero al usuario
    cout << "Digite un numero: "; cin >> numero;
    dir_num = &numero; //Guardamos la posicion de memoria

    if( *dir_num % 2 == 0 ){ //Indicamos lo que hay dentro de esa posicion de memoria
        cout << "El numero " << *dir_num << " es par" << endl;
        cout << "Posicion: " << dir_num << endl; //Solo traemos la posicion de memoria
    } else {
        cout << "El numero " << *dir_num << " es impar" << endl;
        cout << "Posicion: " << dir_num << endl;
    }

    return 0;
}