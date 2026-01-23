#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <iostream>

class Estudiante {
private:
    std::string __nombre;
    double __promedio;

public:
    Estudiante(std::string nombre, double promedio);
    std::string getNombre() const;
    double getPromedio() const;
    
    bool operator>(const Estudiante& otro) const;
    friend std::ostream& operator<<(std::ostream& os, const Estudiante& e);
};

#endif
