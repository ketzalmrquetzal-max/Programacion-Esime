#ifndef COLECCION_PRODUCTOS_H
#define COLECCION_PRODUCTOS_H

#include <vector>
#include "Producto.h"

class ColeccionProductos {
private:
    std::vector<Producto> __productos;

public:
    void agregar(const Producto& p);
    size_t cantidad() const;
    Producto& obtener(size_t indice);
    double precioTotal() const;
    double precioPromedio() const;
    void mostrar() const;
};

#endif
