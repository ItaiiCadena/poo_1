#include <iostream>
using namespace std;

///Clases que simulan la operacion de un coche cualquiera. Ejemplo de Composicion.
///Clase componente
class Motor{
	private:
		bool encendido; ///Atributo
	public:
		///Definicion metodos
		Motor();
		void iniciar()const;
		void apagar()const;
};

///Implementacion de funciones de manera offline
	Motor::Motor() ///Constructor por default
	{
		encendido = false; ///Inicializacion del atributo
	}
	
	///Funcion que enciende el coche volviendo al atributo en verdadero
	///Como es una funcion constante y por tanto ya no se pueden modificar
	///los datos, utilizamos apuntadores para forzar la modificacion el atributo
	void Motor::iniciar()const
	{
		bool *on; ///Se crea un apuntador del mismo tipo del atributo
		on = (bool*)(&encendido); ///Se asigna el tipo y direccion del atributo
		if(encendido == false) //Condicional para cambio
		*on = true; ///Se usa el apuntador para modificar el atributo
		cout << "1:El MOTOR del carro ha sido encendido." << endl;
	}
	
	///Funcion similar a la de iniciar, apaga el motor del coche y convierte
	///al atributo en falso. Al ser una funcion constante utilizamos apuntadores para
	///forzar la modificacion del atributo
	void Motor::apagar() const
	{
		bool *off; ///Se crea un apuntador del mismo tipo del atributo
		off = (bool*)(&encendido); ///Se asigna el tipo y direccion del atributo
		if(encendido == true) //Condicional para cambio
		*off = false; ///Se usa el apuntador para modificar el atributo
		cout << "0:El MOTOR del carro ha sido apagado." << endl;
	}
	

class Coche{
	private:
		const Motor *motor;   ///constante de clase motor que servira para mover y parar
		                     ///el coche con sus metodos antes implementados
		string marca;     
	public:
		///Definicion de los metodos
		Coche(Motor *, string);
		void setMarca(string);
		void mover();
		void parar();
};

	Coche::Coche(Motor *motor, string marca) : motor(motor) ///Constructor por default, inicializacion de los atributos.
	{
		this->marca = marca;
	}
	
	void Coche::mover() ///Funcion que inicia el motor y muestra en pantalla los datos
	{
		motor->iniciar();
		cout << "El CARRO esta en movimiento" << endl;
	}
	
	void Coche::parar() ///Funcion que apaga el motor y muestra los datos en pantalla
	{
		cout << "El CARRO no esta en movimiento" << endl;
		motor->apagar();
	}
	
int main(){
	///Invocacion de los metodos para ver su comportamiento.
	Motor *motor = new Motor; ///Creacion del objeto motor de manera dinamica
	Coche *automovil = new Coche(motor, "BMW"); ///Creacion del objeto coche de manera dinamica
	automovil -> mover();
	automovil -> parar();
	return 0;
}