#include <iostream>
using namespace std;

class Vehiculo
{
	protected:
		string matricula;
		double N_serie;
		string modelo;
		string placa;
		double fecha;
	public:
		friend void setActualizarP(string);
		friend void setActualizarA(double);
};

class Actualizacion : private Vehiculo
{
	public:
		void mostrar();
		friend void setActualizarP(string);
		friend void setActualizarA(double);

void setActualizarP(string _pla){
	placa = _pla;
}

void setActualizarA(double _fech){
	fecha = _fech;
}
};

class Auto: private Vehiculo
{
	private:
	int aire;
	int tipo;
	int duenos;
	public:
		Auto();
		Auto(string mat, double ns, string m);
		friend void setActualizarP(string);
		friend void setActualizarA(double);
		bool aire_a();
		bool tipoDeAuto();
		void setTotalD(int toD);
		void mostrarAuto();
        friend void mostrarDatosAuto(Auto);
};

Auto::Auto(){
	matricula= "155";
	N_serie=142;
	modelo= "s/e";
	fecha=2019;
	placa= "s/e";
	duenos=4;
	aire=0;
	tipo=0;
}

Auto :: Auto(string mat, double ns, string m){
	matricula= mat;
	N_serie=ns;
	modelo= m;
	fecha=0;
	placa="S/E";
	duenos=0;
	aire= 0;
	tipo=0;
}

bool Auto::aire_a(){
	if(aire==1)
	return true;
	else
	return false;
}

bool Auto::tipoDeAuto(){
	if(tipo==1)
	return true;
	else
	return false;
}

void Auto::setTotalD(int toD)
{
	duenos = toD;
}

void Auto::mostrarAuto(){
	cout<<"DATOS DE AUTOMOVIL "<<endl;
	cout<<"Matricula: "<<matricula<<endl;
	cout<<"Numero de serie: "<<N_serie<<endl;
	cout<<"Modelo: "<<modelo<<endl;
	cout<<"Año: "<<fecha<<endl;
	cout<<"Placa: "<<placa<<endl;
	cout<<"Numero de dueños: "<<duenos<<endl;
	cout<<"Tipo : "<<tipo<<endl;
	cout<<"Contiene: "<<aire<<endl;
}

void mostrarDatosAuto(Auto a)
{
	cout<<"DATOS DE AUTOMOVIL "<<endl;
	cout<<"Matricula: "<<a.matricula<<endl;
	cout<<"Numero de serie: "<<a.N_serie<<endl;
	cout<<"Modelo: "<<a.modelo<<endl;
	cout<<"Año: "<<a.fecha<<endl;
	cout<<"Placa: "<<a.placa<<endl;
	cout<<"Numero de dueños: "<<a.duenos<<endl;
	cout<<"Tipo : "<<a.tipo<<endl;
	cout<<"Contiene: "<<a.aire<<endl;

}

class Camioneta : private Vehiculo {
       private:
       	int capacidad_D;
       	int ruedas;
       public:
       	Camioneta();
       	Camioneta(string mat, double ns, string m);
       	friend void setActualizarP(string);
		friend void setActualizarA(double);
		void setCapacidad(int nC);
		void setRuedas(int nR);
		void mostrarCamioneta();
        void mostrarDatosCamioneta(Camioneta *);
};
Camioneta::Camioneta(){
	matricula= "hgasfd";
	N_serie=102;
	modelo= "s/e";
	fecha=2019;
	placa="2016";
	ruedas=4;
	capacidad_D=452;
}


Camioneta::Camioneta(string mat, double ns, string m){
	matricula= mat;
	N_serie=ns;
	modelo= m;
	fecha=0;
	placa="S/E";
	capacidad_D=0;
	ruedas=0;
}


void Camioneta::setCapacidad(int nC){
	capacidad_D = nC;
}


void Camioneta::setRuedas(int nR){
	ruedas = nR;
}

void Camioneta:: mostrarCamioneta(){
    cout<<"DATOS DE CAMIONETA "<<endl;
	cout<<"Matricula: "<<matricula<<endl;
	cout<<"Numero de serie: "<<N_serie<<endl;
	cout<<"Modelo: "<<modelo<<endl;
	cout<<"Fecha: "<<fecha<<endl;
	cout<<"Placa: "<<placa<<endl;
	cout<<"Capacidad : "<<capacidad_D<<endl;
	cout<<"Numero de ruedas : "<<ruedas<<endl;

}

void Camioneta::mostrarDatosCamioneta(Camioneta *a)
{
	cout<<"DATOS DE CAMIONETA "<<endl;
	cout<<"Matricula: "<<a->matricula<<endl;
	cout<<"Numero de serie: "<<a->N_serie<<endl;
	cout<<"Modelo: "<<a->modelo<<endl;
	cout<<"Fecha: "<<a->fecha<<endl;
	cout<<"Placa: "<<a->placa<<endl;
	cout<<"Capacidad : "<<a->capacidad_D<<endl;
	cout<<"Numero de ruedas : "<<a->ruedas<<endl;
}

int main(){
	Auto co;
	Camioneta ca;
	string ma;
	double numS;
	string mod;
	int opc;
	do
	{
		cout << "Elija la opcion que desee "<< endl;
		cout << "1: Agregar auto" << endl;
		cout << "2: Agregar camioneta" << endl;
		cout << "3: Mostrar datos de auto" << endl;
		cout << "4: Mostrar datos de la camioneta" << endl;
		cout << "5: Actualizar datos de camioneta" << endl;
		cout << "6: Actualizar datos de auto" << endl;
		cout << "0: Salir" << endl;
		cin >> opc;
		switch(opc)
		{
			case 1:
				cout << "Ingrese datos: " << endl;
				cout << "Matricula: " << endl;
				cin >> ma;
				cout << "Numero de serie: " << endl;
				cin >> numS;
				cout << "Modelo: " << endl;
				cin >> mod;
				 Auto ObjAuto(char ma, double numS, string mod);
				break;
			case 2:
				cout << "Ingrese datos: " << endl;
				cout << "Matricula: " << endl;
				cin >> ma;
				cout << "Numero de serie: " << endl;
				cin >> numS;
				cout << "Modelo: " << endl;
				cin >> mod;
            	Camioneta nueva(char ma, double numS , string mod);
				break;
				case 3:
					co.mostrarAuto();
					break;
				case 4:
					///ca.mostrarDatosCamioneta(&nueva);
					break;
                case 5:
                    int cap,numR;
                    cout << "Capacidad de carga: ";
                    cin >> cap;
                    ca.setCapacidad(cap);
                    cout << "Numero de ruedas: ";
                    cin >> numR;
                    ca.setRuedas(numR);
                    break;
                case 6:
                    int total;
                    cout << "Total de propietarios: ";
                    cin >> total;
                    co.setTotalD(total);
                    if( co.tipoDeAuto() == true){
                        cout << "Tipo de auto estandar" << endl;
                    }
                    else{cout << "Tipo de auto automatico";}
                    cout << endl;
                    if(co.aire_a()==true){
                        cout << "Auto con aire acondicionado" << endl;
                    }
                    else{
                        cout << "Auto sin aire acondicionado" << endl;
                    }
                    break;
                case 0:
                    cout << "---Programa terminado---" << endl;
                    break;
                default:
                    cout << "Opcion invalida, ingrese nuevamente" << endl;
		}
	}while(opc != 0);

	return 0;
}