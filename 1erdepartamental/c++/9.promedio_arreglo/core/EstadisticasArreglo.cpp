#include "EstadisticasArreglo.h"

EstadisticasArreglo::EstadisticasArreglo(const std::vector<double>& arreglo)
    : __datos(arreglo) {}

std::vector<double> EstadisticasArreglo::getDatos() const {
    return __datos;
}

double EstadisticasArreglo::suma() const {
    double total = 0;
    for (double n : __datos) total += n;
    return total;
}

double EstadisticasArreglo::promedio() const {
    return suma() / __datos.size();
}

double EstadisticasArreglo::maximo() const {
    double m = __datos[0];
    for (double n : __datos) {
        if (n > m) m = n;
    }
    return m;
}

double EstadisticasArreglo::minimo() const {
    double m = __datos[0];
    for (double n : __datos) {
        if (n < m) m = n;
    }
    return m;
}

void EstadisticasArreglo::agregar(double valor) {
    __datos.push_back(valor);
}
