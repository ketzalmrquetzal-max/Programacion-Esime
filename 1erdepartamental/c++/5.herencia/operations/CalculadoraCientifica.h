#ifndef HERENCIA_CALCULADORA_CIENTIFICA_H
#define HERENCIA_CALCULADORA_CIENTIFICA_H

#include "../core/CalculadoraBase.h"

// Calculadora especializada - hereda de CalculadoraBase y agrega funciones científicas
class CalculadoraCientifica : public CalculadoraBase {
public:
    double raizCuadrada(double n);
    double potencia(double base, double exponente);
    double seno(double angulo);
    double operacionEspecial(double valor) override;
};

#endif // HERENCIA_CALCULADORA_CIENTIFICA_H
