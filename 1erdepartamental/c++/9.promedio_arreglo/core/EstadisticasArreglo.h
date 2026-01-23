#ifndef ESTADISTICAS_ARREGLO_H
#define ESTADISTICAS_ARREGLO_H

#include <vector>

class EstadisticasArreglo {
private:
    std::vector<double> __datos;

public:
    EstadisticasArreglo(const std::vector<double>& arreglo);
    std::vector<double> getDatos() const;
    double suma() const;
    double promedio() const;
    double maximo() const;
    double minimo() const;
    void agregar(double valor);
};

#endif
