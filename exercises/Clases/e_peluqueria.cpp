#include <iostream>
using namespace std;

class Mascota {
	private:
		string nombre;
		string raza;
		int servicio;
		float costo;
		string nombreHumano;
		string celularHumano;
		
	public:
		Mascota(){ // Constructor  
			nombre = "nombre_X";
			raza = "raza_X";
			servicio = 1;
			costo = 231.56;
			nombreHumano = "humano_X";
			celularHumano = "cel_X";
		};

        Mascota(string nombre, string raza, int servicio, float costo, string humano, string movil); // Constructor con parametros
		void mostrar ();
		int setServicio(float valor);
		float getCosto();		
};

//contructor sobrecargado
Mascota::Mascota(string nom, string raz, int serv, float cost, string humano, string movil){
	nombre = nom;
	raza = raz;
	servicio = serv;
	costo = cost;
	nombreHumano = humano;
	celularHumano = movil;	
}


void Mascota::mostrar(){
	cout << "Nombre: " << nombre << endl;
}

int main(){
	int n, opc;
	float total; 
	string nombre, raza, celular;
	int servicio;
	
	
	cout << "Ingresa el numero de mascotas que tendra tu peluqueria: "; 
	cin >> n;
	//Se reserva el espacio para las n mascotas
	Mascota *mascotas = new Mascota[n];  //se crea el arreglo de apuntadores a mascotas 
	
	do {
		cout << "\n[1] Registro de mascota [2] Listado de mascotas [3] Ganancias del dia [4] Salir\n";
		cout << "Selecciona una opcion: ";
		cin >> opc; 
		switch (opc){
			case 1: 
				cout << "Ingresa la informacion de la mascota. " << endl;
				for (int i = 0; i < n; i++){ 
					cout << "Nombre: ";
					cin >> nombre;
					cout << "Raza: ";
					cin >> raza;
					cout << "Servicio: ";
					cin >> servicio;
					cout << "Celular: ";
					cin >> celular;
					mascotas[i] = Mascota(nombre, raza, servicio, 234.45, "Juan", celular);
				}
				//For para mostrar los nombres
				for(int j = 0; j < n; j++){
					mascotas[j].mostrar();
				} 
				break;
			case 2: 
				cout << "La informacion de las mascotas es la siguiente: \n";
				break;
			case 3: 
				total = 0;
				cout << "La ganancia total del hoy es: ";  
				cout << total << " pesos" << endl;
				break;
			case 4: 
				cout << "Gracias por su visita \n";
				break;
		}
	} while(opc != 4);
		
	return 0;
}