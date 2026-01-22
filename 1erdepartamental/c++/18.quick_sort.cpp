#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    Persona(string n = "", int e = 0) : nombre(n), edad(e) {}
};

class OrdenadorQuickSort {
private:
    int* datos;
    int tam;
    
    int partition(int low, int high) {
        int pivot = datos[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (datos[j] < pivot) {
                i++;
                swap(datos[i], datos[j]);
            }
        }
        swap(datos[i + 1], datos[high]);
        return i + 1;
    }
    
    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }
public:
    OrdenadorQuickSort(int arr[], int t) : tam(t) {
        datos = new int[t];
        for (int i = 0; i < t; i++) datos[i] = arr[i];
    }
    ~OrdenadorQuickSort() { delete[] datos; }
    
    void ordenar() { quickSort(0, tam - 1); }
    
    void mostrar() {
        for (int i = 0; i < tam; i++) cout << datos[i] << " ";
        cout << endl;
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    OrdenadorQuickSort o(arr, 7);
    o.ordenar();
    cout << "Enteros: "; o.mostrar();
    return 0;
}
