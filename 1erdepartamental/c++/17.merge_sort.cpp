// ============================================
// PROGRAMA: Ordenamiento Merge Sort
// DESCRIPCIÓN: Divide y conquista O(n log n)
// ============================================

#include <iostream>
#include <vector>
using namespace std;


/**
 * Interfaz para ordenadores
 */
template<typename T>
class IOrdenador {
public:
    virtual void ordenar(vector<T>& datos) = 0;
    virtual ~IOrdenador() {}
};


/**
 * Merge Sort: divide en mitades, ordena recursivamente, fusiona
 */
template<typename T>
class OrdenadorMerge : public IOrdenador<T> {
private:
    int __fusiones;
    
    /**
     * Fusiona dos subarreglos ordenados en uno solo
     */
    void fusionar(vector<T>& arr, int izq, int medio, int der) {
        int n1 = medio - izq + 1;
        int n2 = der - medio;
        
        vector<T> izqArr(n1), derArr(n2);
        
        for (int i = 0; i < n1; i++)
            izqArr[i] = arr[izq + i];
        for (int j = 0; j < n2; j++)
            derArr[j] = arr[medio + 1 + j];
        
        int i = 0, j = 0, k = izq;
        
        while (i < n1 && j < n2) {
            if (izqArr[i] <= derArr[j]) {
                arr[k] = izqArr[i];
                i++;
            } else {
                arr[k] = derArr[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) arr[k++] = izqArr[i++];
        while (j < n2) arr[k++] = derArr[j++];
        
        __fusiones++;
    }
    
    /**
     * Función recursiva de merge sort
     */
    void mergeSortRecursivo(vector<T>& arr, int izq, int der) {
        if (izq >= der) return;  // Base: solo 1 elemento
        
        int medio = izq + (der - izq) / 2;
        
        // Divide
        mergeSortRecursivo(arr, izq, medio);
        mergeSortRecursivo(arr, medio + 1, der);
        
        // Conquista (fusiona)
        fusionar(arr, izq, medio, der);
    }

public:
    OrdenadorMerge() : __fusiones(0) {}
    
    int getFusiones() const { return __fusiones; }
    
    void ordenar(vector<T>& datos) override {
        __fusiones = 0;
        if (datos.size() > 1) {
            mergeSortRecursivo(datos, 0, datos.size() - 1);
        }
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    vector<int> numeros = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Array original: ";
    for (int n : numeros) cout << n << " ";
    cout << endl << endl;
    
    OrdenadorMerge<int> ordenador;
    ordenador.ordenar(numeros);
    
    cout << "Array ordenado: ";
    for (int n : numeros) cout << n << " ";
    cout << endl << endl;
    
    cout << "Fusiones realizadas: " << ordenador.getFusiones() << endl;
    
    return 0;
}
