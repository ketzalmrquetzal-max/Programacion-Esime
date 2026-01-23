#include "Estadisticas.h"

// Constructor - inicializa el arreglo
Estadisticas::Estadisticas(double n1, double n2, double n3, double n4, double n5) {
    __numeros = {n1, n2, n3, n4, n5};
}

// Obtiene el arreglo de numeros
std::array<double, 5> Estadisticas::getNumeros() const {
    return __numeros;
}

// Calcula la suma de todos los numeros
double Estadisticas::suma() const {
    double total = 0;
    for (double n : __numeros) total += n;
    return total;
}

// Calcula el promedio
double Estadisticas::promedio() const {
    return suma() / __numeros.size();
}

// Encuentra el valor maximo
double Estadisticas::maximo() const {
    double m = __numeros[0];
    for (double n : __numeros) {
        if (n > m) m = n;
    }
    return m;
}

// Encuentra el valor minimo
double Estadisticas::minimo() const {
    double m = __numeros[0];
    for (double n : __numeros) {
        if (n < m) m = n;
    }
    return m;
}
