#include "ColeccionProductos.h"
#include <iostream>
#include <stdexcept>

void ColeccionProductos::agregar(const Producto& p) {
    __productos.push_back(p);
}

size_t ColeccionProductos::cantidad() const {
    return __productos.size();
}

Producto& ColeccionProductos::obtener(size_t indice) {
    if (indice >= __productos.size()) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return __productos[indice];
}

double ColeccionProductos::precioTotal() const {
    double total = 0;
    for (const auto& p : __productos) {
        total += p.getPrecio();
    }
    return total;
}

double ColeccionProductos::precioPromedio() const {
    if (__productos.empty()) return 0;
    return precioTotal() / __productos.size();
}

void ColeccionProductos::mostrar() const {
    for (size_t i = 0; i < __productos.size(); i++) {
        std::cout << i << ": " << __productos[i] << std::endl;
    }
}
