#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre, ap, am, genero;
    int edad;
public:
    Persona(string n, string a, string am, string g, int e)
        : nombre(n), ap(a), am(am), genero(g), edad(e) {}
    
    string nombreCompleto() {
        return nombre + " " + ap + " " + am;
    }
    
    void mostrar() {
        cout << nombreCompleto() << ", " << edad << " años" << endl;
    }
};

class Auto {
private:
    string marca, modelo;
    double precio;
    int anio;
public:
    Auto(string m, string mod, double p, int a)
        : marca(m), modelo(mod), precio(p), anio(a) {}
    
    void mostrar() {
        cout << marca << " " << modelo << " (" << anio << ") - $" << precio << endl;
    }
};

int main() {
    Persona p("Hugo", "Dominguez", "Lopez", "M", 19);
    p.mostrar();
    
    Auto a("Honda", "Civic", 350000, 2022);
    a.mostrar();
    return 0;
}
