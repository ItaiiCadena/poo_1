#include <iostream>
using namespace std;
///Programa recursivo que devulve un valor no entero de una suma de numeros 
float sumaArmonica(int); ///Definicion de la funcion

int main(){
	int n;
	cout << "Introduce un limite N para la suma armonica: ";
	cin >> n;
	cout << endl << "La suma armonica es: " << sumaArmonica(n) << endl; ///Invocacion de la funcion e
	return 0;															/// impresion en pantalla
}
	
///Implementacion de la funcion
float sumaArmonica(int n){
	if(n == 1) ///CASO BASE
		return 1;
	return 1 / (float) n + sumaArmonica(n-1); ///CASO GENERAL
}