#include "Estudiante.h"

// Constructor
Estudiante::Estudiante(std::string nombre, double promedio)
    : __nombre(nombre), __promedio(promedio) {}

// Getters
std::string Estudiante::getNombre() const { return __nombre; }
double Estudiante::getPromedio() const { return __promedio; }

// Operador >
bool Estudiante::operator>(const Estudiante& otro) const {
    return __promedio > otro.__promedio;
}

// Operador salida
std::ostream& operator<<(std::ostream& os, const Estudiante& e) {
    os << e.__nombre << " (Promedio: " << e.__promedio << ")";
    return os;
}
