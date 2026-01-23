#include "Saludo.h"
#include <iostream>
#include <stdexcept>
void Saludo::validarMensaje(const std::string& msg) const {
    if (msg.empty()) {
        throw std::invalid_argument("El mensaje no puede estar vacío");
    }
}

Saludo::Saludo(std::string msg) : __mensaje("") {
    setMensaje(msg);
}

std::string Saludo::getMensaje() const {
    return __mensaje;
}

void Saludo::setMensaje(const std::string& msg) {
    validarMensaje(msg);
    __mensaje = msg;
}

void Saludo::mostrar() const {
    std::cout << __mensaje << std::endl;
}

std::string Saludo::saludarPersona(const std::string& nombre) const {
    if (nombre.empty()) {
        throw std::invalid_argument("El nombre no puede estar vacío");
    }
    return "Hola " + nombre;
}

std::ostream& operator<<(std::ostream& os, const Saludo& s) {
    os << "Saludo(mensaje=\"" << s.__mensaje << "\")";
    return os;
}
