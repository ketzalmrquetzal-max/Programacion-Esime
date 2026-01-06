#include <iostream>
using namespace std;

class Puntero {
private:
    double* arr;
    int pos;
    int tam;
public:
    Puntero(double* a, int t) : arr(a), pos(0), tam(t) {}
    
    double get() { return arr[pos]; }
    double getAt(int i) { return arr[pos + i]; }
    void setAt(int i, double val) { arr[pos + i] = val; }
    void avanzar() { pos++; }
    void reset() { pos = 0; }
    int tamanio() { return tam; }
};

class EstadisticasPuntero {
private:
    Puntero* p;
public:
    EstadisticasPuntero(double* arr, int tam) {
        p = new Puntero(arr, tam);
    }
    
    ~EstadisticasPuntero() { delete p; }
    
    double suma() {
        double total = 0;
        for (int i = 0; i < p->tamanio(); i++) total += p->getAt(i);
        return total;
    }
    
    double promedio() { return suma() / p->tamanio(); }
    
    double maximo() {
        double m = p->getAt(0);
        for (int i = 1; i < p->tamanio(); i++)
            if (p->getAt(i) > m) m = p->getAt(i);
        return m;
    }
    
    double minimo() {
        double m = p->getAt(0);
        for (int i = 1; i < p->tamanio(); i++)
            if (p->getAt(i) < m) m = p->getAt(i);
        return m;
    }
};

int main() {
    double arr[] = {10, 25, 5, 30, 15};
    EstadisticasPuntero e(arr, 5);
    cout << "Suma: " << e.suma() << endl;
    cout << "Promedio: " << e.promedio() << endl;
    cout << "Maximo: " << e.maximo() << endl;
    cout << "Minimo: " << e.minimo() << endl;
    return 0;
}
