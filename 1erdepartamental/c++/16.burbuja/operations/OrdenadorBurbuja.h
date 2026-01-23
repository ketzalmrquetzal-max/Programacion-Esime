#ifndef ORDENADOR_BURBUJA_H
#define ORDENADOR_BURBUJA_H

#include "../interfaces/IOrdenador.h"

// Bubble sort con templates y estadísticas de rendimiento
template<typename T>
class OrdenadorBurbuja : public IOrdenador<T> {
private:
    int __comparaciones, __intercambios;  // Contadores para análisis
    void intercambiar(T& a, T& b);

public:
    OrdenadorBurbuja();
    int getComparaciones() const;
    int getIntercambios() const;
    void ordenar(std::vector<T>& datos) override;
    void mostrarEstadisticas() const;
};

template<typename T>
void OrdenadorBurbuja<T>::intercambiar(T& a, T& b) {
    T temp = a; a = b; b = temp;
    __intercambios++;
}

template<typename T>
OrdenadorBurbuja<T>::OrdenadorBurbuja() : __comparaciones(0), __intercambios(0) {}

template<typename T>
int OrdenadorBurbuja<T>::getComparaciones() const { return __comparaciones; }

template<typename T>
int OrdenadorBurbuja<T>::getIntercambios() const { return __intercambios; }

template<typename T>
void OrdenadorBurbuja<T>::ordenar(std::vector<T>& datos) {
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
        if (!huboIntercambio) break;
    }
}

template<typename T>
void OrdenadorBurbuja<T>::mostrarEstadisticas() const {
    std::cout << "Comparaciones: " << __comparaciones << std::endl;
    std::cout << "Intercambios: " << __intercambios << std::endl;
}

#endif
