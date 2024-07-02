#include <iostream>
using namespace std;

//Creacion de la clase platilla
template <class I>
class Matriz{
	private: //Declaracion de atributos de la clase
		I **matriz; // matriz que puede ser de cualquir tipo de dato
		int filas;
		int columnas;
	public: //Declaracion de los metodos de la clase plantilla
		Matriz();
		Matriz(int,int);
		void insertar(int,int,I);
		I sacar(int,int);
		///sobrecarga de operadores
		Matriz<I> operator + (Matriz<I>);
		Matriz<I> operator * (Matriz<I>);
		Matriz<I> operator~();
		void borrarMatriz();
		void inicializarMatriz(int,int);
		///funciones amigas tambien creadas con plantillas
		template <class u> friend void mostrar(Matriz<u>);
		template <class u> friend bool comparaDimension(Matriz <u>, Matriz <u>);
};


int main(){
    ///Creacion de objetos de tipo entero
	Matriz <int> A(3,3),B,C;
	cout << "Matriz A: " << endl;
	mostrar(A);
	cout << endl;

	B.inicializarMatriz(3,3);
	cout << "Matriz B: " << endl;
	mostrar(B);
	cout << endl;

	cout << "Suma de Matriz A y B: "<< endl;
	C = A + B;
	mostrar(C);
	cout << endl;

	cout << "Multiplicacion de matriz A y B: " << endl;
	C = A * B;
	mostrar(C);
	cout << endl;

	cout << "Funcion insertar: " << endl;
	B.insertar(1,1,12);
	mostrar(B);
	cout << endl;

	cout << "Matriz transversa de A: " << endl;
	C = ~A;
	cout << endl;

	cout << "Funcion inicializar: " << endl;
	B.inicializarMatriz(4,4);
	mostrar(B);
	cout << endl;

	cout << "Eliminacion de la matriz A: " << endl;
	A.borrarMatriz();
	mostrar(A);
	cout << endl;
    
	cout << "Comparacion de la dimension de la matriz A Y B: " << endl;
	if(comparaDimension(A,B) == true){
        cout << "Las matrices son de igual dimension. " << endl;
	}
	else
        cout << "Las matrices son de diferente dimension." << endl;
	return 0;
}

//Implementacion de los metodos offline
	template <class I>
	Matriz<I>::Matriz()
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

	template <class I>
	Matriz<I>::Matriz(int f, int c)
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


	template <class I>
	void Matriz<I>::insertar(int x, int y, I n)
    { //Funcion que inserta en coordenadas o posicion (x,y) un numero
		matriz[x][y] = n;
	} //Fin de la funcion

	template <class I>
	I Matriz<I>::sacar(int x, int y) //Funcion que obtiene un dato y lo saca de la matriz
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

	template <class I>
	Matriz<I> Matriz<I>::operator+(Matriz<I> B) //Funcion que devuelve en una nueva matriz la suma de dos matrices
	{
		Matriz<I> C(filas,columnas); //Instancia de una nueva matriz
		for(int i=0; i<filas; i++)
        {
			for(int j=0; j<columnas; j++)
			{
				C.matriz[i][j] = matriz[i][j] + B.sacar(i,j); //Suma de matrices
			}
		}
		return C; //Retorno de resultado
	} //Fin de la funcion

	template <class I>
	Matriz<I> Matriz<I>::operator *(Matriz<I> B) //Funcion que devuelve una nueva matriz con los productos de dos matrices
	{
		Matriz<I> C(filas,columnas); //Instancia de una nueva matriz
		for(int i=0; i<filas; i++)
        {
			for(int j=0; j<columnas; j++)
			{
				C.matriz[i][j] = (C.matriz[i][j] + (matriz[i][j] * B.sacar(i,j))); //Operaciones de multiplicacion
			}
		}
		return C; //Retorno del resultado
	} //Fin de la funcion


	template <class I>
	Matriz<I> Matriz<I>::operator~() //Funcion que retorna la matriz transversa de una matriz
	{
		Matriz<I> C(filas,columnas); //Instancia de una matriz
		for(int i=0; i<filas; i++)
        {
			for(int j=0; j<columnas; j++)
			{
				C.matriz[i][j] = matriz[j][i]; //Cambia filas por columnas
			}
		}
		mostrar(C);
	} //Fin de la funcion


	template <class I>
	void Matriz<I>::borrarMatriz() //Funcion que elemina la matriz creada
	{
		delete (matriz); //Eliminacion de la matriz
	}

	template <class I>


	void Matriz<I>::inicializarMatriz(int fil, int col) //Funcion que inicializa la matriz antes creada con nuevos valores
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


    ///implementacion de las funciones amigas
    template <class u>
	void mostrar(Matriz<u> A) //Funcion que imprime en pantalla la matriz
	{
		for(int i=0; i<A.filas; i++) //Recorrido en filas
		{
			for(int j=0; j<A.columnas; j++) //Recorrido en columnas
			{
				cout << A.matriz[i][j] << " "; //Impresion en pantalla
			}
			cout << endl;
		}
	} //Fin de la funcion


	template <class u>
	bool comparaDimension(Matriz<u> A, Matriz<u> B) //Funcion que compara la dimension de dos matrices
	{                                               //Si son iguales devuelve true, de lo contrario devolvera false
        if((A.filas*A.columnas) == (B.filas*B.columnas)) //Sabemos que si multiplicamos las filas por las columnas obtendremmos la dimension de
            return true;                                 //la matriz, por lo tanto eso es lo que se hace en este caso
        else
            return false;
	} //Fin de la funcion