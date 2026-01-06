#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    Persona(string n = "", int e = 0) : nombre(n), edad(e) {}
};

class OrdenadorBurbujaIndirecto {
private:
    int* datos;
    int* indices;
    int tam;
public:
    OrdenadorBurbujaIndirecto(int arr[], int t) : tam(t) {
        datos = new int[t];
        indices = new int[t];
        for (int i = 0; i < t; i++) {
            datos[i] = arr[i];
            indices[i] = i;
        }
    }
    ~OrdenadorBurbujaIndirecto() { delete[] datos; delete[] indices; }
    
    void ordenar() {
        for (int i = 0; i < tam - 1; i++)
            for (int j = 0; j < tam - 1 - i; j++)
                if (datos[indices[j]] > datos[indices[j + 1]])
                    swap(indices[j], indices[j + 1]);
    }
    
    void mostrarOriginal() {
        cout << "Original: ";
        for (int i = 0; i < tam; i++) cout << datos[i] << " ";
        cout << endl;
    }
    
    void mostrarOrdenado() {
        cout << "Ordenado: ";
        for (int i = 0; i < tam; i++) cout << datos[indices[i]] << " ";
        cout << endl;
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    OrdenadorBurbujaIndirecto o(arr, 7);
    o.ordenar();
    o.mostrarOriginal();
    o.mostrarOrdenado();
    return 0;
}
