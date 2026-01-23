#ifndef COLECCION_PRODUCTOS_H
#define COLECCION_PRODUCTOS_H

#include <vector>
#include "Producto.h"

// Clase ColeccionProductos
class ColeccionProductos {
private:
    std::vector<Producto> __productos;

public:
    // Agrega producto
    void agregar(const Producto& p);
    // Obtiene cantidad
    size_t cantidad() const;
    // Obtiene producto por indice
    Producto& obtener(size_t indice);
    // Calcula precio total
    double precioTotal() const;
    // Calcula precio promedio
    double precioPromedio() const;
    // Muestra todos los productos
    void mostrar() const;
};

#endif
