#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    Persona(string n, int e) : nombre(n), edad(e) {}
};

class AnalizadorTamanios {
public:
    void analizar() {
        cout << "int: " << sizeof(int) << " bytes" << endl;
        cout << "float: " << sizeof(float) << " bytes" << endl;
        cout << "double: " << sizeof(double) << " bytes" << endl;
        cout << "char: " << sizeof(char) << " bytes" << endl;
        cout << "bool: " << sizeof(bool) << " bytes" << endl;
        cout << "long: " << sizeof(long) << " bytes" << endl;
        cout << "short: " << sizeof(short) << " bytes" << endl;
    }
    
    void analizarObjeto(Persona& p) {
        cout << "Objeto Persona: " << sizeof(p) << " bytes" << endl;
    }
};

int main() {
    AnalizadorTamanios a;
    a.analizar();
    
    Persona p("Juan", 25);
    a.analizarObjeto(p);
    return 0;
}
