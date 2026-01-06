#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;
    Persona(string n = "", int e = 0) : nombre(n), edad(e) {}
};

class OrdenadorMergeSort {
private:
    int* datos;
    int tam;
    
    void merge(int izq, int mid, int der) {
        int n1 = mid - izq + 1, n2 = der - mid;
        int* L = new int[n1];
        int* R = new int[n2];
        for (int i = 0; i < n1; i++) L[i] = datos[izq + i];
        for (int j = 0; j < n2; j++) R[j] = datos[mid + 1 + j];
        int i = 0, j = 0, k = izq;
        while (i < n1 && j < n2) datos[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) datos[k++] = L[i++];
        while (j < n2) datos[k++] = R[j++];
        delete[] L; delete[] R;
    }
    
    void mergeSort(int izq, int der) {
        if (izq < der) {
            int mid = izq + (der - izq) / 2;
            mergeSort(izq, mid);
            mergeSort(mid + 1, der);
            merge(izq, mid, der);
        }
    }
public:
    OrdenadorMergeSort(int arr[], int t) : tam(t) {
        datos = new int[t];
        for (int i = 0; i < t; i++) datos[i] = arr[i];
    }
    ~OrdenadorMergeSort() { delete[] datos; }
    
    void ordenar() { mergeSort(0, tam - 1); }
    
    void mostrar() {
        for (int i = 0; i < tam; i++) cout << datos[i] << " ";
        cout << endl;
    }
};

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    OrdenadorMergeSort o(arr, 7);
    o.ordenar();
    cout << "Enteros: "; o.mostrar();
    return 0;
}
