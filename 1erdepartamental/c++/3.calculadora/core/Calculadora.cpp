#include "Calculadora.h"
#include <stdexcept>

Calculadora::Calculadora() : __resultado(0) {}

double Calculadora::getResultado() const {
    return __resultado;
}

double Calculadora::sumar(double a, double b) {
    __resultado = a + b;
    return __resultado;
}

double Calculadora::restar(double a, double b) {
    __resultado = a - b;
    return __resultado;
}

double Calculadora::multiplicar(double a, double b) {
    __resultado = a * b;
    return __resultado;
}

double Calculadora::dividir(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Error: división por cero");
    }
    __resultado = a / b;
    return __resultado;
}
