#include <iostream>
using namespace std;
#ifndef CLASSGATO_H 
#define CLASSGATO_H
class gatos
{
	public:
		gatos(){};
		~gatos(){};
		void maulla()
		{
			cout << "Yo muerdo." << endl;
		}
};
#endif //Cierre del if 

#include "classGato.h"
int main()
{
	Gato felix;
	felix.maulla();
	return 0;
}