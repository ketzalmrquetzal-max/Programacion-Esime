#include "Auto.h"
#include <iomanip>
#include <stdexcept>

void Auto::validarPrecio(double precio) const {
    if (precio < 0) throw std::invalid_argument("El precio no puede ser negativo");
}

Auto::Auto(std::string marca, std::string modelo, double precio, int anio)
    : __marca(marca), __modelo(modelo), __precio(0), __anio(anio) {
    setPrecio(precio);
}

double Auto::getPrecio() const { return __precio; }

void Auto::setPrecio(double precio) {
    validarPrecio(precio);
    __precio = precio;
}

std::ostream& operator<<(std::ostream& os, const Auto& a) {
    os << a.__marca << " " << a.__modelo << " (" << a.__anio << ") - $";
    os << std::fixed << std::setprecision(2) << a.__precio;
    return os;
}
