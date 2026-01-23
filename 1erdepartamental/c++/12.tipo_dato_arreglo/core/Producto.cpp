#include "Producto.h"
#include <stdexcept>

void Producto::validarPrecio(double precio) const {
    if (precio < 0) throw std::invalid_argument("Precio no puede ser negativo");
}

Producto::Producto(std::string nombre, double precio) : __nombre(nombre), __precio(0) {
    setPrecio(precio);
}

std::string Producto::getNombre() const { return __nombre; }
double Producto::getPrecio() const { return __precio; }

void Producto::setPrecio(double precio) {
    validarPrecio(precio);
    __precio = precio;
}

bool Producto::operator<(const Producto& otro) const {
    return __precio < otro.__precio;
}

std::ostream& operator<<(std::ostream& os, const Producto& p) {
    os << p.__nombre << ": $" << p.__precio;
    return os;
}
