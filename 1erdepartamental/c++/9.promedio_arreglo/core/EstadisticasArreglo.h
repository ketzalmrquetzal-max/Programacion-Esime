#ifndef ESTADISTICAS_ARREGLO_H
#define ESTADISTICAS_ARREGLO_H

#include <vector>

// Clase EstadisticasArreglo
class EstadisticasArreglo {
private:
    std::vector<double> __datos;

public:
    // Constructor - inicializa con un vector
    EstadisticasArreglo(const std::vector<double>& arreglo);
    // Obtiene los datos
    std::vector<double> getDatos() const;
    // Calcula la suma
    double suma() const;
    // Calcula el promedio
    double promedio() const;
    // Encuentra el maximo
    double maximo() const;
    // Encuentra el minimo
    double minimo() const;
    // Agrega un valor al arreglo
    void agregar(double valor);
};

#endif
