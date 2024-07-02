#include <iostream>
using namespace std;

int factorial(int n);

int main() {
    int num;
    cout << "* * * FACTORIAL * * *\n";
    cout << "Introduce un numero: ";
    cin >> num;

    int fact = factorial(num);
    cout << "\nSu factorial es: " << fact << "\n";

    return 0;
}

/// FUNCIÓN RECURSIVA
int factorial(int n) {
    if (n==0)                   /// <-- CASO BASE (no recursivo)
        return 1;
    return n*factorial(n-1);    /// <-- CASO GENERAL (recursivo)
}