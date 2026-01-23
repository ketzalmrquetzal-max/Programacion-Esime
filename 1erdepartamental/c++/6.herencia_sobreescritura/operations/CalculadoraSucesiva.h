#ifndef CALCULADORA_SUCESIVA_H
#define CALCULADORA_SUCESIVA_H

#include "../core/CalculadoraBase.h"

// Implementación algorítmica - usa loops en lugar de operadores nativos
class CalculadoraSucesiva : public CalculadoraBase {
public:
    double multiplicar(double a, int veces) override;
    double potencia(double base, int exponente) override;
    double dividir(double a, int divisor) override;
};

#endif
