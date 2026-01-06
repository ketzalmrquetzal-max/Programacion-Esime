#include <iostream>
using namespace std;

class OrdenadorQuickSortIndirecto {
private:
    int* datos;
    int* indices;
    int tam;
    
    int partition(int low, int high) {
        int pivot = datos[indices[high]];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (datos[indices[j]] < pivot) {
                i++;
                swap(indices[i], indices[j]);
            }
        }
        swap(indices[i + 1], indices[high]);
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
    OrdenadorQuickSortIndirecto(int arr[], int t) : tam(t) {
        datos = new int[t];
        indices = new int[t];
        for (int i = 0; i < t; i++) { datos[i] = arr[i]; indices[i] = i; }
    }
    ~OrdenadorQuickSortIndirecto() { delete[] datos; delete[] indices; }
    
    void ordenar() { quickSort(0, tam - 1); }
    
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
    OrdenadorQuickSortIndirecto o(arr, 7);
    o.ordenar();
    o.mostrarOriginal();
    o.mostrarOrdenado();
    return 0;
}
