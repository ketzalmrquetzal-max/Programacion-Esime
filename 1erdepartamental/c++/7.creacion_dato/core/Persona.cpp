#include "Persona.h"
#include <stdexcept>

void Persona::validarEdad(int edad) const {
    if (edad < 0) throw std::invalid_argument("La edad no puede ser negativa");
}

Persona::Persona(std::string nombre, std::string ap, std::string am, char genero, int edad)
    : __nombre(nombre), __ap(ap), __am(am), __genero(genero), __edad(0) {
    setEdad(edad);
}

std::string Persona::getNombre() const { return __nombre; }
int Persona::getEdad() const { return __edad; }

void Persona::setEdad(int edad) {
    validarEdad(edad);
    __edad = edad;
}

std::string Persona::nombreCompleto() const {
    return __nombre + " " + __ap + " " + __am;
}

std::ostream& operator<<(std::ostream& os, const Persona& p) {
    os << p.nombreCompleto() << ", " << p.__edad << " años";
    return os;
}
