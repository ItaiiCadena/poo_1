#include <iostream>
using namespace std;

///Clase Estudiante
class Estudiante{
	private:
		string nombre;
		int matricula;
		string facultad;
	public:
		Estudiante();
		Estudiante(string, int, string);
		string getNombre();
		int getMatricula();
		string getFacultad();
};

	Estudiante::Estudiante()
	{
		nombre = facultad = "";
		matricula = 0;
	}
	
	Estudiante::Estudiante(string nombre, int matricula, string facultad)
	{
		this -> nombre = nombre;
		this -> matricula = matricula;
		this -> facultad = facultad;
	}
	
	string Estudiante::getNombre()
	{
		return nombre;
	}
	
	int Estudiante::getMatricula()
	{
		return matricula;
	}
	
	string Estudiante::getFacultad()
	{
		return facultad;
	}
	
	
class Facultad{
	private:
		string nombre;
		int noEstudiantes;
		Estudiante *estudiantes;
	public:
		Facultad();
		Facultad(string, Estudiante *, int);
		string getNombre();
		int getNoEstudiantes();
		Estudiante* getEstudiantes();
};

	Facultad::Facultad()
	{
		nombre = "";
		estudiantes = NULL;
	}
	
	Facultad::Facultad(string nombre, Estudiante *estudiantes, int noEstudiantes)
	{
		this->nombre = nombre;
		this->noEstudiantes = noEstudiantes;
		this->estudiantes = estudiantes;
	}
	
	string Facultad::getNombre()
	{
		return nombre;
	}
	
	int Facultad::getNoEstudiantes()
	{
		return noEstudiantes;
	}
	
	Estudiante* Facultad::getEstudiantes()
	{
		return estudiantes;
	}
	
	
class Universidad{
	private:
		string nombre;
		int noFacultades;
		Facultad *facultades;
	public:
		Universidad();
		Universidad(string, Facultad *, int);
		string getNombre();
		int getNoFacultades();
		Facultad* getFacultades();
		int getTotalEstudiantesUniversidad();
};

	Universidad::Universidad()
	{
		nombre = "";
		facultades = NULL;
	}
	
	Universidad::Universidad(string nombre, Facultad *facultades, int noFacultades)
	{
		this->nombre = nombre;
		this->noFacultades = noFacultades;
		this->facultades = facultades;
	}
	
	string Universidad::getNombre()
	{
		return nombre;
	}
	
	int Universidad::getNoFacultades()
	{
		return noFacultades;
	}
	
	Facultad* Universidad::getFacultades()
	{
		return facultades;
	}
	
	int Universidad::getTotalEstudiantesUniversidad()
	{
		int noEstudiantes = 0;
		Estudiante *est;
		for(int i=0; i<noFacultades; i++)
		{
			noEstudiantes += facultades[i].getNoEstudiantes();
			est = facultades[i].getEstudiantes();
			for(int j=0; j<facultades[i].getNoEstudiantes(); j++)
			{
				cout << "Nombre: " << est[j].getNombre() << endl;
				cout << "Matricula: " << est[j].getMatricula() << endl;
				cout << "Facultad: " << est[j].getFacultad() << endl;
				cout << endl;
			}
		}
		
		return noEstudiantes;
	}
	
	
	int main(){
		Estudiante *e1 = new Estudiante("Mia",101,"FCC");
		Estudiante *e2 = new Estudiante("Melanie",102,"FCC");
		Estudiante *e3 = new Estudiante("John",103,"FCE");
		Estudiante *e4 = new Estudiante("Raul",104,"FCE");
		
		///Se crea la lista de estudiantes de la FCC
		Estudiante *fcc_students = new Estudiante[2];
		fcc_students[0] = *e1;
		fcc_students[1] = *e2;
		
		///Se crea la lista de estudiantes de la FCE
		Estudiante *fce_students = new Estudiante[2];
		fce_students[0] = *e3;
		fce_students[1] = *e4;
		
		//Se crean dos facultades y se les asigna sus lista de estudiantes
		Facultad *FCC = new Facultad("FCC", fcc_students,2);
		Facultad *FCE = new Facultad("FCE", fce_students,2);
		
		//Se crea la lista de Facultades para la BUAP
		Facultad *buap_facultades = new Facultad[2];
		buap_facultades[0] = *FCC;
		buap_facultades[1] = *FCE;
		
		//Se crea la universidad BUAP con su lista de facultades
		Universidad *uni = new Universidad("BUAP", buap_facultades, 2);
		int Total = uni->getTotalEstudiantesUniversidad();
		cout << "Total de estudiantes en la " << uni -> getNombre() << ": " << Total;
		
		return 0; 
		
	}