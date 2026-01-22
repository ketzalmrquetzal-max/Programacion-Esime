#include <iostream>
#include <string>
using namespace std;

class Saludo {
private:
    string mensaje;
public:
    Saludo(string msg = "Hola Mundo") : mensaje(msg) {}
    
    void mostrar() {
        cout << mensaje << endl;
    }
    
    string saludarPersona(string nombre) {
        return "Hola " + nombre;
    }
};

int main() {
    Saludo s;
    s.mostrar();
    cout << s.saludarPersona("Hugo") << endl;
    return 0;
}
