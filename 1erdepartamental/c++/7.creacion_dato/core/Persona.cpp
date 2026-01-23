#include "Persona.h"
#include <stdexcept>

// Valida que la edad no sea negativa
void Persona::validarEdad(int edad) const {
    if (edad < 0) throw std::invalid_argument("La edad no puede ser negativa");
}

// Constructor - inicializa atributos con validacion
Persona::Persona(std::string nombre, std::string ap, std::string am, char genero, int edad)
    : __nombre(nombre), __ap(ap), __am(am), __genero(genero), __edad(0) {
    setEdad(edad);
}

// Obtiene el nombre
std::string Persona::getNombre() const { return __nombre; }
// Obtiene la edad
int Persona::getEdad() const { return __edad; }

// Establece la edad con validacion
void Persona::setEdad(int edad) {
    validarEdad(edad);
    __edad = edad;
}

// Retorna el nombre completo
std::string Persona::nombreCompleto() const {
    return __nombre + " " + __ap + " " + __am;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const Persona& p) {
    os << p.nombreCompleto() << ", " << p.__edad << " años";
    return os;
}
