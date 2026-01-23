#include "CalculadoraBase.h"

// Constructor - inciializa resultado en cero
CalculadoraBase::CalculadoraBase() : __resultado(0) {}

// Obtiene el resultado
double CalculadoraBase::getResultado() const {
    return __resultado;
}

// Suma dos numeros
double CalculadoraBase::sumar(double a, double b) {
    __resultado = a + b;
    return __resultado;
}

// resta dos numeros
double CalculadoraBase::restar(double a, double b) {
    __resultado = a - b;
    return __resultado;
}
