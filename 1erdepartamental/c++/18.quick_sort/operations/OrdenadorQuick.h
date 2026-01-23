#ifndef ORDENADOR_QUICK_H
#define ORDENADOR_QUICK_H

#include "../interfaces/IOrdenador.h"

template<typename T>
class OrdenadorQuick : public IOrdenador<T> {
private:
    int __particiones;
    void intercambiar(T& a, T& b);
    int particionar(std::vector<T>& arr, int bajo, int alto);
    void quickSortRecursivo(std::vector<T>& arr, int bajo, int alto);

public:
    OrdenadorQuick();
    int getParticiones() const;
    void ordenar(std::vector<T>& datos) override;
};

template<typename T>
OrdenadorQuick<T>::OrdenadorQuick() : __particiones(0) {}

template<typename T>
int OrdenadorQuick<T>::getParticiones() const { return __particiones; }

template<typename T>
void OrdenadorQuick<T>::intercambiar(T& a, T& b) {
    T temp = a; a = b; b = temp;
}

template<typename T>
int OrdenadorQuick<T>::particionar(std::vector<T>& arr, int bajo, int alto) {
    T pivote = arr[alto];
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        if (arr[j] < pivote) intercambiar(arr[++i], arr[j]);
    }
    intercambiar(arr[i + 1], arr[alto]);
    __particiones++;
    return i + 1;
}

template<typename T>
void OrdenadorQuick<T>::quickSortRecursivo(std::vector<T>& arr, int bajo, int alto) {
    if (bajo >= alto) return;
    int pi = particionar(arr, bajo, alto);
    quickSortRecursivo(arr, bajo, pi - 1);
    quickSortRecursivo(arr, pi + 1, alto);
}

template<typename T>
void OrdenadorQuick<T>::ordenar(std::vector<T>& datos) {
    __particiones = 0;
    if (datos.size() > 1) quickSortRecursivo(datos, 0, datos.size() - 1);
}

#endif
