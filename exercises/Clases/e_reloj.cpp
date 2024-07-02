#include<iostream> //Input y output stream, entrada y salida de datos
using namespace std; //Estandar de c++, nos ayuda para no tener que colocar std:: cada que
                     // creamos algo
                     //std::cout <<
                     
//Creaci�n de la clase reloj
class Reloj {
	private:
		int horas, minutos, segundos;
	public:
		//Las funciones de una clase pueden implementarse dentro de la misma
		//Por ejemplos
		Reloj(){
			horas = 0;
			minutos = 0;
			segundos = 0;
		}; //Obliga y controla la inicializaci�n de un objeto
		Reloj(int hr, int min, int seg); //Pueden existir diferentes constructores
		void mostrarHora();
		void incrementarHoras();
		void incrementarMinutos();
		void incrementarSegundos();
		void cambiarHora(int nuevaHora);
		void cambiarMinutos(int nuevosMinutos);
		void cambiarSegundos(int nuevosSegundos);
		void reset();	
};

//Sin embargo, existe otra forma de implementar las funciones
Reloj::Reloj(int hr, int min, int seg){
	horas = hr;
	minutos = min;
	segundos = seg;
}

void Reloj::mostrarHora(){
	cout << horas << ":" << minutos << ":" << segundos << endl;
}

void Reloj::incrementarHoras(){
	if(horas >= 0 && horas < 23){
		horas = horas + 1;
	} else if(horas == 23) {
		horas = 0;
	}
}

void Reloj::incrementarMinutos(){
	if(minutos >= 0 && minutos < 59){
		minutos = minutos + 1;
	} else if (minutos == 59){
		minutos = 0;
		incrementarHoras();
	}
}

void Reloj::incrementarSegundos(){
	if(segundos >= 0 && minutos < 59){
		segundos = segundos + 1;
	} else if(minutos == 59) {
		segundos = 0;
		incrementarMinutos();
	}
}

void Reloj::cambiarHora(int nuevaHora){
	if(nuevaHora >= 0 && nuevaHora <= 23){
		horas = nuevaHora;
	} else {
		cout << "Ingrese parametros validos" << endl;
	}
}

void Reloj::cambiarMinutos(int nuevosMinutos){
	if(nuevosMinutos >= 0 && nuevosMinutos <= 59){
		minutos = nuevosMinutos;
	} else if (nuevosMinutos == 60){
		incrementarHoras();
	} else {
		cout << "Ingrese parametros validos" << endl;
	}
}

void Reloj::cambiarSegundos(int nuevosSegundos){
	if(nuevosSegundos >= 0 && nuevosSegundos <= 59){
		segundos = nuevosSegundos;
	} else if(nuevosSegundos == 60){
		incrementarMinutos();
	} else {
		cout << "Ingrese parametros validos" << endl;
	}
}

void Reloj::reset(){
	horas = 0;
	minutos = 0;
	segundos = 0;
}

//Funcion principal
int main(){
	//Creamos el objeto de la clase Reloj
	Reloj reloj1; //Constructor por default
	reloj1.mostrarHora(); //Mostrando datos del reloj
	int hrs;
	cout << "Ingrese horas" << endl;
	cin >> hrs;
	Reloj reloj2(hrs, 0, 0); //Constructor con parametros
	reloj2.mostrarHora();
	
	reloj2.incrementarHoras();
	reloj2.mostrarHora();
	
	reloj2.cambiarSegundos(7);
	reloj2.cambiarMinutos(59);
	reloj2.mostrarHora();
	
	reloj2.incrementarMinutos();
	reloj2.mostrarHora();
	
	reloj1.cambiarMinutos(59);
	reloj1.cambiarSegundos(59);
	reloj1.mostrarHora();
	
	reloj1.incrementarSegundos();
	reloj1.mostrarHora();
	
	reloj2.cambiarHora(25);
	reloj2.mostrarHora();
	
    return 0; //Detecta que el programa termino correctamente
}
