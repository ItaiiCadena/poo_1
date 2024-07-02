#include <cstdlib>
#include <iostream>
using namespace std;

class Libro{
	private:
		int clave;
		string titulo;
		string autor;
	public:
		int anio;
		Libro();
		Libro(int, string, string, int);
		void cambiarDatos(int, string, string, int);
		void mostrarDatos();
};

Libro::Libro()
{
	titulo = "Sin especificar";
	autor = "Sin especificar";
	anio = 0;
	clave = 0;
}

Libro::Libro(int clave, string titulo, string autor, int anio)
{
	this->clave = clave;
	this->titulo = titulo;
	this->autor = autor;
	this->anio = anio;
}

void Libro::cambiarDatos(int clave, string titulo, string autor, int anio)
{
	this->clave = clave;
	this->titulo = titulo;
	this->autor = autor;
	this->anio = anio;
}

void Libro::mostrarDatos()
{
	cout <<  clave << ": " << autor << ", " << titulo << ", " << anio << "." << endl;
}

template <class T>
class Clasificacion{
	public:
		void intercambiar(T *A1, T *A2);
		void imprimirArreglo(T A[], int);
		virtual void ordenar(T A[], int)=0;
};

template <class T>
void Clasificacion<T>::intercambiar(T *A1, T *A2)
{
	T tmp = *A1;
    *A1 = *A2;
    *A2 = tmp;
}

template <class T>
void Clasificacion<T>::imprimirArreglo(T A[], int n)
{
	for (int i=0; i<n; i++) {
        A[i].mostrarDatos();
    }
}

template <class T> 
class BubblesortIzq : public Clasificacion<T>
{
	public:
		void ordenar(T A[], int);
};

template <class T>
void BubblesortIzq<T>::ordenar(T A[], int n)
{
	for (int i=0; i<=n-1; i++) {
        for (int j=n-1; j>=i+1; j--) {
            if (A[j].anio < A[j-1].anio)
                this->intercambiar(&A[j], &A[j-1]);
        }
    }
}

template <class T>
class BubblesortDer : public Clasificacion<T>
{
	public:
		void ordenar(T*, int);
};

template <class T>
void BubblesortDer<T>::ordenar(T A[], int n)
{
	for (int i=n-1; i>=1; i--) {
        for (int j=0; j<=i-1; j++) {
            if (A[j].anio > A[j+1].anio)
                this->intercambiar(&A[j], &A[j+1]);
        }
    }
}

template <class T>
class Shakesort : public Clasificacion<T>
{
	public:
		void ordenar(T*, int);
};

template <class T>
void Shakesort<T>::ordenar(T A[], int n)
{
	int left = 1, right = n-1, k = n-1;
	do{
		for(int i=right; i>=left; i--){
			if(A[i-1].anio > A[i].anio){
				this->intercambiar(&A[i-1],&A[i]);
				k=1;
			}
		}
		left = k+1;
		for(int j=left; j<=right; j++){
			if(A[j-1].anio > A[j].anio){
				this->intercambiar(&A[j-1],&A[j]);
				k=j;
			}
		}
		right = k-1;
	}
	while(left <= right);
}

int main() {
	cout << "***** ALGORITMOS DE ORDENAMIENTO *****\n";
	int N = 7;
	Libro nuevo, favoritos[N];
	
	
	/// Se utiliza el objeto "nuevo" como recipiente para insertar una copia
	/// de cada libro en el arreglo de objetos (paso por valor).
	nuevo.cambiarDatos(6, "Las nueve revelaciones", "James Redfield", 1993);
	favoritos[0] = nuevo;
	nuevo.cambiarDatos(9, "Siddhartha", "Hermann Hesse", 1922);
	favoritos[1] = nuevo;
	nuevo.cambiarDatos(12, "Un mundo feliz", "Aldous Huxley", 1932);
	favoritos[2] = nuevo;
	nuevo.cambiarDatos(67, "1984", "Geroge Orwell", 1948);
	favoritos[3] = nuevo;
	nuevo.cambiarDatos(3, "Plan de vuelo", "A. Esquinca", 2011);
	favoritos[4] = nuevo;
	nuevo.cambiarDatos(0, "Manual para no morir de amor", "Walter Riso", 2010);
	favoritos[5] = nuevo;
	nuevo.cambiarDatos(2, "El caballero de la armadura oxidada", "Robert Fisher", 1987);
	favoritos[6] = nuevo;
	
	
	/// Se deben probar las 3 clases
	BubblesortIzq <Libro>met1; /// <-- Burbuja con recorridos a la izquierda (V1)
	BubblesortDer <Libro>met2; /// <-- Burbuja con recorridos a la derecha (V2)
	Shakesort <Libro>met3; /// <-- Burbuja mejorada (bidireccional o por vibración)
	
	
	cout << "\nARREGLO DE OBJETOS ORIGINAL\n";
	met1.imprimirArreglo(favoritos, N);
	//met2.imprimirArreglo(favoritos, N);
	//met3.imprimirArreglo(favoritos, N);
	
	
	met1.ordenar(favoritos, N); /// <-- Ordenamiento por burbuja V1
	//met2.ordenar(favoritos, N); /// <-- Ordenamiento por burbuja V2
	//met3.ordenar(favoritos, N); /// <-- Ordenamiento por burbuja mejorada
	
	
	cout << "\nARREGLO DE OBJETOS ORDENADO POR ANIO\n";
	met1.imprimirArreglo(favoritos, N);
	//met2.imprimirArreglo(favoritos, N);
	//met3.imprimirArreglo(favoritos, N);
	
	return 0;
}