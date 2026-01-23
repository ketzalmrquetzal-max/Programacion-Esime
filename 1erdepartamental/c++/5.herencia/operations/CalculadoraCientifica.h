#ifndef HERENCIA_CALCULADORA_CIENTIFICA_H
#define HERENCIA_CALCULADORA_CIENTIFICA_H

#include "../core/CalculadoraBase.h"

// Calculadora especializada - hereda de CalculadoraBase y agrega funciones científicas
class CalculadoraCientifica : public CalculadoraBase {
public:
    // Calcula la raiz cuadrada
    double raizCuadrada(double n);
    // Calcula la potencia
    double potencia(double base, double exponente);
    // Calcula el seno de un angulo
    double seno(double angulo);
    // Operacion especial - retorna raiz cuadrada
    double operacionEspecial(double valor) override;
};

#endif // HERENCIA_CALCULADORA_CIENTIFICA_H
