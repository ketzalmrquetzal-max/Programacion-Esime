#include "Producto.h"
#include <stdexcept>

// Valida precio
void Producto::validarPrecio(double precio) const {
    if (precio < 0) throw std::invalid_argument("Precio no puede ser negativo");
}

// Constructor
Producto::Producto(std::string nombre, double precio) : __nombre(nombre), __precio(0) {
    setPrecio(precio);
}

// Getters
std::string Producto::getNombre() const { return __nombre; }
double Producto::getPrecio() const { return __precio; }

// Setter con validacion
void Producto::setPrecio(double precio) {
    validarPrecio(precio);
    __precio = precio;
}

// Operador comparacion
bool Producto::operator<(const Producto& otro) const {
    return __precio < otro.__precio;
}

// Operador salida
std::ostream& operator<<(std::ostream& os, const Producto& p) {
    os << p.__nombre << ": $" << p.__precio;
    return os;
}
