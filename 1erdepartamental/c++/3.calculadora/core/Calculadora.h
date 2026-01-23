#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "../interfaces/ICalculadora.h"

/**
 * Calculadora con operaciones básicas y manejo de excepciones
 */
class Calculadora : public ICalculadora {
private:
    double __resultado;

public:
    Calculadora();
    
    double getResultado() const override;
    
    double sumar(double a, double b);
    double restar(double a, double b);
    double multiplicar(double a, double b);
    double dividir(double a, double b);
};

#endif // CALCULADORA_H
