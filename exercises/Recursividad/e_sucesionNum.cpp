#include <iostream>             ///Programa que imprime la sucesion numerica de 1 hasta 101
using namespace std;            ///Ejemplo de recursividad indirecta o cruzada

///Definicion de funciones
int paso1(int i);
int paso2(int i);

int main(){
	int i=1;
	paso1(i);///Invocacion de funcion
	return 0;
}

///Implementacion de funciones
int paso1(int i){
	cout << i << " "; ///Impresion en pantalla
	if(i == 101) ///CASO BASE
		return 101;
	return paso2(i+1); ///CASO GENERAL
}

int paso2(int i){
	cout << i << " "; ///Impresion en pantalla
	if(i == 101) ///CASO BASE
		return 101;
	return paso1(i+1); ///CASO GENERAL
}