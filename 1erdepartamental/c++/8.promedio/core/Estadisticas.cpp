#include "Estadisticas.h"

Estadisticas::Estadisticas(double n1, double n2, double n3, double n4, double n5) {
    __numeros = {n1, n2, n3, n4, n5};
}

std::array<double, 5> Estadisticas::getNumeros() const {
    return __numeros;
}

double Estadisticas::suma() const {
    double total = 0;
    for (double n : __numeros) total += n;
    return total;
}

double Estadisticas::promedio() const {
    return suma() / __numeros.size();
}

double Estadisticas::maximo() const {
    double m = __numeros[0];
    for (double n : __numeros) {
        if (n > m) m = n;
    }
    return m;
}

double Estadisticas::minimo() const {
    double m = __numeros[0];
    for (double n : __numeros) {
        if (n < m) m = n;
    }
    return m;
}
