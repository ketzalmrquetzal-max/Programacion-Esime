#include "EstadisticasPuntero.h"

// Constructor - copia el vector
EstadisticasPuntero::EstadisticasPuntero(const std::vector<double>& arreglo)
    : __datos(arreglo) {}

// Calcula suma usando puntero
double EstadisticasPuntero::suma() const {
    Puntero p(const_cast<std::vector<double>*>(&__datos));
    double total = 0;
    while (p.enRango()) {
        total += p.getAt();
        p.avanzar();
    }
    return total;
}

// Calcula promedio
double EstadisticasPuntero::promedio() const {
    return suma() / __datos.size();
}

// Encuentra maximo usando puntero
double EstadisticasPuntero::maximo() const {
    Puntero p(const_cast<std::vector<double>*>(&__datos));
    double m = p.getAt();
    while (p.enRango()) {
        if (p.getAt() > m) m = p.getAt();
        p.avanzar();
    }
    return m;
}

// Encuentra minimo usando puntero
double EstadisticasPuntero::minimo() const {
    Puntero p(const_cast<std::vector<double>*>(&__datos));
    double m = p.getAt();
    while (p.enRango()) {
        if (p.getAt() < m) m = p.getAt();
        p.avanzar();
    }
    return m;
}
