///Clases que pretenden simular un Coche cualquiera
///Ejemplo de Agregacion
#include <iostream>
using namespace std;

///Se crea la clase Motor. Clase contenido
class Motor{
	private:
		bool encendido; ///Atributo
	public:
		Motor();
		void iniciar();
		void apagar();
};

	///Implementacion de metodos de manera offline
	Motor::Motor() ///Constructor por default
	{
		encendido = false; ///Inicializacion del atributo
	}
	
	///Funcion que modifica el valor del atributo y muestra en pantalla el cambio
	void Motor::iniciar()
	{
		if(encendido == false) ///Condicional para cambio
		encendido = true; ///Cambio
		cout << "1:El MOTOR del carro ha sido encendido." << endl; 
	}
	
	///Funcion que modifica el valor del atributo y muestra el cambio en pnatalla
	void Motor::apagar()
	{
		if(encendido == true) ///Condicional para cambio
		encendido = false; ///Cambio
		cout << "0:El MOTOR del carro ha sido apagado." << endl;
	}

///Creacion de la clase Coche. Clase contenedor
class Coche{
	public:
	Motor *motor; ///Atributo
	/// definicion de los Metodos
	Coche();
	Coche(Motor *);
	void mover();
	void parar();
};

	///Implementacion de los metodos de manera offline
	Coche::Coche() {} ///Constructor por default
	
	Coche::Coche(Motor *motor) ///Constructor sobrecargado
	{
		this->motor = motor; ///Inicializacion del atributo
	}
	
	///Funcion que enciende el motor y muestra los datos en pantalla
	void Coche::mover()
	{
		motor->iniciar();
		cout << "El CARRO esta en movimiento" << endl;
	}
	
	///Funcion que apaga el motor y muestra los datos en pantalla
	void Coche::parar()
	{
		cout << "El CARRO no esta en movimiento" << endl;
		motor->apagar();
	}
	
	
int main(){
	Motor *mot1 = new Motor; ///Creacion del objeto de la clase Motor de manera dinamica
	Coche *automovil = new Coche(mot1); ///Creacion del objeto de la clase Coche de manera dinamica
	automovil -> mover();
	cout << endl;
	automovil -> parar();
	return 0;
}