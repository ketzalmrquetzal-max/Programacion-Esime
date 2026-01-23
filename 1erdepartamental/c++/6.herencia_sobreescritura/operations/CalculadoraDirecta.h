#ifndef CALCULADORA_DIRECTA_H
#define CALCULADORA_DIRECTA_H

#include "../core/CalculadoraBase.h"

// Implementación directa - usa operadores nativos de C++
class CalculadoraDirecta : public CalculadoraBase {
public:
    double multiplicar(double a, int veces) override;
    double potencia(double base, int exponente) override;
    double dividir(double a, int divisor) override;
};

#endif
