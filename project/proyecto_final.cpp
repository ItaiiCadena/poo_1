#include <iostream>
#include <climits>
#include <math.h>
#include <windows.h>
using namespace std;

///Template de la clase pila
template <class T>
class Pila{ ///Atributos
    T *stack;
    int tope, max;
public: ///Definicion de metodos
    Pila();
    void push(T dato);
    int pop();
    void mostrarPila();
    bool pilaVacia();
    bool pilaLlena();
};

///Implementacion de metodos
template <class T> ///Constructor
Pila<T>::Pila() {
    stack = new T[20];
    max = 20-1;
    tope = 0;
}

template <class T> ///Funcion para saber si la pila esta llena
bool Pila<T>::pilaLlena() {
    return tope>max;
}

template <class T> ///Funcion para saber si la pila esta vacia
bool Pila<T>::pilaVacia() {
    return tope<=0;
}

template <class T> ///Funcion para agregar datos en la pila
void Pila<T>::push(T dato) {
    if ( !pilaLlena() )
        stack[tope++] = dato;
    else
        cout << "\nPila Llena!!!\n";
}

template <class T> ///Funcion para eliminar datos de la pila
int Pila<T>::pop() {
    int dato =  INT_MAX;
    if ( !pilaVacia() )
        dato = stack[--tope];
    else
        cout << "\nPila Vacia!!!\n";

    return dato;
}

template <class T> ///Funcion que muestra los valores contenidos dentro de la pila
void Pila<T>::mostrarPila() {
    cout << "\n   ---\n";
    for (int i=tope-1; i>=0; i--)
        cout << stack[i] << "    \n";
    cout << "   ---\n";
}

//////////////////////////////////////////////////////////////////////////////////////
///Clase cola circular
class ColaCircular {
    ///Atributos
    char *queue;
    int min, max;
    int frente, fondo;
public: ///Definicion de metodos
    ColaCircular();
    void inserta_circular(int dato);
    int elimina_circular();
    void mostrarColaCircular();
    bool ColaCircularVacia();
    bool ColaCircularLlena();
};

///Implementacion de metodos
ColaCircular::ColaCircular() { ///Constructor
    queue = new char[20];
    min = 0;
    max = 20-1;
    frente = fondo = min;
}

bool ColaCircular::ColaCircularLlena() { ///Funcion para saber si la cola esta llena
	return (frente==min && fondo==(max+1)) || (frente>min && fondo==frente);
}

bool ColaCircular::ColaCircularVacia() { ///Funcion para saber si la cola esta vacia
	return (frente==min && fondo==min );
}

void ColaCircular::inserta_circular(int dato) { ///Funcion para insertar datos en la cola
        if ( !ColaCircularLlena() ){
            if ( fondo>max )
                fondo = 0;
            queue[fondo++] = dato;
        }
        else {
        	cout << "\nCola Circular llena!!!\n";
        }
}

int ColaCircular::elimina_circular() { ///Funcion para eliminar datos de la cola
    int dato =  INT_MAX;
    if ( !ColaCircularVacia() ){
        dato = queue[frente++];
        if ( frente==fondo )
            frente = fondo = 0;
        else
            if ( frente>max )
                frente = 0;
	}
    else {
    	cout << "\nCola Circular vacia!!!";
    }

    return dato;
}

void ColaCircular::mostrarColaCircular() { ///Funcion para mostrar los datos contenidos en la cola
    cout << "\n       | ";
    if (frente<fondo)
        for (int i=frente; i<fondo; i++)
            cout << queue[i] << " ";
    else
        if (frente>=fondo && frente!=min) {
            for (int i=frente; i<=max; i++)
                cout << queue[i] << " ";
            for (int i=min; i<fondo; i++)
                cout << queue[i] << " ";
        }

    cout << "|\n\n";
}

/////////////////////////////////////////////////////////////////////////////////////
///Clase para convertir la expresion en posfijo
class ConvertirPosfijo {
	private: ///Atributos, objetos dinamicos de las clases pila y cola
		ColaCircular *EIN;
		ColaCircular *EPOS;
		Pila <char> *OPERADORES;
		Pila<int> *pilaEvaluacion;
	public:///Definicion de metodos
		ConvertirPosfijo();
		void Conv_posfijo(ColaCircular *EIN,ColaCircular *EPOS);
		int precedencia(char);
		bool isOperator(char);
		Pila<int> asignaValores(ColaCircular*);
		float evaluarPosfijo(ColaCircular*, Pila<int>);
};

///Implementacion de metodos
ConvertirPosfijo::ConvertirPosfijo(){///Constructor
	this -> EIN = new ColaCircular;
	this -> EPOS = new ColaCircular;

}
int ConvertirPosfijo::precedencia(char c){ ///Funcion para saber la precedencia o proridad de los operadores
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
    return -1; ///Si no esta el operador retornara -1
}

bool ConvertirPosfijo::isOperator(char c){ ///Funcion para saber si el caracter es un operador
    if(c == '+'||c == '-'||c == '/'||c == '*'||c == '^')
        return true;
    return false;
}

void ConvertirPosfijo::Conv_posfijo(ColaCircular *EIN, ColaCircular *EPOS){ ///Funcion para convertir la expresion infija a posfija
    this->OPERADORES = new Pila <char>; ///Objeto dinamico para guardar operadores
    char SIMBOLO; ///Para manejar caracteres

    while(!EIN->ColaCircularVacia() ){
	    SIMBOLO = EIN->elimina_circular(); ///El elemento que se elimina se inserta en el caracter simbolo
	    if(SIMBOLO == '('){ ///Condicional primero para evaluar el caracter
	    	OPERADORES->push(SIMBOLO);
		}
		else{
			if(SIMBOLO==')'){
				do{
					SIMBOLO=OPERADORES->pop();
					if(SIMBOLO!='('){
						EPOS->inserta_circular(SIMBOLO);
					}
				} while(SIMBOLO=='(');
            OPERADORES->pop(); ///Para eliminar el parentesis "(" de la expresion
			}
			else{
				if(SIMBOLO!= '(' && ')' && isOperator(SIMBOLO)!= true){
					EPOS->inserta_circular(SIMBOLO);
				}
				else{
					if(OPERADORES->pilaVacia()){
						OPERADORES->push(SIMBOLO);
					}
				else{
					char SIMBOLO2;
					SIMBOLO2=OPERADORES->pop();
					while(!OPERADORES->pilaVacia() && precedencia(SIMBOLO) <= precedencia(SIMBOLO2) ){
						EPOS->inserta_circular(SIMBOLO2);
						SIMBOLO2=OPERADORES->pop();
					}
					if(precedencia(SIMBOLO)>precedencia(SIMBOLO2)){
						OPERADORES->push(SIMBOLO2);
					}
					else{
						EPOS->inserta_circular(SIMBOLO2);
					}
					OPERADORES->push(SIMBOLO);
				}
                }
			}
		}
	}
	while(!OPERADORES->pilaVacia()){
		EPOS->inserta_circular(OPERADORES->pop());
	}
}

Pila<int> ConvertirPosfijo::asignaValores(ColaCircular *EPOS){ ///Funcion para asignar valores a la expresion posfija
    Pila<int> valores; ///Para  guardar valores
    ColaCircular *operador = new ColaCircular; ///Para guardar valores que se eliminen de EPOS
    int num;
    char c;
        while(!EPOS->ColaCircularVacia()){
            c = EPOS->elimina_circular();
            if(isOperator(c)!=true){ ///Si el caracter no es un operador
                cout << "\n    Ingrese valor para " << c << ": " <<endl;
                cin >> num;
                valores.push(num); ///Ingresa el valor en la pila
                operador->inserta_circular(c); ///ingresa el caracter en la cola
            }else if(isOperator(c)== true){
                operador->inserta_circular(c); ///Ingresa caracter en la cola
            }
        }
    while(!operador->ColaCircularVacia()){ ///Llena nuevamente EPOS con los datos que tenia
        EPOS->inserta_circular(operador->elimina_circular());
    }
    return valores; ///Retorna la pila
}

float ConvertirPosfijo::evaluarPosfijo(ColaCircular *EPOS, Pila<int> valores){ ///Funcion para evaluar la expresion
    pilaEvaluacion = new Pila<int>; ///Para guardar el resultado
    Pila<int> valoresFin; ///Para acomodar los valores
    while(!valores.pilaVacia()){ ///Acomodando los valores de la expresion
        valoresFin.push(valores.pop());
    }
        while(!EPOS->ColaCircularVacia()){
            char x = EPOS->elimina_circular();
            if(isOperator(x)!=true){ ///Evalua caracter distinto de operador
                pilaEvaluacion->push(valoresFin.pop()); ///Guarda valores
            }else if(isOperator(x)==true){ ///Evalua caracter distinto de operando
                int a = pilaEvaluacion->pop(); ///Saca dos elementos de la pila para hacer la operacion
                int b = pilaEvaluacion->pop();
                char op = x;
                switch(op){
                case '-':
                    pilaEvaluacion->push(b-a); ///Guarda el resultado en la pila nuevamente
                break;
                case '+':
                    pilaEvaluacion->push(b+a);
                break;
                case '/':
                    pilaEvaluacion->push(b/a);
                break;
                case '*':
                    pilaEvaluacion->push(b*a);
                break;
                case '^':
                    pilaEvaluacion->push(pow(b,a));
                break;
                }
            }
        }
    if(!pilaEvaluacion->pilaVacia())
        return pilaEvaluacion->pop(); ///Retorna el resultado
    else
        return 0; ///Si ocurre un error en el codigo retorna 0
}

////////////////////////////////////////////////////////////////////////////
int main() {
	char dummy;
	ColaCircular *EIN=new ColaCircular; ///INFIJO objeto dinamico de la clase cola
	ColaCircular *EPOS=new ColaCircular; ///POSFIJO objeto dinamico de la clase cola
	ConvertirPosfijo *posfi = new ConvertirPosfijo; ///Objeto dinamico de la clase Convertir posfijo
	Pila<int> VALORES; ///objeto de la clase pila
	char c;
	int opcion, i=0; ///para manejo en switch

    do {

        cout << "\n        Menu de Opciones         \n" << endl;
        cout << " 1)  Insertar una expresion aritmetica (infijo) " << endl;
        cout << " 2)  Mostrar la expresion en infijo  " << endl;
        cout << " 3)  Transformar de Infijo a Posfijo " << endl;
        cout << " 4)  Mostrar la expresion en Posfijo " << endl;
        cout << " 5)  Asignar valores a los operandos " << endl;
        cout << " 6)  Evaluar la expresion en posfijo " << endl;
        cout << " 0)  Salir "<< endl;

        cout << "\n  Ingrese una opcion: ";
        cin >> opcion;
        system("cls");
        switch (opcion) {
            case 1:
                system("cls");
            	cin.get(dummy);
            	cout<<"\n     Insertar una expresion aritmetica"<<endl;
            	cin.get(c);
            	while(i<20 && c!='\n'){ ///Para guardar caracter por caracter en el objeto cola
                     EIN->inserta_circular(c);
                     i++;
                     cin.get(c);
            	}
            	system("pause");
                break;
            case 2:
                system("cls");
            	cout<<"\n     Los simbolos ingresados en infijo son : "<<endl;
            	EIN->mostrarColaCircular();
            	system("pause");
                break;

            case 3:
                system("cls");
                cout<<"\n     Transformando..."<<endl;
                posfi->Conv_posfijo(EIN,EPOS);
                system("pause");
				break;

            case 4:
                system("cls");
                cout <<"\n    La expresion en posfijo es: " << endl;
                EPOS->mostrarColaCircular();
                system("pause");
                break;

             case 5:
                system("cls");
                VALORES = posfi->asignaValores(EPOS);
                system("pause");
                break;

             case 6:
                system("cls");
                cout << "\n    El resultado de la operacion es: ";
                cout << posfi->evaluarPosfijo(EPOS,VALORES);
                cout << endl;
                system("pause");
                break;

             case 0:
                system("cls");
                cout << "      ---PROGRAMA TERMINADO---" << endl;
                system("pause");
                break;

            default:
                system("cls");
                cout << "\n\nValor no valido, ingrese nuevamente" << endl;
                system("pause");
                break;
        }

    } while ( opcion!=0 );

    return 0;

}