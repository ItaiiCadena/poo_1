#include <iostream>
using namespace std;

//Declaracion del producto como estructura
struct Producto {
	string nombre;
	int id = 0;
	float precio;
	int stock;
	string departamento;
};
 
void insertProducto( int id, Producto *array,int pos){
	string nombre, departamento;
	float precio;
	int stock;
	char dummy;
	cout << "Nombre: "; cin >> nombre;
	cin.get(dummy);
	cout << "Precio: "; cin >> precio;
	cin.get(dummy);
	cout << "Stock: "; cin >> stock;
	cin.get(dummy);
	cout << "Departamento: "; cin >> departamento;
	cin.get(dummy);

	array[pos].id = id;
	//Al producto asignarle los valores que el usuario esta ingresando
	array[pos].nombre = nombre;
	array[pos].precio = precio;
	array[pos].stock = stock;
	array[pos].departamento = departamento;
}	

void setNombre(int id, string nombre, Producto *array_prod){
	int i = 0;
	bool found = false;

	while(i < 20){
		if(array_prod[i].id == id){
			found = true;
			break;
		}
		i++;
	}

	if(found == true){
		array_prod[i].nombre = nombre;
	} else {
		cout << "No se encontro un producto con ese ID" << endl;
	}
}

void mostrarProductos(Producto *array_prod){
	int i = 0;
	while( i < 20){
		if(array_prod[i].id != 0){
			cout << "ID: " << array_prod[i].id << endl;
			cout << "Nombre: " << array_prod[i].nombre << endl;
			cout << "Precio: " << array_prod[i].precio << endl;
			cout << "Stock: " << array_prod[i].stock << endl;
			cout << "Departamento: " << array_prod[i].departamento << endl;
			cout << endl;
		}
		else {
			break;
		}
		i++;
	}
}

int main(){
	//Vector de productos, contiene elementos de tipo Producto - struct Producto
	struct Producto array_prod[20];
	
	//Variables necesarias para manejo del programa
	int op, stock, id_mod;
	int id_increment = 1, pos = 0;
	string nombre, departamento, n_nom;
	float precio;
	char dummy;
	
	do {
		cout << "\t\n-----------TIENDA--------------" << endl;
		cout << "1. Insertar producto" << endl;
		cout << "2. Mostrar producto" << endl;
		cout << "3. Modificar nombre" << endl;
		cout << "0. Salir" << endl;
		cin >> op;
		cin.get(dummy);
			
		switch(op){
			case 1:
				cout << "Ingrese los siguientes datos..." << endl;
				insertProducto(id_increment, array_prod, pos);
				//Incrementar mis variables controladoras del id y la pos
				id_increment++;
				pos++;
				cout << "El producto se registro correctamente..." << endl;
				break;
			case 2:
				cout << "\nMostrando productos" << endl;
				//1. Ordenar los productos de menor a mayor de acuerdo al precio
				//2. Utilizar un for para recorrer el array o vector
				mostrarProductos(array_prod);
				break;
			case 3:
				cout << "ID del producto a modificar: "; cin >> id_mod;
				cout << "Ingresa el nuevo nombre: "; cin >> n_nom;
				setNombre(id_mod, n_nom, array_prod);
				break;	
			case 0:
				cout << "\nPrograma terminado" << endl;
				break;
			default:
				cout << "Opcion no valida, ingrese de nuevo" << endl;
				break;
					
		}
		
	} while(op != 0);
	
	return 0;
}