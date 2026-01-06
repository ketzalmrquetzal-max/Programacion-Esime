#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre, ap;
    int edad;
    Persona(string n, string a, int e) : nombre(n), ap(a), edad(e) {}
    void mostrar() { cout << nombre << " " << ap << ", " << edad << " años" << endl; }
};

class Puntero {
private:
    Persona** arr;
    int pos, tam;
public:
    Puntero(Persona** a, int t) : arr(a), pos(0), tam(t) {}
    Persona* get() { return arr[pos]; }
    Persona* getAt(int i) { return arr[pos + i]; }
    void avanzar() { pos++; }
    void reset() { pos = 0; }
    int tamanio() { return tam; }
};

class ListaPersonasPuntero {
private:
    Persona* datos[10];
    int tam;
    Puntero* p;
public:
    ListaPersonasPuntero() : tam(0), p(nullptr) {}
    
    void agregar(Persona* per) {
        datos[tam++] = per;
        if (p) delete p;
        p = new Puntero(datos, tam);
    }
    
    void mostrar() {
        for (int i = 0; i < p->tamanio(); i++) {
            cout << "*p+" << i << ": ";
            p->getAt(i)->mostrar();
        }
    }
    
    ~ListaPersonasPuntero() { if (p) delete p; }
};

int main() {
    ListaPersonasPuntero lp;
    lp.agregar(new Persona("Juan", "Perez", 25));
    lp.agregar(new Persona("Maria", "Lopez", 30));
    lp.agregar(new Persona("Pedro", "Ramirez", 22));
    lp.mostrar();
    return 0;
}
