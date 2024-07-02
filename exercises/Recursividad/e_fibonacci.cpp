#include <iostream>
using namespace std;

int Fibonacci(int n) {
    if (n<=1)
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main() {
    int num=0,res=0;
    cout << "* * * SERIE DE FIBONACCI * * *\n" << endl;
    cout << "Introduce la posición: ";
    cin >> num;

    for(int i=0;i<=num;i++) {
        res = Fibonacci(i);
        cout <<"\t " << res;
    }

    cout <<"\n";
    return 0;
}