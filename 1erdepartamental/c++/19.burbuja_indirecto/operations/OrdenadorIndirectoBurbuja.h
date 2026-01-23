#ifndef ORDENADOR_INDIRECTO_BURBUJA_H
#define ORDENADOR_INDIRECTO_BURBUJA_H

#include "../interfaces/IOrdenadorIndirecto.h"

template<typename T>
class OrdenadorIndirectoBurbuja : public IOrdenadorIndirecto<T> {
private:
    const std::vector<T>* __datosOriginales;
    std::vector<int> __indices;
    int __intercambios;

public:
    OrdenadorIndirectoBurbuja(const std::vector<T>& datos);
    void ordenar() override;
    std::vector<int> getIndices() const override;
    void mostrarOrdenado() const;
    void mostrarOriginal() const;
};

template<typename T>
OrdenadorIndirectoBurbuja<T>::OrdenadorIndirectoBurbuja(const std::vector<T>& datos)
    : __datosOriginales(&datos), __intercambios(0) {
    for (size_t i = 0; i < datos.size(); i++) __indices.push_back(i);
}

template<typename T>
void OrdenadorIndirectoBurbuja<T>::ordenar() {
    __intercambios = 0;
    size_t n = __indices.size();
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if ((*__datosOriginales)[__indices[j]] > 
                (*__datosOriginales)[__indices[j + 1]]) {
                std::swap(__indices[j], __indices[j + 1]);
                __intercambios++;
            }
        }
    }
}

template<typename T>
std::vector<int> OrdenadorIndirectoBurbuja<T>::getIndices() const {
    return __indices;
}

template<typename T>
void OrdenadorIndirectoBurbuja<T>::mostrarOrdenado() const {
    std::cout << "Orden mediante índices: ";
    for (int idx : __indices) std::cout << (*__datosOriginales)[idx] << " ";
    std::cout << std::endl;
}

template<typename T>
void OrdenadorIndirectoBurbuja<T>::mostrarOriginal() const {
    std::cout << "Array original: ";
    for (const T& val : *__datosOriginales) std::cout << val << " ";
    std::cout << std::endl;
}

#endif
