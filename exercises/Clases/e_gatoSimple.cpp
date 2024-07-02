#include <iostream>
using namespace std;

class GatoSimple {
    private:
        int suEdad;
    public:
        GatoSimple();
        ~GatoSimple();
};

GatoSimple::GatoSimple(){
    cout << "Se llamo al constructor.\n";
    suEdad = 1;
}

GatoSimple::~GatoSimple(){
    cout << "Se llamo al destructor.\n";
}

int main() {
    cout << "GatoSimple Pelusa...\n";
    GatoSimple Pelusa;
    cout << endl;

    cout << "GatoSimple *apFelix = new GatoSimple...\n";
    GatoSimple * apFelix = new GatoSimple;
    cout << endl;

    cout << "delete apFelix...\n";
    delete apFelix;
    cout << endl;
    
    cout << "saliendo, observe cómo se va Pelusa...\n";
    return 0;
}