#include <iostream>
using namespace std;
///Clase cola circular
class ColaCircular {
    int *queue; ///Arreglo dinamico
    int min, max;
    int frente, fondo; /// apuntadores
public:
	///Definicion de funciones de la clase
    ColaCircular(int tam);
    void inserta_circular(int dato);
    int elimina_circular();
    void mostrarColaCircular();
    bool ColaCircularVacia();
    bool ColaCircularLlena();
};

///Implementacion de funciones de la clase de manera offline
ColaCircular::ColaCircular(int tam) {
    queue = new int[tam];
    min = 0;
    max = tam-1;
    frente = fondo = min;
}

void ColaCircular::inserta_circular(int dato) {
        /// SE VERIFICAN LOS DOS ESTADOS PARA QUE LA COLA ESTÉ LLENA
        /// 1) QUE frente SEA IGUAL A min Y fondo SEA IGUAL A max+1
        /// 2) QUE frente Y fondo SEAN IGUALES, PERO DIFERENTES A LA POSICIÓN 0
        if ( !ColaCircularLlena() ){
        /// SE VERIFICA SI HAY ESPACIO PARA MOVER fondo A LA POSICIÓN 0
            if ( fondo>max )
                fondo = 0;
            /// SE HACE LA INSERCIÓN Y SE MUEVE fondo HACIA ADELANTE
            queue[fondo++] = dato;
        }
        else {
        	cout << "\nCola Circular llena!!!\n";
        }
}

bool ColaCircular::ColaCircularLlena() { 
	return (frente==min && fondo==(max+1)) || (frente>min && fondo==frente); ///Condiciones para comprobar si la cola
																			//// esta llena
}

bool ColaCircular::ColaCircularVacia() { 
	return (frente==min && fondo==min ); ///Condiciones para comprobar si la cola esta vacia
}

int ColaCircular::elimina_circular() {
    int dato =  INT_MAX;
    /// SE VERIFICAN EL ÚNICO ESTADOS PARA QUE LA COLA ESTÉ VACÍA
    /// SI frente Y fondo ESTÁN EN LA POSICIÓN 0
    if ( !ColaCircularVacia() ){
    	/// SE REMUEVE EL DATO Y SE MUEVE frente HACIA ADELANTE
        dato = queue[frente++];
        /// SI DESPUES DE MOVER frente RESULTA IGUAL A FONDO
        /// SIGNIFICA QUE YA LO ALCANZÓ Y LA COLA ESTÁ VACÍA
        /// POR LO QUE VUELVE AL ESTADO INICIAL
        if ( frente==fondo )
            frente = fondo = 0;
        else
            /// SINO, QUEDA LA POSIBILIDAD QUE HAYA AL MENOS UN
            /// DATO EN LA POSICIÓN 0
            ///
            /// NOTA: RECUERDA QUE frente SÓLO APUNTA A 0 CUANDO
            ///       SE TRATA DEL ESTADO INICIAL
            if ( frente>max )
                frente = 0;
	}
    else {
    	cout << "\nCola Circular vacia!!!";
    }

    return dato;
}

void ColaCircular::mostrarColaCircular() {
    cout << "\n| ";
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

    cout << "|\n";
}

int main() {
    ColaCircular cc1(5);

    cc1.mostrarColaCircular();

    /// SE LLENA LA COLA
    cout << "\nSe inserta 1";   cc1.inserta_circular(1);
    cout << "\nSe inserta 2";   cc1.inserta_circular(2);
    cout << "\nSe inserta 3";   cc1.inserta_circular(3);
    cout << "\nSe inserta 4";   cc1.inserta_circular(4);
    cout << "\nSe inserta 5";   cc1.inserta_circular(5);

    cout << endl;
    cc1.mostrarColaCircular();

    /// SE INTENTA INSERTAR UN DATO CON LA COLA LLENA
    cout << "\nSe inserta 6";   cc1.inserta_circular(6);

    /// SE ELIMINAN 3 DATOS
    cout << "\nDato borrado: " << cc1.elimina_circular();
    cout << "\nDato borrado: " << cc1.elimina_circular();
    cout << "\nDato borrado: " << cc1.elimina_circular();

    cout << endl;
    cc1.mostrarColaCircular();

    /// SE ELIMINAN 2 DATOS
    cout << "\nDato borrado: " << cc1.elimina_circular();
    cout << "\nDato borrado: " << cc1.elimina_circular();
    /// SE ELIMINA 1 DATO CON LA COLA VACÍA
    cout << "\nDato borrado: " << cc1.elimina_circular();

    cout << endl;
    cc1.mostrarColaCircular();

    /// SE VUELVE A LLENAR LA COLA
    cout << "\nSe inserta 7";   cc1.inserta_circular(7);
    cout << "\nSe inserta 8";   cc1.inserta_circular(8);
    cout << "\nSe inserta 9";   cc1.inserta_circular(9);
    cout << "\nSe inserta 10";  cc1.inserta_circular(10);
    cout << "\nSe inserta 11";  cc1.inserta_circular(11);

    cout << endl;
    cc1.mostrarColaCircular();

    /// SE ELIMINAN 2 DATOS
    cout << "\nDato borrado: " << cc1.elimina_circular();
    cout << "\nDato borrado: " << cc1.elimina_circular();

    cout << endl;
    cc1.mostrarColaCircular();

    /// SE INSERTAN 2 DATOS EN LAS POSICIONES DESOCUPADAS
    cout << "\nSe inserta 12";   cc1.inserta_circular(12);
    cout << "\nSe inserta 13";   cc1.inserta_circular(13);

    cout << endl;
    cc1.mostrarColaCircular();

    cout << "\nSe inserta 14";   cc1.inserta_circular(14);
    cout << "\nDato borrado: " << cc1.elimina_circular();

    cout << endl;
    cc1.mostrarColaCircular();

    cout << "\nSe inserta 14";   cc1.inserta_circular(14);

    cout << endl;
    cc1.mostrarColaCircular();

    return 0;
}