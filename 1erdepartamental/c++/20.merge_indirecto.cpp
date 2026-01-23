// ============================================
// PROGRAMA: Merge Sort Indirecto
// DESCRIPCIÓN: Ordena índices con divide y conquista
// ============================================

#include <iostream>
#include <vector>
using namespace std;


/**
 * Merge sort indirecto: ordena índices, preserva original
 */
template<typename T>
class OrdenadorIndirectoMerge {
private:
    const vector<T>* __datosOriginales;
    vector<int> __indices;
    
    void fusionar(int izq, int medio, int der) {
        int n1 = medio - izq + 1;
        int n2 = der - medio;
        
        vector<int> izqArr(n1), derArr(n2);
        
        for (int i = 0; i < n1; i++)
            izqArr[i] = __indices[izq + i];
        for (int j = 0; j < n2; j++)
            derArr[j] = __indices[medio + 1 + j];
        
        int i = 0, j = 0, k = izq;
        
        while (i < n1 && j < n2) {
            // Compara valores originales usando índices
            if ((*__datosOriginales)[izqArr[i]] <= 
                (*__datosOriginales)[derArr[j]]) {
                __indices[k] = izqArr[i];
                i++;
            } else {
                __indices[k] = derArr[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) __indices[k++] = izqArr[i++];
        while (j < n2) __indices[k++] = derArr[j++];
    }
    
    void mergeSortRecursivo(int izq, int der) {
        if (izq >= der) return;
        
        int medio = izq + (der - izq) / 2;
        
        mergeSortRecursivo(izq, medio);
        mergeSortRecursivo(medio + 1, der);
        fusionar(izq, medio, der);
    }

public:
    OrdenadorIndirectoMerge(const vector<T>& datos)
        : __datosOriginales(&datos) {
        for (size_t i = 0; i < datos.size(); i++) {
            __indices.push_back(i);
        }
    }
    
    void ordenar() {
        if (__indices.size() > 1) {
            mergeSortRecursivo(0, __indices.size() - 1);
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
    
    OrdenadorIndirectoMerge<int> ordenador(numeros);
    
    ordenador.mostrarOriginal();
    ordenador.ordenar();
    ordenador.mostrarOrdenado();
    ordenador.mostrarOriginal();
    
    return 0;
}
