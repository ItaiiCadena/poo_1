#include <iostream>
using namespace std;

int impar(int numi);

int par(int nump) {
    if (nump==0)
        return 1;
    return impar(nump-1);
}

int impar(int numi) {
    if (numi==0)
        return 0;
    return par(numi-1);
}

int main() {
    int num;
    cout<<"* * * PAR O IMPAR * * *\n\n";
    cout<<"Introduce un numero entero: ";
    cin>> num;

    int res = par(num);
    if (res==1)
        cout << endl << num << " es par.";
    else
        cout << endl << num << " es impar.";

    return 0;
}