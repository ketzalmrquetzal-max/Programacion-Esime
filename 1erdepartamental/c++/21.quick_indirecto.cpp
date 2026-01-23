// ============================================
// PROGRAMA: Quick Sort Indirecto
// DESCRIPCIÓN: Ordena índices con particionamiento
// ============================================

#include <iostream>
#include <vector>
using namespace std;


/**
 * Quick sort indirecto: ordena índices, preserva original
 */
template<typename T>
class OrdenadorIndirectoQuick {
private:
    const vector<T>* __datosOriginales;
    vector<int> __indices;
    
    int particionar(int bajo, int alto) {
        // Usa el valor original del último índice como pivote
        T pivote = (*__datosOriginales)[__indices[alto]];
        int i = bajo - 1;
        
        for (int j = bajo; j < alto; j++) {
            // Compara valores originales usando índices
            if ((*__datosOriginales)[__indices[j]] < pivote) {
                i++;
                swap(__indices[i], __indices[j]);
            }
        }
        swap(__indices[i + 1], __indices[alto]);
        return i + 1;
    }
    
    void quickSortRecursivo(int bajo, int alto) {
        if (bajo >= alto) return;
        
        int pi = particionar(bajo, alto);
        
        quickSortRecursivo(bajo, pi - 1);
        quickSortRecursivo(pi + 1, alto);
    }

public:
    OrdenadorIndirectoQuick(const vector<T>& datos)
        : __datosOriginales(&datos) {
        for (size_t i = 0; i < datos.size(); i++) {
            __indices.push_back(i);
        }
    }
    
    void ordenar() {
        if (__indices.size() > 1) {
            quickSortRecursivo(0, __indices.size() - 1);
        }
    }
    
    vector<int> getIndices() const { return __indices; }
    
    void mostrarOrdenado() const {
        cout << "Orden mediante índices: ";
        for (int idx : __indices) {
            cout << (*__datosOriginales)[idx] << " ";
        }
        cout << endl;
    }
    
    void mostrarOriginal() const {
        cout << "Array original: ";
        for (const T& val : *__datosOriginales) {
            cout << val << " ";
        }
        cout << endl;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    vector<int> numeros = {64, 34, 25, 12, 22, 11, 90};
    
    OrdenadorIndirectoQuick<int> ordenador(numeros);
    
    ordenador.mostrarOriginal();
    ordenador.ordenar();
    ordenador.mostrarOrdenado();
    ordenador.mostrarOriginal();
    
    return 0;
}
