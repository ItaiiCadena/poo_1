#include <iostream>
using namespace std;
///Clases que simulan la operacion de un coche cualquiera. Ejemplo de Agregacion entre clases
///Clase contenido
class Motor{
	private:
		bool encendido; //aAtributo
	public:
		///Definicion de funciones
		Motor();
		void iniciar();
		void apagar();
};

///Implementacion de funciones de manera offline
	Motor::Motor() ///Constructor por default
	{
		encendido = false; ///Inicializacion del atributo
	}
	
	///Funcion que cambia el valor del atributo a verdadero para encender el coche
	void Motor::iniciar() 
	{
		if(encendido = false) ///Condicional  de cambio
		encendido = true; ///Cambio
		cout << "1: El MOTOR del carro ha sido encendido." << endl; ///Impresion en pantalla
	}
	
	///Funcion que cambia el valor del atributo a falso (nuevamente) para apagar el coche
	void Motor::apagar()
	{
		if(encendido = true) ///Condicional de cambio
		encendido = false; ///Cambio
		cout << "0: El MOTOR del carro ha sido apagado." << endl; ///Impresion en pantalla
	}
	
///Clase contenedor	
class Coche{
	private:
		///Atributos
		Motor *motor;
		string marca;
	public:
		///Definicion de metodos
		Coche();
		Coche(Motor *, string);
		void setMotor(Motor *);
		void setMarca(string);
		void mover();
		void parar();
};

	
///Implementacion de funciones de manera offline
Coche::Coche(){ ///Constructor por default
	///Inicializacion de atributos
	motor = NULL;
	marca = "s/e";
}
	
	
Coche::Coche(Motor *motor, string marca){ ///Constructor sobrecargado
    ///Inicializacion de atributos
	this -> motor = motor;
	this -> marca = marca;
}
	
///Funcion que actualiza el valor del atributo Motor
void Coche::setMotor(Motor *motor){
	this -> motor = motor;
}
	
///Funcion que actualiza el valor del atributo marca
void Coche::setMarca(string marca){
	this -> marca = marca;
}
	
///Funcion que verifica si existe el motor, si es verdadero iniciara el motor y mostrara en pantalla
///que el carro esta en movimiento. Si el motor no existe no hara nada.
void Coche::mover(){
	if(motor != NULL){
		motor -> iniciar();
		cout << "El CARRO esta en movimiento." << endl;
	}
}
	
///Funcion que verifica si existe el motor, si es verdadero mostrara en pantalla que el carro no esta en movimiento
///despues apagara el motor. Si el motor no existe no hara nada
void Coche::parar(){
	if(motor != NULL){
		cout << "El CARRO no esta en movimiento." << endl;
		motor -> apagar();
	}
}
	
	
int main(){
	///Invocacion de funciones para ver su comportamiento
	Motor *mot1 = new Motor(); ///Creacion de un objeto de la clase Motor de manera dinamica
	Coche *automovil1 = new Coche(mot1, "BMW"); ///Creacion de un objeto de la clase coche con el constructor sobrecargado de manera dinamica
	cout << "Coche 1. Constructor sobrecargado." << endl;
	automovil1->mover();
	automovil1->parar();

	Coche *automovil2 = new Coche(); ///Creacion de un objeto de la clase coche con el constructor por default de manera dinamica
	cout << "\nCoche 2. Constructor por default." << endl;
	automovil2->mover();
	automovil2->parar();

	cout << "No hay respuesta." << endl;
	cout << "\nResultados despues de asignar un Motor" << endl;
	Motor *mot2 = new Motor(); ///Creacion de un objeto de la clase motor de manera dinamica
	automovil2->setMotor(mot2); ///Actualizacion de los datos del coche
	automovil2->mover();
	automovil2->parar();

	return 0;
}