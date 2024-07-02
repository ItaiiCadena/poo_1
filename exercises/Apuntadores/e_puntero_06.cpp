#include <iostream>
using namespace std;

class Gato {
private:
	string nombre;
	int  edad;
    float peso;
public:
	Gato ();
	Gato(string nombre, int edad, float peso);
	~Gato(){ cout << "Eliminando "<<nombre << endl;
	}
	void maullar( ); 
	void cazarRatones(); 
	void mostrar();
};
	
Gato::Gato (): nombre("callejero"), edad(2), peso(5) {
    cout << "Constructor: " << nombre << endl; 
}

	
Gato::Gato(string nombre, int edad, float peso)
	: nombre(nombre), edad(edad), peso(peso){ 
    cout << "Constructor: " << nombre << endl;
 }
	
void Gato::maullar( ){
    cout << "miau.... " << endl;
}
void Gato::cazarRatones(){
	cout << "\nCazando ratones :v" << endl; 	
}
void Gato::mostrar(){
	cout << "\nMi nombre es " << nombre << " tengo " << edad << " anios";
	cout << " y peso " << peso << " kg" <<endl;
}

int main()
{	
	Gato benito("Benito", 3, 10);
	benito.maullar();
	benito.mostrar();
	
	Gato *ap; //apuntador a Gato
	ap = new Gato();
	ap->maullar();
	(*ap).mostrar(); //otra forma de llamar sus funciones
	
	Gato *g = new Gato("Cucho", 3, 5);
	(*g).mostrar();
	delete(g);
	
	g = new Gato("Don Gato", 10, 7);
	g->mostrar();
	
	return 0;
}