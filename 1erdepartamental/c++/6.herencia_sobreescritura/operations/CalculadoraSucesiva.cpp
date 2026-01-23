#include "CalculadoraSucesiva.h"
#include <stdexcept>

// Multiplica mediante sumas sucesibas
double CalculadoraSucesiva::multiplicar(double a, int veces) {
    __resultado = 0;
    for (int i = 0; i < veces; i++) {
        __resultado += a;
    }
    return __resultado;
}

// Calcula potencia con multiplicaciones
double CalculadoraSucesiva::potencia(double base, int exponente) {
    if (exponente < 0) throw std::invalid_argument("Exponente debe ser >= 0");
    __resultado = 1;
    for (int i = 0; i < exponente; i++) {
        __resultado *= base;
    }
    return __resultado;
}

// Divide mediante restas sucesivas
double CalculadoraSucesiva::dividir(double a, int divisor) {
    if (divisor == 0) throw std::invalid_argument("División por cero");
    __resultado = 0;
    double residuo = a;
    while (residuo >= divisor) {
        residuo -= divisor;
        __resultado++;
    }
    return __resultado;
}
