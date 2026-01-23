#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>

// Clase Persona
class Persona {
private:
    std::string __nombre, __ap, __am;
    char __genero;
    int __edad;
    void validarEdad(int edad) const;

public:
    // Constructor - inicializa atributos
    Persona(std::string nombre, std::string ap, std::string am, char genero, int edad);
    // Obtiene el nombre
    std::string getNombre() const;
    // Obtiene la edad
    int getEdad() const;
    // Estable ce la edad con validacion
    void setEdad(int edad);
    // Retorna el nombre completo
    std::string nombreCompleto() const;
    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Persona& p);
};

#endif
