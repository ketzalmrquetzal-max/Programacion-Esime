#ifndef PERSONA_TAMANIOS_H
#define PERSONA_TAMANIOS_H

#include <string>
#include <iostream>

class Persona {
private:
    std::string __nombre, __apellido;
    int __edad;

public:
    Persona(std::string nombre, std::string apellido, int edad);
    friend std::ostream& operator<<(std::ostream& os, const Persona& p);
};

#endif
