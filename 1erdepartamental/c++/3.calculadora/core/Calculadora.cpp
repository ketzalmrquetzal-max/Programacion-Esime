#include "Calculadora.h"
#include <stdexcept>

// Constructor - Inicializa el resultado en cero
Calculadora::Calculadora() : __resultado(0) {}

// Obtiene el último resultado calculado
double Calculadora::getResultado() const {
    return __resultado;
}

// Suma dos números y guarda el resultado
double Calculadora::sumar(double a, double b) {
    __resultado = a + b;
    return __resultado;
}

// Resta dos números y guarda el resultado
double Calculadora::restar(double a, double b) {
    __resultado = a - b;
    return __resultado;
}

// Multiplica dos números y guarda el resultado
double Calculadora::multiplicar(double a, double b) {
    __resultado = a * b;
    return __resultado;
}

// Divide dos números con validación de división por cero
double Calculadora::dividir(double a, double b) {
    if (b == 0) {
        throw std::runtime_error("Error: división por cero");
    }
    __resultado = a / b;
    return __resultado;
}
