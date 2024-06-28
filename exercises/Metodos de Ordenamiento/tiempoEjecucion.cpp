#include <iostream>
#include <ctime>
using namespace std;

int main(){
	unsigned t0, t1;
	t0 = clock();
	 	///Invocacion del metodo de ordenamiento
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "\nExecution Time: " << time << " (" << t1 << "-" << t0 << ")" << endl;
	return 0;
}