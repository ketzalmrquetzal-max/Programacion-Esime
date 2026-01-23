#ifndef ORDENADOR_INDIRECTO_QUICK_H
#define ORDENADOR_INDIRECTO_QUICK_H

#include "../interfaces/IOrdenadorIndirecto.h"

template<typename T>
class OrdenadorIndirectoQuick : public IOrdenadorIndirecto<T> {
private:
    const std::vector<T>* __datosOriginales;
    std::vector<int> __indices;
    
    int particionar(int bajo, int alto);
    void quickSortRecursivo(int bajo, int alto);

public:
    OrdenadorIndirectoQuick(const std::vector<T>& datos);
    void ordenar() override;
    std::vector<int> getIndices() const override;
    void mostrarOrdenado() const;
    void mostrarOriginal() const;
};

template<typename T>
OrdenadorIndirectoQuick<T>::OrdenadorIndirectoQuick(const std::vector<T>& datos)
    : __datosOriginales(&datos) {
    for (size_t i = 0; i < datos.size(); i++) __indices.push_back(i);
}

template<typename T>
int OrdenadorIndirectoQuick<T>::particionar(int bajo, int alto) {
    T pivote = (*__datosOriginales)[__indices[alto]];
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        if ((*__datosOriginales)[__indices[j]] < pivote) {
            std::swap(__indices[++i], __indices[j]);
        }
    }
    std::swap(__indices[i + 1], __indices[alto]);
    return i + 1;
}

template<typename T>
void OrdenadorIndirectoQuick<T>::quickSortRecursivo(int bajo, int alto) {
    if (bajo >= alto) return;
    int pi = particionar(bajo, alto);
    quickSortRecursivo(bajo, pi - 1);
    quickSortRecursivo(pi + 1, alto);
}

template<typename T>
void OrdenadorIndirectoQuick<T>::ordenar() {
    if (__indices.size() > 1) quickSortRecursivo(0, __indices.size() - 1);
}

template<typename T>
std::vector<int> OrdenadorIndirectoQuick<T>::getIndices() const {
    return __indices;
}

template<typename T>
void OrdenadorIndirectoQuick<T>::mostrarOrdenado() const {
    std::cout << "Orden mediante índices: ";
    for (int idx : __indices) std::cout << (*__datosOriginales)[idx] << " ";
    std::cout << std::endl;
}

template<typename T>
void OrdenadorIndirectoQuick<T>::mostrarOriginal() const {
    std::cout << "Array original: ";
    for (const T& val : *__datosOriginales) std::cout << val << " ";
    std::cout << std::endl;
}

#endif
