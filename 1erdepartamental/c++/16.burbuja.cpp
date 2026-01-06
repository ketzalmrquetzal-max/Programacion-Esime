#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    Persona(string n = "", int e = 0) : nombre(n), edad(e) {}
};

class OrdenadorBurbuja {
private:
    int* datos;
    int tam;
public:
    OrdenadorBurbuja(int arr[], int t) : tam(t) {
        datos = new int[t];
        for (int i = 0; i < t; i++) datos[i] = arr[i];
    }
    ~OrdenadorBurbuja() { delete[] datos; }
    
    void ordenar() {
        for (int i = 0; i < tam - 1; i++)
            for (int j = 0; j < tam - 1 - i; j++)
                if (datos[j] > datos[j + 1])
                    swap(datos[j], datos[j + 1]);
    }
    
    void mostrar() {
        for (int i = 0; i < tam; i++) cout << datos[i] << " ";
        cout << endl;
    }
};

class OrdenadorBurbujaPersonas {
private:
    Persona* personas;
    int tam;
public:
    OrdenadorBurbujaPersonas(Persona arr[], int t) : tam(t) {
        personas = new Persona[t];
        for (int i = 0; i < t; i++) personas[i] = arr[i];
    }
    ~OrdenadorBurbujaPersonas() { delete[] personas; }
    
    void ordenarPorEdad() {
        for (int i = 0; i < tam - 1; i++)
            for (int j = 0; j < tam - 1 - i; j++)
                if (personas[j].edad > personas[j + 1].edad)
                    swap(personas[j], personas[j + 1]);
    }
    
    void mostrar() {
        for (int i = 0; i < tam; i++)
            cout << personas[i].nombre << "(" << personas[i].edad << ") ";
        cout << endl;
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    OrdenadorBurbuja o(arr, 7);
    o.ordenar();
    cout << "Enteros: "; o.mostrar();
    
    Persona pers[] = {Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)};
    OrdenadorBurbujaPersonas op(pers, 3);
    op.ordenarPorEdad();
    cout << "Por edad: "; op.mostrar();
    return 0;
}
