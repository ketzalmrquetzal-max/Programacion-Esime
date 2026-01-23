#include <iostream>
#include "core/ColeccionProductos.h"

int main() {
    // Crea coleccion
    ColeccionProductos inventario;
    
    // Agrega productos
    inventario.agregar(Producto("Laptop", 15000));
    inventario.agregar(Producto("Mouse", 250));
    inventario.agregar(Producto("Teclado", 800));
    
    std::cout << "=== INVENTARIO ===" << std::endl;
    inventario.mostrar();
    std::cout << "\nTotal productos: " << inventario.cantidad() << std::endl;
    std::cout << "Precio total: $" << inventario.precioTotal() << std::endl;
    std::cout << "Precio promedio: $" << inventario.precioPromedio() << std::endl;
    
    return 0;
}
