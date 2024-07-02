#include <iostream>
using namespace std;

int main(){
	int *p; //declarar un apuntador
	int x;

//	*p = 0;	
	cout << "p: " << p << "\t&p: " << &p << endl;
	cout << "x: " << x << "\t&x: " << &x <<endl;
	
	x = 15;
	cout << "x: " << x << "\t&x: " << &x <<endl;
	p = &x; //al apuntador se le asigna la direccion de memoria de x
	cout << "p: " << p << "\t*p: " << *p << endl;
	
	//memoria dinámica
	p = new int;  //asignando memoria en tiempo de ejecucion
	*p = 100;
	cout << "p: " << p << "\t*p: " << *p << endl;
	cout << "x: " << x << "\t&x: " << &x <<endl;

	
}