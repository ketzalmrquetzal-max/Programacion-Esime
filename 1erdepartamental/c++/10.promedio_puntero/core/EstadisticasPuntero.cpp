#include "EstadisticasPuntero.h"

EstadisticasPuntero::EstadisticasPuntero(const std::vector<double>& arreglo)
    : __datos(arreglo) {}

double EstadisticasPuntero::suma() const {
    Puntero p(const_cast<std::vector<double>*>(&__datos));
    double total = 0;
    while (p.enRango()) {
        total += p.getAt();
        p.avanzar();
    }
    return total;
}

double EstadisticasPuntero::promedio() const {
    return suma() / __datos.size();
}

double EstadisticasPuntero::maximo() const {
    Puntero p(const_cast<std::vector<double>*>(&__datos));
    double m = p.getAt();
    while (p.enRango()) {
        if (p.getAt() > m) m = p.getAt();
        p.avanzar();
    }
    return m;
}

double EstadisticasPuntero::minimo() const {
    Puntero p(const_cast<std::vector<double>*>(&__datos));
    double m = p.getAt();
    while (p.enRango()) {
        if (p.getAt() < m) m = p.getAt();
        p.avanzar();
    }
    return m;
}
