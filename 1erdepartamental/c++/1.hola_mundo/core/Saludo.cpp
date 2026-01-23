#include "Saludo.h"
#include <iostream>
#include <stdexcept>

// Valida que el mensaje no esté vacío
void Saludo::validarMensaje(const std::string& msg) const {
    if (msg.empty()) {
        throw std::invalid_argument("El mensaje no puede estar vacío");
    }
}

// Constructor - Inicializa el mensaje con validación
Saludo::Saludo(std::string msg) : __mensaje("") {
    setMensaje(msg);
}

// Obtiene el mensaje
std::string Saludo::getMensaje() const {
    return __mensaje;
}

// Establece el mensaje con validación
void Saludo::setMensaje(const std::string& msg) {
    validarMensaje(msg);
    __mensaje = msg;
}

// Muestra el mensaje en consola
void Saludo::mostrar() const {
    std::cout << __mensaje << std::endl;
}

// Retorna un saludo personalizado
std::string Saludo::saludarPersona(const std::string& nombre) const {
    if (nombre.empty()) {
        throw std::invalid_argument("El nombre no puede estar vacío");
    }
    return "Hola " + nombre;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const Saludo& s) {
    os << "Saludo(mensaje=\"" << s.__mensaje << "\")";
    return os;
}
