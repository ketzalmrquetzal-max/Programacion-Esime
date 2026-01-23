#include "Auto.h"
#include <iomanip>
#include <stdexcept>

// Valida que el precio no sea negativo
void Auto::validarPrecio(double precio) const {
    if (precio < 0) throw std::invalid_argument("El precio no puede ser negativo");
}

// Constructor - inicializa los atributos
Auto::Auto(std::string marca, std::string modelo, double precio, int anio)
    : __marca(marca), __modelo(modelo), __precio(0), __anio(anio) {
    setPrecio(precio);
}

// Obtiene el precio
double Auto::getPrecio() const { return __precio; }

// Establece el precio con validacion
void Auto::setPrecio(double precio) {
    validarPrecio(precio);
    __precio = precio;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const Auto& a) {
    os << a.__marca << " " << a.__modelo << " (" << a.__anio << ") - $";
    os << std::fixed << std::setprecision(2) << a.__precio;
    return os;
}
