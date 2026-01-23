#ifndef ORDENADOR_INDIRECTO_MERGE_H
#define ORDENADOR_INDIRECTO_MERGE_H

#include "../interfaces/IOrdenadorIndirecto.h"

template<typename T>
class OrdenadorIndirectoMerge : public IOrdenadorIndirecto<T> {
private:
    const std::vector<T>* __datosOriginales;
    std::vector<int> __indices;
    
    void fusionar(int izq, int medio, int der);
    void mergeSortRecursivo(int izq, int der);

public:
    OrdenadorIndirectoMerge(const std::vector<T>& datos);
    void ordenar() override;
    std::vector<int> getIndices() const override;
    void mostrarOrdenado() const;
    void mostrarOriginal() const;
};

template<typename T>
OrdenadorIndirectoMerge<T>::OrdenadorIndirectoMerge(const std::vector<T>& datos)
    : __datosOriginales(&datos) {
    for (size_t i = 0; i < datos.size(); i++) __indices.push_back(i);
}

template<typename T>
void OrdenadorIndirectoMerge<T>::fusionar(int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;
    std::vector<int> izqArr(n1), derArr(n2);
    
    for (int i = 0; i < n1; i++) izqArr[i] = __indices[izq + i];
    for (int j = 0; j < n2; j++) derArr[j] = __indices[medio + 1 + j];
    
    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if ((*__datosOriginales)[izqArr[i]] <= (*__datosOriginales)[derArr[j]])
            __indices[k++] = izqArr[i++];
        else
            __indices[k++] = derArr[j++];
    }
    while (i < n1) __indices[k++] = izqArr[i++];
    while (j < n2) __indices[k++] = derArr[j++];
}

template<typename T>
void OrdenadorIndirectoMerge<T>::mergeSortRecursivo(int izq, int der) {
    if (izq >= der) return;
    int medio = izq + (der - izq) / 2;
    mergeSortRecursivo(izq, medio);
    mergeSortRecursivo(medio + 1, der);
    fusionar(izq, medio, der);
}

template<typename T>
void OrdenadorIndirectoMerge<T>::ordenar() {
    if (__indices.size() > 1) mergeSortRecursivo(0, __indices.size() - 1);
}

template<typename T>
std::vector<int> OrdenadorIndirectoMerge<T>::getIndices() const {
    return __indices;
}

template<typename T>
void OrdenadorIndirectoMerge<T>::mostrarOrdenado() const {
    std::cout << "Orden mediante índices: ";
    for (int idx : __indices) std::cout << (*__datosOriginales)[idx] << " ";
    std::cout << std::endl;
}

template<typename T>
void OrdenadorIndirectoMerge<T>::mostrarOriginal() const {
    std::cout << "Array original: ";
    for (const T& val : *__datosOriginales) std::cout << val << " ";
    std::cout << std::endl;
}

#endif
