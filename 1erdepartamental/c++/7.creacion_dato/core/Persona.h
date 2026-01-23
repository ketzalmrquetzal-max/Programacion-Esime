#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

class Persona {
private:
    std::string __nombre, __ap, __am;
    char __genero;
    int __edad;
    void validarEdad(int edad) const;

public:
    Persona(std::string nombre, std::string ap, std::string am, char genero, int edad);
    std::string getNombre() const;
    int getEdad() const;
    void setEdad(int edad);
    std::string nombreCompleto() const;
    friend std::ostream& operator<<(std::ostream& os, const Persona& p);
};

#endif
