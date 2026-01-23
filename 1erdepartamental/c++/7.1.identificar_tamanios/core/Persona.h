#ifndef PERSONA_TAMANIOS_H
#define PERSONA_TAMANIOS_H

#include <string>
#include <iostream>

// Clase Persona
class Persona {
private:
    std::string __nombre, __apellido;
    int __edad;

public:
    // Constructor
    Persona(std::string nombre, std::string apellido, int edad);
    // Sobercarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Persona& p);
};

#endif
