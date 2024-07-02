//recursion en un arreglo.
#include <iostream>
using namespace std;

int menorelemento(int arreglo[], int n)
{
	if (n == 0)
		return arreglo[n];
	return min(arreglo[n - 1], menorelemento(arreglo, n - 1));
}

int main()
{
	int n = 10;
	int arreglo[10] = {2, 33, 6, 1, 3, 0, -2, 11, 5, 15};
	cout << menorelemento(arreglo, n);

	return 0;
}