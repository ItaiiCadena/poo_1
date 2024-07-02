#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

class Contenedor {
    protected:
        float altura;
        float volumen;
        string sustancia;
    public:
        virtual void setAltura(float)=0;
        virtual void setSustancia(string)=0;
        virtual float getVolumen()=0;
        virtual void calculaVolumen()=0;
        virtual void mostrar()=0;
};

class Cilindrico:private Contenedor {
    float radio;
    public:
        Cilindrico();
        Cilindrico(string, float, float);
        void setAltura(float);
        void setSustancia(string);
        void setRadio(float);
        float getVolumen();
        void calculaVolumen();
        void mostrar();
        friend void mostrarDatosCilindrico(Cilindrico);
};


Cilindrico::Cilindrico() {
    sustancia = "awa";
    altura = 0.0;
    radio = 0.0;
    volumen = 0.0;
}

Cilindrico::Cilindrico(string sus, float alt, float r){
    sustancia = sus;
    altura = alt;
    radio = r;
    volumen = 0.0;
}

void Cilindrico::calculaVolumen() {
    volumen = (3.14*(pow(radio,2)*altura));
}

void Cilindrico::setAltura(float alt) {
    altura = alt;
}

void Cilindrico::setSustancia(string sus) {
    sustancia = sus;
}

void Cilindrico::setRadio(float rad)
{
    radio = rad;
}

void Cilindrico::mostrar() {
    cout << "Sustancia :" << sustancia << endl;
    cout << "Altura :" << altura << endl;
    cout << "Radio :" << radio << endl;
    cout << "Volumen :" << volumen << endl;
}

float Cilindrico::getVolumen() {
    return volumen;
}

void mostrarDatosCilindrico(Cilindrico c) {
    /// Recuerden que estos atributos son TODOS privados
    cout << "Sustancia :" << c.sustancia << endl;
    cout << "Altura :" << c.altura << endl;
    cout << "Radio :" << c.radio << endl;
    cout << "Volumen :" << c.volumen << endl;
}

class Cubo : private Contenedor
{
		float largo;
		float ancho;
	public:
		Cubo();
		Cubo(string, float, float, float);
        void setAltura(float);
        void setSustancia(string);
        float getVolumen();
        void calculaVolumen();
        void mostrar();
		friend void datosMostrarCubo(Cubo);
		void setAncho(float);
		void setLargo(float);

};


Cubo::Cubo()
{
	altura = 0;
	largo = 0;
	ancho = 0;
	sustancia = "S/E";
	volumen = 0;
}

Cubo::Cubo(string nom, float alt, float anch, float lar)
{
	altura = alt;
	largo = lar;
	ancho = anch;
	sustancia = nom;
	volumen = 0;
}

void Cubo::calculaVolumen()
{
	volumen = (altura*largo*ancho);
}


void Cubo::setSustancia(string nuevaSus)
{
	sustancia = nuevaSus;
}


void Cubo::setAltura(float _alt)
{
	altura = _alt;
}


void Cubo::setAncho(float anch)
{
    ancho = anch;
}


void Cubo::setLargo(float larg)
{
    largo = larg;
}

float Cubo::getVolumen()
{
	return volumen;
}

void Cubo::mostrar()
{
	cout << "Datos de la sustancia." << endl;
	cout << "Nombre: " << sustancia << endl;
	cout << "Altura: " << altura << endl;
	cout << "Ancho: " << ancho << endl;
	cout << "Largo: " << largo << endl;
	cout << "Volumen: " << volumen << endl;
}

void datosMostrarCubo(Cubo b)
{
	cout << "Datos de la sustancia." << endl;
	cout << "Nombre: " << b.sustancia << endl;
	cout << "Altura: " << b.altura << endl;
	cout << "Ancho: " << b.ancho << endl;
	cout << "Largo: " << b.largo << endl;
	cout << "Volumen: " << b.volumen << endl;
}

int main() {
    string dato1,valor1;
    float dato2, dato3, valor2, valor3, valor4;
	Cilindrico sus("antrax", 1.5, 0.5);
	Cubo sust("Acido", 1.5, 1.5, 1.5);
	Cilindrico agrego("s/e",0,0);
	Cubo contener("s/e",0,0,0);
	int opc;
	do
	{
		cout << "Bienvenido. Elija una opcion: " << endl;
		cout << "1: Agregar sustancia en contenedor cilindrico" << endl;
		cout << "2: Actualizar datos del cilindro" << endl;
		cout << "3: Calcular y mostrar volumen del cilindro" << endl;
		cout << "4: Mostrar datos de la sustancia en cilindro" << endl;
		cout << "5: Agregar sustancia en contenedor cubico" << endl;
		cout << "6: Actualizar datos del cubo" << endl;
		cout << "7: Calcular y Mostrar volumen del cubo" << endl;
		cout << "8: Mostrar datos de la sustancia en cubo" << endl;
		cout << "0: Salir" << endl;
		cin >> opc;
		system("cls");
		switch(opc)
		{
            case 1:
                system("cls");
                cout << "Ingrese los siguientes datos" << endl;
                cout << "Nombre de la sustancia: " << endl;
                cin >> dato1;
                agrego.setSustancia(dato1);
                cout << "Altura: " << endl;
                cin >> dato2;
                agrego.setAltura(dato2);
                cout << "Radio: " << endl;
                cin >> dato3;
                agrego.setRadio(dato3);
                cout << "Nueva sustancia." << endl;
                mostrarDatosCilindrico(agrego);
                system("pause");
                break;
            case 2:
                system("cls");
                cout << "Ingrese los siguientes datos" << endl;
                cout << "Nombre de la sustancia: " << endl;
                cin >> dato1;
                sus.setSustancia(dato1);
                cout << "Altura: " << endl;
                cin >> dato2;
                sus.setAltura(dato2);
                cout << "Radio: " << endl;
                cin >> dato3;
                sus.setRadio(dato3);
                system("pause");
                break;
            case 3:
                system("cls");
                sus.calculaVolumen();
                cout << "Volumen de la sustancia: ";
                cout << sus.getVolumen() << endl;
                system("pause");
                break;
            case 4:
                system("cls");
                mostrarDatosCilindrico(sus);
                system("pause");
                break;
            case 5:
                system("cls");
                cout << "Ingrese los siguientes datos" << endl;
                cout << "Nombre de la sustancia: " << endl;
                cin >> valor1;
                contener.setSustancia(valor1);
                cout << "Altura: " << endl;
                cin >> valor2;
                contener.setAltura(valor2);
                cout << "Ancho: " << endl;
                cin >> valor3;
                contener.setAncho(valor3);
                cout << "Largo: " << endl;
                cin >> valor4;
                contener.setLargo(valor4);
                datosMostrarCubo(contener);
                system("pause");
                break;
            case 6:
                system("cls");
                cout << "Ingrese los siguientes datos" << endl;
                cout << "Nombre de la sustancia: " << endl;
                cin >> valor1;
                sust.setSustancia(valor1);
                cout << "Altura: " << endl;
                cin >> valor2;
                sust.setAltura(valor2);
                cout << "Ancho: " << endl;
                cin >> valor3;
                sust.setAncho(valor3);
                cout << "Largo: " << endl;
                cin >> valor4;
                sust.setLargo(valor4);
                system("pause");
                break;
            case 7:
                system("cls");
                sust.calculaVolumen();
                cout << "Volumen de la sustancia: " << endl;
                cout << sust.getVolumen() << endl;
                system("pause");
                break;
            case 8:
                system("cls");
                datosMostrarCubo(sust);
                system("pause");
                break;
            case 0:
                system("cls");
                cout << "---Programa terminado---" << endl;
                system("pause");
				break;
			default:
			    system("cls");
				cout << "Opcion invalida, ingrese nuevamente" << endl;
				system("pause");
				break;
		}
	}while(opc != 0);
	return 0;
}