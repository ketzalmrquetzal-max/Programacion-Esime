#include "EstadisticasArreglo.h"

// Constructor - copia el vector
EstadisticasArreglo::EstadisticasArreglo(const std::vector<double>& arreglo)
    : __datos(arreglo) {}

// Obtiene el vector de datos
std::vector<double> EstadisticasArreglo::getDatos() const {
    return __datos;
}

double EstadisticasArreglo::suma() const {
    double total = 0;
    for (double n : __datos) total += n;
    return total;
}

// Calcula el promedio
double EstadisticasArreglo::promedio() const {
    return suma() / __datos.size();
}

// Encuentra el maximo
double EstadisticasArreglo::maximo() const {
    double m = __datos[0];
    for (double n : __datos) {
        if (n > m) m = n;
    }
    return m;
}

// Encuentra el minimo
double EstadisticasArreglo::minimo() const {
    double m = __datos[0];
    for (double n : __datos) {
        if (n < m) m = n;
    }
    return m;
}

// Agrega un nuevo valor
void EstadisticasArreglo::agregar(double valor) {
    __datos.push_back(valor);
}
