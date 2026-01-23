// ============================================
// PROGRAMA: Ordenamiento Burbuja (Bubble Sort)
// DESCRIPCIÓN: Algoritmo O(n²) con optimización
// ============================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * Interfaz para algoritmos de ordenamiento
 */
template<typename T>
class IOrdenador {
public:
    virtual void ordenar(vector<T>& datos) = 0;
    virtual ~IOrdenador() {}
};


/**
 * Ordenamiento burbuja con encapsulación
 */
template<typename T>
class OrdenadorBurbuja : public IOrdenador<T> {
private:
    int __comparaciones;
    int __intercambios;
    
    void intercambiar(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
        __intercambios++;
    }

public:
    OrdenadorBurbuja() : __comparaciones(0), __intercambios(0) {}
    
    int getComparaciones() const { return __comparaciones; }
    int getIntercambios() const { return __intercambios; }
    
    /**
     * Burbuja: compara pares adyacentes y los intercambia si están desordenados
     * Optimización: detiene si no hay intercambios en una pasada
     */
    void ordenar(vector<T>& datos) override {
        __comparaciones = 0;
        __intercambios = 0;
        
        size_t n = datos.size();
        bool huboIntercambio;
        
        for (size_t i = 0; i < n - 1; i++) {
            huboIntercambio = false;
            
            for (size_t j = 0; j < n - i - 1; j++) {
                __comparaciones++;
                if (datos[j] > datos[j + 1]) {
                    intercambiar(datos[j], datos[j + 1]);
                    huboIntercambio = true;
                }
            }
            
            // Optimización: si no hubo intercambios, ya está ordenado
            if (!huboIntercambio) break;
        }
    }
    
    void mostrarEstadisticas() const {
        cout << "Comparaciones: " << __comparaciones << endl;
        cout << "Intercambios: " << __intercambios << endl;
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
    
    OrdenadorBurbuja<int> ordenador;
    ordenador.ordenar(numeros);
    
    cout << "Array ordenado: ";
    for (int n : numeros) cout << n << " ";
    cout << endl << endl;
    
    ordenador.mostrarEstadisticas();
    
    return 0;
}
