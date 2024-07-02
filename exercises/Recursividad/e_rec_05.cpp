/*
	Programa que convierte una Cadena de caracteres en minuscula, a otro igual
	pero en mayusculas de manera recursiva.
*/

#include <iostream>
using namespace std;

int aMayuscula(char*); ///Definicion de la funcion

int main()
{
   char caracterm[] = "hola mundo"; ///Creacion del arreglo de caracteres
   cout << "Antes de utilizar la funcion:  " << caracterm << endl;
   aMayuscula(caracterm); ///Invocacion de la funcion
   cout << "Despues de utilizar la funcion:  " << caracterm << endl;
   return 0;
}

int aMayuscula(char* minusculas) ///Implementacion de la funcion
{
    if ( *minusculas == 0 ) ///Caso base
        return 0;
	else if ( *minusculas >= 'a' && *minusculas <= 'z')  ///Caso general
       *minusculas = *minusculas-32;
      return   aMayuscula(++minusculas); //uso de recursividad
}