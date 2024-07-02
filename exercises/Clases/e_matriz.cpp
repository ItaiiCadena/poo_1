/*
Implementar la clase matriz, con los siguiente metodos y atributos:
Atributos:
+ **matriz:int
- filas:int
- columnas:int
Metodos:
Matriz();
Matriz(int,int);
void mostrar();
void insertar(int,int,int);
void sacar(int,int);
Matriz operator + (Matriz);
Matriz operator * (Matriz);
Matriz operador();
void borrarMatriz();
void inicializarMatriz(int,int);
Por lo tanto se te pide implementar la clase Matriz con sus atributos y métodos, poniendo
especial atención en la programación de las
siguientes operaciones con matrices.
Sean A, B y C objetos de la clase Matriz, entonces se debe implementar:
i. Suma de matrices:
    C = A + B   //donde A, B y C son del mismo tamaño
ii. Multiplicación de matrices
    C = A * B   //donde el número de columnas de A es igual al número de filas de B
iii. Transposición de matriz
    C = A’      //donde las filas de A se convierten en sus columnas en el mismo orden.
*/

#include <iostream>
using namespace std;

//Creacion de la clase
class Matriz{
	private: //Declaracion de atributos de la clase
		int **matriz;
		int filas;
		int columnas;
	public: //Declaracion de los metodos de la clase
		Matriz();
		Matriz(int,int);
		void mostrar();
		void insertar(int,int,int);
		int sacar(int,int);
		Matriz operator + (Matriz);
		Matriz operator * (Matriz);
		Matriz operator~();
		void borrarMatriz();
		void inicializarMatriz(int,int);
};


int main(){
	Matriz A(3,3), B,C;
	cout << "Matriz A: " << endl;
	A.mostrar();
	cout << endl;
	B.inicializarMatriz(3,3);
	cout << "Matriz B: " << endl;
	B.mostrar();
	cout << endl;
	cout << "Suma de Matriz A y B: "<< endl;
	C = A + B;
	C.mostrar();
	cout << endl;
	cout << "Multiplicacion de matriz A y B: " << endl;
	C = A * B;
	C.mostrar();
	cout << endl;
	cout << "Funcion insertar: " << endl;
	B.insertar(1,1,12);
	B.mostrar();
	cout << endl;
	cout << "Matriz transversa de A: " << endl;
	C = ~A;
	cout << endl;
	cout << "Funcion inicializar: " << endl;
	B.inicializarMatriz(4,4);
	B.mostrar();
	cout << endl;
	cout << "Eliminacion de la matriz A: " << endl;
	A.borrarMatriz();
	A.mostrar();
	return 0;
}

//Implementacion de los metodos offline

	Matriz::Matriz()
	{ //Contructor para inicializar los valores de los atributos
		filas = 3;
		columnas = 3;
		//Creacion de la matriz mediante apuntadores
		matriz = new int*[filas];
		for(int i=0; i<filas; i++)
			matriz[i] = new int[columnas];
		//Creacion de matriz de 3x3 en 0
		for(int i=0; i<filas; i++)
			for(int j=0; j<columnas; j++)
				matriz[i][j] = 0;
	}


	Matriz::Matriz(int f, int c)
	{ //Constructor sobrecargado para inicializar valores de los atributos
		int cont=0; //Para matriz de FxC de 1 en 1
		filas = f;
		columnas = c;
		matriz = new int*[filas];
		for(int i=0; i<filas; i++)
			matriz[i] = new int[columnas];
			// Creacion de matriz FxC con 0,1,2,3,4....n+1
		for(int i=0; i<filas; i++)
			for(int j=0; j<columnas; j++)
				matriz[i][j] = cont++;
	}


	void Matriz::mostrar() //Funcion que imprime en pantalla la matriz
	{
		for(int i=0; i<filas; i++) //Recorrido en filas
		{
			for(int j=0; j<columnas; j++) //Recorrido en columnas
			{
				cout << matriz[i][j] << " "; //Impresion en pantalla
			}
			cout << endl;
		}
	} //Fin de la funcion


	void Matriz::insertar(int x, int y, int n)
    { //Funcion que inserta en coordenadas o posicion (x,y) un numero
		matriz[x][y] = n;
	} //Fin de la funcion

	int Matriz::sacar(int x, int y) //Funcion que obtiene un dato y lo saca de la matriz
	{
		for(int i=0; i<filas; i++)
        {
			for(int j=0; j< columnas; j++)
			{
				if(i == x && j == y)
				{
				    return matriz[i][j];

				}
			}
		}

	}


	Matriz Matriz::operator+(Matriz B) //Funcion que devuelve en una nueva matriz la suma de dos matrices
	{
		Matriz C(filas,columnas); //Instancia de una nueva matriz
		for(int i=0; i<filas; i++)
        {
			for(int j=0; j<columnas; j++)
			{
				C.matriz[i][j] = matriz[i][j] + B.sacar(i,j); //Suma de matrices
			}
		}
		return C; //Retorno de resultado
	} //Fin de la funcion


	Matriz Matriz::operator *(Matriz B) //Funcion que devuelve una nueva matriz con los productos de dos matrices
	{
		Matriz C(filas,columnas); //Instancia de una nueva matriz
		for(int i=0; i<filas; i++)
        {
			for(int j=0; j<columnas; j++)
			{
				C.matriz[i][j] = (C.matriz[i][j] + (matriz[i][j] * B.sacar(i,j))); //Operaciones de multiplicacion
			}
		}
		return C; //Retorno del resultado
	} //Fin de la funcion


	Matriz Matriz::operator~() //Funcion que retorna la matriz transversa de una matriz
	{
		Matriz C(filas,columnas); //Instancia de una matriz
		for(int i=0; i<filas; i++)
        {
			for(int j=0; j<columnas; j++)
			{
				C.matriz[i][j] = matriz[j][i]; //Cambia filas por columnas
			}
		}
		C.mostrar();
	} //Fin de la funcion


	void Matriz::borrarMatriz() //Funcion que elemina la matriz creada
	{
		delete (matriz); //Eliminacion de la matriz
	}


	void Matriz::inicializarMatriz(int fil, int col) //Funcion que inicializa la matriz antes creada con nuevos valores

	{
		int cont=1; //Para crear matriz FxC de 1 en 1
		filas = fil;
		columnas = col;
		matriz = new int*[filas];
		for(int i=0; i<filas; i++)
			matriz[i] = new int[columnas];

		for(int i=0; i<filas; i++)
			for(int j=0; j<columnas; j++)
				matriz[i][j] = cont++;
	} //Fin de la funcion
