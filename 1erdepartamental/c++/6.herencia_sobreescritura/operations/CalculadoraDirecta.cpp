#include "CalculadoraDirecta.h"
#include <stdexcept>

// Multiplica usando operador nativo
double CalculadoraDirecta::multiplicar(double a, int veces) {
    __resultado = a * veces;
    return __resultado;
}

// Calcula potencia con loops
double CalculadoraDirecta::potencia(double base, int exponente) {
    if (exponente < 0) throw std::invalid_argument("Exponente debe ser >= 0");
    __resultado = 1;
    for (int i = 0; i < exponente; i++) {
        __resultado *= base;
    }
    return __resultado;
}

// Divide usando operador nativo
double CalculadoraDirecta::dividir(double a, int divisor) {
    if (divisor == 0) throw std::invalid_argument("División por cero");
    __resultado = a / divisor;
    return __resultado;
}
