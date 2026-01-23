// ============================================
// PROGRAMA: Ordenamiento Indirecto con Burbuja
// DESCRIPCIÓN: Ordena índices, preserva array original
// ============================================

#include <iostream>
#include <vector>
using namespace std;


/**
 * Ordenamiento indirecto: ordena un vector de índices
 * en lugar de modificar el array original
 */
template<typename T>
class OrdenadorIndirectoBurbuja {
private:
    const vector<T>* __datosOriginales;
    vector<int> __indices;
    int __intercambios;

public:
    OrdenadorIndirectoBurbuja(const vector<T>& datos)
        : __datosOriginales(&datos), __intercambios(0) {
        // Inicializa índices [0, 1, 2, ..., n-1]
        for (size_t i = 0; i < datos.size(); i++) {
            __indices.push_back(i);
        }
    }
    
    /**
     * Ordena los índices según los valores originales
     * El array original NO se modifica
     */
    void ordenar() {
        __intercambios = 0;
        size_t n = __indices.size();
        
        for (size_t i = 0; i < n - 1; i++) {
            for (size_t j = 0; j < n - i - 1; j++) {
                // Compara valores originales usando índices
                if ((*__datosOriginales)[__indices[j]] > 
                    (*__datosOriginales)[__indices[j + 1]]) {
                    swap(__indices[j], __indices[j + 1]);
                    __intercambios++;
                }
            }
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
        cout << "Array original (sin modificar): ";
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
    
    OrdenadorIndirectoBurbuja<int> ordenador(numeros);
    
    ordenador.mostrarOriginal();
    ordenador.ordenar();
    ordenador.mostrarOrdenado();
    ordenador.mostrarOriginal();  // Demuestra que no cambió
    
    return 0;
}
