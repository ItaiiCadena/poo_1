#include<iostream>
using namespace std; 

class Empresa {
	protected:
	string nombre;
	int edad; 
};

class Empleado: private Empresa{
	private: 
	float Sbruto;
	float Sneto; // restar 15% de bruto es igual al neto 
	public: 
	Empleado();
	Empleado(string nom, int eda, float brut, float net);
	friend class SAT;
    void mostrar();
};

Empleado::Empleado(){
	nombre = "itaii";
	edad = 19;
	Sbruto = 1200;
	Sneto = 444;
} 

Empleado::Empleado(string nom, int eda, float brut, float net){
	nombre = nom;
	edad = eda;
	Sbruto = brut; 
	Sneto = net; 
}

void Empleado::mostrar(){
	cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Sueldo Bruto: " << Sbruto << endl;
    cout << "Sueldo neto: " << Sneto << endl;
}

class SAT{
    public:
	void CalcularNeto(float Sbruto);
	bool Situacion(float Sneto);
	void mostrarDatosE(); 
};