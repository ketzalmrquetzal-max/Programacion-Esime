#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persona {
public:
    string nombre, ap;
    int edad;
    Persona(string n, string a, int e) : nombre(n), ap(a), edad(e) {}
    void mostrar() { cout << nombre << " " << ap << ", " << edad << " años" << endl; }
};

class Coche {
public:
    string marca, modelo;
    int anio;
    Coche(string m, string mod, int a) : marca(m), modelo(mod), anio(a) {}
    void mostrar() { cout << marca << " " << modelo << " (" << anio << ")" << endl; }
};

class ListaPersonas {
private:
    vector<Persona> personas;
public:
    void agregar(Persona p) { personas.push_back(p); }
    void mostrar() {
        for (int i = 0; i < personas.size(); i++) {
            cout << "[" << i << "] "; personas[i].mostrar();
        }
    }
};

class ListaCoches {
private:
    vector<Coche> coches;
public:
    void agregar(Coche c) { coches.push_back(c); }
    void mostrar() {
        for (int i = 0; i < coches.size(); i++) {
            cout << "[" << i << "] "; coches[i].mostrar();
        }
    }
};

int main() {
    ListaPersonas lp;
    lp.agregar(Persona("Juan", "Perez", 25));
    lp.agregar(Persona("Maria", "Lopez", 30));
    lp.mostrar();
    
    ListaCoches lc;
    lc.agregar(Coche("Honda", "Civic", 2022));
    lc.agregar(Coche("Toyota", "Corolla", 2021));
    lc.mostrar();
    return 0;
}
