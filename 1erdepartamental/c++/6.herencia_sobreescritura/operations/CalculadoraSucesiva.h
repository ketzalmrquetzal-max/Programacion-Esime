#ifndef CALCULADORA_SUCESIVA_H
#define CALCULADORA_SUCESIVA_H

#include "../core/CalculadoraBase.h"

// Implementación algorítmica - usa loops en lugar de operadores nativos
class CalculadoraSucesiva : public CalculadoraBase {
public:
    // Multiplica con sumas sucesivas
    double multiplicar(double a, int veces) override;
    // Calcula potencia con multiplicaciones
    double potencia(double base, int exponente) override;
    // Divide con restas sucesibas
    double dividir(double a, int divisor) override;
};

#endif
