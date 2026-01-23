#ifndef ORDENADOR_MERGE_H
#define ORDENADOR_MERGE_H

#include "../interfaces/IOrdenador.h"

template<typename T>
class OrdenadorMerge : public IOrdenador<T> {
private:
    int __fusiones;
    void fusionar(std::vector<T>& arr, int izq, int medio, int der);
    void mergeSortRecursivo(std::vector<T>& arr, int izq, int der);

public:
    OrdenadorMerge();
    int getFusiones() const;
    void ordenar(std::vector<T>& datos) override;
};

template<typename T>
OrdenadorMerge<T>::OrdenadorMerge() : __fusiones(0) {}

template<typename T>
int OrdenadorMerge<T>::getFusiones() const { return __fusiones; }

template<typename T>
void OrdenadorMerge<T>::fusionar(std::vector<T>& arr, int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    
    std::vector<T> izqArr(n1), derArr(n2);
    for (int i = 0; i < n1; i++) izqArr[i] = arr[izq + i];
    for (int j = 0; j < n2; j++) derArr[j] = arr[medio + 1 + j];
    
    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (izqArr[i] <= derArr[j]) arr[k++] = izqArr[i++];
        else arr[k++] = derArr[j++];
    }
    while (i < n1) arr[k++] = izqArr[i++];
    while (j < n2) arr[k++] = derArr[j++];
    __fusiones++;
}

template<typename T>
void OrdenadorMerge<T>::mergeSortRecursivo(std::vector<T>& arr, int izq, int der) {
    if (izq >= der) return;
    int medio = izq + (der - izq) / 2;
    mergeSortRecursivo(arr, izq, medio);
    mergeSortRecursivo(arr, medio + 1, der);
    fusionar(arr, izq, medio, der);
}

template<typename T>
void OrdenadorMerge<T>::ordenar(std::vector<T>& datos) {
    __fusiones = 0;
    if (datos.size() > 1) mergeSortRecursivo(datos, 0, datos.size() - 1);
}

#endif
