/*
Programa que realiza las siguientes acciones:
Diseñar la clase Cadena, que tenga como atributos privados un arreglo de 50 caracteres, como funciones miembro (o métodos):
		>Una función miembro “leer”, que permita captura una línea carácter por carácter
			(se puede incluir cualquier carácter, espacios o números y terminar con ‘.’).
		>Una función miembro “mostrar”, que imprimirá en pantalla la línea de texto.
		>Una función miembro “histograma”, que imprima en forma de histograma las
			vocales existentes en la cadena. Por ejemplo: “divide y venceras.”
			Caracteres: 18
			A:a
			E:eee
			I:ii
			O:
			U:
		>Una función miembro “sustituir”, que dados dos caracteres sustituya el primer
			carácter por el segundo en toda la línea.
		>Además debe existir al menos un constructor, definido como función en línea
			(inline).
		>Todos las demás funciones miembro NO deben ser funciones en línea.
*/
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
//Creacion de la clase
class Cadena{
	private:
		//Atributos
		char cadCaracter[50];
	public:
		//Metodos
		Cadena(){ //Constructor inline para inicializar los valores de los atributos
			cadCaracter[50] = 'D','I','V','I','D','E','\0','Y','\0','V','E','N','C','E','R','A','S','.';
		}
		//Declaracion de funciones miembro, son void porque no retornan nada
		//Se implementaran de manera offline
		void leerCadena();
		void mostrarCadena();
		void histograma();
		void sustituir(char,char);
};


int main(){
	//Uso de funciones de la clase
	char car1, car2; //Para la funcion "Sustituir"
	Cadena cad1; //instancia del objeto
	//Invocacion de funciones
	cad1.leerCadena();
	cad1.mostrarCadena();
	cad1.histograma();
	cout << "Introduzca el caracter a cambiar: " << endl;
	cin >> car1;
	cout << "Introduzca el caracter por el que lo va a cambiar: " << endl;
	cin >> car2;
	cad1.sustituir(car1,car2); //Paso de parametros por valor
}


//Construccion o implementacion de funciones miembro de manera offline
void Cadena::leerCadena() //Lee una cadena de caracteres termina en punto (.)
{ 
	char c; //Para guardar caracter por caracter
	int j = 0;
	cout << "Introduzca una cadena de caracteres en MAYUSCULAS, termine con '.'" << endl;
	cin.get(c); //Lee solo un caracter
	while(j < 50 && c != '.') //Para hacer recorrido en el arreglo
	{ 
		cadCaracter[j] = c; //Guardar lo que hay en c en el arreglo
		j++;
		cin.get(c); //Lee siguiente caracter
	}
} //Fin de la funcion


void Cadena::mostrarCadena() //Imprime en pantalla la cadena
{ 
	cout << "La cadena introducida fue: ";
	cout << cadCaracter << "." << endl;
} //Fin de la funcion


void Cadena::histograma() //Funcion para hacer un histograma con la repeticion de vocales de la cadena
{ 
	cout << "Total caracteres de la cadena: "; 
	cout << strlen(cadCaracter)+1 << endl; //Imprime el total de caracteres de la cadena (+1 para tomar en cuenta el '.')
	//Menus separados para que imprima de manera ordenada las vocales
	cout << "A" << ": ";
	for(int j=0; j<50; j++) //Recorrido en el arreglo
	{ 
		switch( cadCaracter[j])
		{
			case 'A':
			cout<<"A";  //Cada vez que encuentra la vocal la imprimira el numero de veces que la encontro
			break; 
		}
	}
	cout<<endl; //Separacion entre vocales
	//Mismo sistema explicado anteriormente
	cout << "E" << ": ";
	for(int k=0; k<50; k++)
	{
		switch( cadCaracter[k])
		{
			case 'E':
			cout<<"E";
			break; 
		}
	}
	cout<<endl;
	cout << "I" << ": ";
	for(int g=0; g<50; g++)
	{
		switch( cadCaracter[g])
		{
			case 'I':
			cout<<"I";
			break; 
 		}
	}
	cout<<endl;
	cout << "O" << ": ";
	for(int m=0; m<50; m++)
	{
		switch( cadCaracter[m])
		{
			case 'O':
			cout<<"O";
			break; 	
		}
	}
	cout<<endl;
	cout << "U" << ": ";
  	for(int x=0; x<50; x++)
	{
  		switch( cadCaracter[x])
		{
			case 'U':
			cout<<"U";
			break; 
		}
	}
	cout << endl;
} //Fin de la funcion


void Cadena::sustituir(char carac1, char carac2)
{ 
//Funcion que cambia un caracter de la cadena por otro ingresado por el usuario
	for(int i=0; i<50; i++) //Recorrido en el arreglo
	{ 
		if(cadCaracter[i] == carac1) //Comparacion de lo que contiene el arreglo con el caracter a cambiar
		{ 
			cadCaracter[i] = carac2; //Cambio en el arreglo por el nuevo caracter
		}
	}
	cout << "La nueva cadena es: " << cadCaracter <<  "." << endl; //Imprime en pantalla los cambios
} //Fin de la funcion