#ifndef ESTADISTICAS_PUNTERO_H
#define ESTADISTICAS_PUNTERO_H

#include <vector>
#include "../utils/Puntero.h"

// Clase EstadisticasPuntero
class EstadisticasPuntero {
private:
    std::vector<double> __datos;

public:
    // Constructor - inicializa con vector
    EstadisticasPuntero(const std::vector<double>& arreglo);
    // Calcula suma usando punteros
    double suma() const;
    // Calcula promedio
    double promedio() const;
    // Encuentra maximo
    double maximo() const;
    // Encuentra minimo
    double minimo() const;
};

#endif
