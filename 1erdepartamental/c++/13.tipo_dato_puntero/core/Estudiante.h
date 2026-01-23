#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <iostream>

// Clase Estudiante
class Estudiante {
private:
    std::string __nombre;
    double __promedio;

public:
    // Constructor
    Estudiante(std::string nombre, double promedio);
    // Obtiene nombre
    std::string getNombre() const;
    // Obtiene promedio
    double getPromedio() const;
    
    // Comparador >
    bool operator>(const Estudiante& otro) const;
    // Operador salida
    friend std::ostream& operator<<(std::ostream& os, const Estudiante& e);
};

#endif
