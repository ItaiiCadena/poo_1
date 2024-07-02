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

/// FUNCIÓN ITERATIVA
int factorial(int n) {
    int res = 1;
    for(int i=2; i<=n; i++) {
        res = res*i;
    }
    return res;
}
