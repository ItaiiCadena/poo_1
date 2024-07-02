#include <iostream>
#include <cmath>
#include <string.h>
#include <cstring>
using namespace std;



class plantaQuimica
{
	protected:
		float volumen;
		float altura;
		string sustancia;
	public:
		virtual void mostrar()=0;
		virtual void calcularVolumen()=0;
		virtual void setSustancia(string)=0;
		virtual void setAltura(float)=0;
		virtual float getVolumen()=0;

};

class Cilindrico : private plantaQuimica
{
	private:
		float radio;
	public:
		Cilindrico();
		Cilindrico(float alt, float rad, string nom);
		void mostrar();
		void calcularVolumen();
		float getVolumen();
		void setSustancia(string);
		void setAltura(float);
        ///friend void datosMostrarCilindro(Cilindrico);
};


Cilindrico::Cilindrico()
{
	altura = 0;
	radio = 0;
	sustancia = "S/E";
	volumen = 0;
}


Cilindrico::Cilindrico(float alt, float rad, string nom)
{
	altura = alt;
	radio = rad;
	sustancia = nom;
	volumen = 0;
}

void Cilindrico::calcularVolumen()
{
	volumen = 3.1416*(pow(radio,2)*altura);
}


void Cilindrico::setSustancia(string nuevaS)
{
	sustancia = nuevaS;
}


void Cilindrico::setAltura(float _altura)
{
	altura = _altura;
}


float Cilindrico::getVolumen()
{
	return volumen;
}

void Cilindrico::mostrar()
{
	cout << "Datos de la sustancia" << endl;
	cout << "Nombre: " << sustancia << endl;
	cout << "Altura: " << altura << endl;
	cout << "Radio: " << radio << endl;
	cout << "Volumen: " << volumen << endl;
}

/*void datosMostrarCilindro(Cilindrico a)
{
	cout << "Datos de la sustancia" << endl;
	cout << "Nombre: " << a.sustancia << endl;
	cout << "Altura: " << a.altura << endl;
	cout << "Radio: " << a.radio << endl;
	cout << "Volumen: " << a.volumen << endl;
}
*/

class Cubico : private plantaQuimica
{
	private:
		float largo;
		float ancho;
	public:
		Cubico();
		Cubico(string, float, float, float);
		void calcularVolumen();
		void setSustancia(string);
		void setAltura(float);
		float getVolumen();
		void mostrar();
		///friend void datosMostrarCubo(Cubico);

};


Cubico::Cubico()
{
	altura = 0;
	largo = 0;
	ancho = 0;
	sustancia = "S/E";
	volumen = 0;
}

Cubico::Cubico(string nom, float alt, float anch, float lar)
{
	altura = alt;
	largo = lar;
	ancho = anch;
	sustancia = nom;
	volumen = 0;
}

void Cubico::calcularVolumen()
{
	volumen = (altura*largo*ancho);
}


void Cubico::setSustancia(string nuevaSus)
{
	sustancia = nuevaSus;
}


void Cubico::setAltura(float _alt)
{
	altura = _alt;
}


float Cubico::getVolumen()
{
	return volumen;
}

void Cubico::mostrar()
{
	cout << "Datos de la sustancia." << endl;
	cout << "Nombre: " << sustancia << endl;
	cout << "Altura: " << altura << endl;
	cout << "Ancho: " << ancho << endl;
	cout << "Largo: " << largo << endl;
	cout << "Volumen: " << volumen << endl;
}

/*void datosMostrarCubo(Cubico a)
{
	cout << "Datos de la sustancia." << endl;
	cout << "Nombre: " << a.sustancia << endl;
	cout << "Altura: " << a.altura << endl;
	cout << "Ancho: " << a.ancho << endl;
	cout << "Largo: " << a.largo << endl;
	cout << "Volumen: " << a.volumen << endl;
}
*/
int main()
{
	float alt, rad;
	string nom;
	cout << "Ingrese los siguientes datos" << endl;
	cout << "Nombre de la sustancia: " << endl;
	cin >> nom;
	cout << "Altura: " << endl;
	cin >> alt;
	rad = 0;
	Cilindrico sus(alt,rad,nom);
	Cubico sust(nom,alt,7,8);
	cout << endl;
	int opc;

    //Declaracion de variables para su uso en do - while
    int variable, info, al1, al2, al3;
	string date, var, cubicnom, nombreCubic;
    float resultado, resulVol;
    Cubico nuevaSus(cubicnom,al1,al2,al3);

	do
	{
		cout << "Bienvenido. Elija una opcion: " << endl;
		cout << "1: Agregar sustancia en contenedor cilindrico" << endl;
		cout << "2: Actualizar datos del cilindro" << endl;
		cout << "3: Calcular y mostrar volumen" << endl;
		cout << "4: Mostrar datos de la sustancia" << endl;
		cout << "5: Agregar sustancia en contenedor cubico" << endl;
		cout << "6: Actualizar datos del cubo" << endl;
		cout << "7: Calcular y Mostrar volumen del cubo" << endl;
		cout << "8: Mostrar datos de la sustancia" << endl;
		cout << "0: Salir" << endl;
		cin >> opc;
		switch(opc)
		{
			case 1:
				cout << "Ingrese los siguientes datos: " << endl;
				cout << "Nombre de la sustancia: " << endl;
				cin >> date;
				cout << "Altura: " << endl;
				cin >> variable;
				cout << "Radio: " << endl;
				cin >> info;
				//Cilindrico c1(variable,info,date);
				//c1.mostrar();
				cout << endl;
				break;
			case 2:
				cout << "Nuevo nombre: " << endl;
				cin >> var;
				sus.setSustancia(var);
				float _tamano;
				cout << "Nueva altura: " << endl;
				cin >> _tamano;
				sus.setAltura(_tamano);
				cout << endl;
				break;
			case 3:
				sus.calcularVolumen();
				resultado = sus.getVolumen();
				cout << "Volumen de la sustancia: " << endl;
				cout << resultado;
				cout << endl;
				break;
			case 4:
				sus.mostrar();
				cout << endl;
				break;
			case 5:
				cout << "Ingrese los siguientes datos" << endl;
				cout << "Nombre de la sustancia: " << endl;
				cin >> cubicnom;
				cout << "Altura: " << endl;
				cin >> al1;
				cout << "Ancho: " << endl;
				cin >> al2;
				cout << "Largo: " << endl;
				cin >> al3;
				nuevaSus.mostrar();
				cout << endl;
				break;
			case 6:
				cout << "Nuevo nombre: " << endl;
				cin >> nombreCubic;
				sust.setSustancia(nombreCubic);
				int dimen;
				cout << "Nueva altura: " << endl;
				cin >> dimen;
				sust.setAltura(dimen);
				cout << endl;
				break;
			case 7:
				sust.calcularVolumen();
				resulVol = sust.getVolumen();
				cout << "Volumen de la sustancia: " << endl;
				cout << resulVol << endl;
				cout << endl;
				break;
			case 8:
				sust.mostrar();
				cout << endl;
				break;
			case 0:
				cout << "---Programa terminado---" << endl;
				break;
			default:
				cout << "Opcion invalida, ingrese nuevamente" << endl;
				break;
		}
	}while(opc != 0);
	return 0;
}