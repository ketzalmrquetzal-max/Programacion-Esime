#ifndef CALCULADORA_DIRECTA_H
#define CALCULADORA_DIRECTA_H

#include "../core/CalculadoraBase.h"

// Implementación directa - usa operadores nativos de C++
class CalculadoraDirecta : public CalculadoraBase {
public:
    // Multiplica usando operador nativo
    double multiplicar(double a, int veces) override;
    // Calcula potencia con loop
    double potencia(double base, int exponente) override;
    // Divide usando operador nativo
    double dividir(double a, int divisor) override;
};

#endif
