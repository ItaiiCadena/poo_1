#include <iostream>
using namespace std;

long Ackerman(int m, int n) {
    if(m==0)
      return n+1;
    else
        if(n==0)
           return Ackerman(m-1, 1);
        else
           return Ackerman(m-1, Ackerman(m, n-1));
}

int main() {
    int m, n, num ;
    cout<<"* * * FUNCION DE ACKERMAN * * *\n\n";
    cout<<"Introduce <m>: ";
    cin>> m ;
    cout<<"Introduce <n>: ";
    cin>> n ;

    num = Ackerman(m,n);
    cout<<"\nEl numero es: "<< num <<endl;

	return 0;
}