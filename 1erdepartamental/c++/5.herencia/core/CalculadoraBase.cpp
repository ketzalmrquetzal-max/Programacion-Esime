#include "CalculadoraBase.h"

CalculadoraBase::CalculadoraBase() : __resultado(0) {}

double CalculadoraBase::getResultado() const {
    return __resultado;
}

double CalculadoraBase::sumar(double a, double b) {
    __resultado = a + b;
    return __resultado;
}

double CalculadoraBase::restar(double a, double b) {
    __resultado = a - b;
    return __resultado;
}
