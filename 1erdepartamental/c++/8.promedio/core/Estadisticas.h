#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <array>

class Estadisticas {
private:
    std::array<double, 5> __numeros;

public:
    Estadisticas(double n1, double n2, double n3, double n4, double n5);
    std::array<double, 5> getNumeros() const;
    double suma() const;
    double promedio() const;
    double maximo() const;
    double minimo() const;
};

#endif
