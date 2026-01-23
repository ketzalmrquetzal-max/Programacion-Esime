#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <array>

// Clase Estadisticas
class Estadisticas {
private:
    std::array<double, 5> __numeros;

public:
    // Constructor - inicializa los 5 numeros
    Estadisticas(double n1, double n2, double n3, double n4, double n5);
    // Obtiene los numeros
    std::array<double, 5> getNumeros() const;
    // Calcula la suma
    double suma() const;
    // Calcula el promedio
    double promedio() const;
    // Encuentra el maximo
    double maximo() const;
    // Encuentra el minimo
    double minimo() const;
};

#endif
