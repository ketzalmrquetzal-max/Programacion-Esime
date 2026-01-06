#include <iostream>
using namespace std;

class OrdenadorMergeSortIndirecto {
private:
    int* datos;
    int* indices;
    int tam;
    
    void merge(int* idx, int izq, int mid, int der) {
        int n1 = mid - izq + 1, n2 = der - mid;
        int* L = new int[n1];
        int* R = new int[n2];
        for (int i = 0; i < n1; i++) L[i] = idx[izq + i];
        for (int j = 0; j < n2; j++) R[j] = idx[mid + 1 + j];
        int i = 0, j = 0, k = izq;
        while (i < n1 && j < n2)
            idx[k++] = (datos[L[i]] <= datos[R[j]]) ? L[i++] : R[j++];
        while (i < n1) idx[k++] = L[i++];
        while (j < n2) idx[k++] = R[j++];
        delete[] L; delete[] R;
    }
    
    void mergeSort(int* idx, int izq, int der) {
        if (izq < der) {
            int mid = izq + (der - izq) / 2;
            mergeSort(idx, izq, mid);
            mergeSort(idx, mid + 1, der);
            merge(idx, izq, mid, der);
        }
    }
public:
    OrdenadorMergeSortIndirecto(int arr[], int t) : tam(t) {
        datos = new int[t];
        indices = new int[t];
        for (int i = 0; i < t; i++) { datos[i] = arr[i]; indices[i] = i; }
    }
    ~OrdenadorMergeSortIndirecto() { delete[] datos; delete[] indices; }
    
    void ordenar() { mergeSort(indices, 0, tam - 1); }
    
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
    OrdenadorMergeSortIndirecto o(arr, 7);
    o.ordenar();
    o.mostrarOriginal();
    o.mostrarOrdenado();
    return 0;
}
