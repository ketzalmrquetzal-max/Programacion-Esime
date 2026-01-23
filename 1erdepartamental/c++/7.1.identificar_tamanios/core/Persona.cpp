#include "Persona.h"

// Constructor - inicialisa atributos
Persona::Persona(std::string nombre, std::string apellido, int edad)
    : __nombre(nombre), __apellido(apellido), __edad(edad) {}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const Persona& p) {
    os << p.__nombre << " " << p.__apellido;
    return os;
}
