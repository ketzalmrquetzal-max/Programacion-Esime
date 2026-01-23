// ============================================
// PROGRAMA: Ordenamiento Quick Sort
// DESCRIPCIÓN: Pivote y particionamiento O(n log n)
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
 * Quick Sort: elige pivote, particiona, ordena recursivamente
 */
template<typename T>
class OrdenadorQuick : public IOrdenador<T> {
private:
    int __particiones;
    
    void intercambiar(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
    
    /**
     * Partición: todos los menores al pivote a la izquierda,
     * mayores a la derecha
     */
    int particionar(vector<T>& arr, int bajo, int alto) {
        T pivote = arr[alto];  // Pivote = último elemento
        int i = bajo - 1;
        
        for (int j = bajo; j < alto; j++) {
            if (arr[j] < pivote) {
                i++;
                intercambiar(arr[i], arr[j]);
            }
        }
        intercambiar(arr[i + 1], arr[alto]);
        __particiones++;
        
        return i + 1;
    }
    
    /**
     * Función recursiva de quick sort
     */
    void quickSortRecursivo(vector<T>& arr, int bajo, int alto) {
        if (bajo >= alto) return;  // Base: solo 1 elemento
        
        int pi = particionar(arr, bajo, alto);
        
        quickSortRecursivo(arr, bajo, pi - 1);
        quickSortRecursivo(arr, pi + 1, alto);
    }

public:
    OrdenadorQuick() : __particiones(0) {}
    
    int getParticiones() const { return __particiones; }
    
    void ordenar(vector<T>& datos) override {
        __particiones = 0;
        if (datos.size() > 1) {
            quickSortRecursivo(datos, 0, datos.size() - 1);
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
    
    OrdenadorQuick<int> ordenador;
    ordenador.ordenar(numeros);
    
    cout << "Array ordenado: ";
    for (int n : numeros) cout << n << " ";
    cout << endl << endl;
    
    cout << "Particiones realizadas: " << ordenador.getParticiones() << endl;
    
    return 0;
}
