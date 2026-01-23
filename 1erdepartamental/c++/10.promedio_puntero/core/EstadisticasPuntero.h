#ifndef ESTADISTICAS_PUNTERO_H
#define ESTADISTICAS_PUNTERO_H

#include <vector>
#include "../utils/Puntero.h"

class EstadisticasPuntero {
private:
    std::vector<double> __datos;

public:
    EstadisticasPuntero(const std::vector<double>& arreglo);
    double suma() const;
    double promedio() const;
    double maximo() const;
    double minimo() const;
};

#endif
