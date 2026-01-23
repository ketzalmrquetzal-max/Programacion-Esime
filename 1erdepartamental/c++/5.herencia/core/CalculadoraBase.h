#ifndef HERENCIA_CALCULADORA_BASE_H
#define HERENCIA_CALCULADORA_BASE_H

#include "../interfaces/ICalculadora.h"

// Clase base abstracta - define comportamiento común
class CalculadoraBase : public ICalculadora {
protected:
    double __resultado;  // Protected permite acceso a clases hijas

public:
    CalculadoraBase();
    virtual ~CalculadoraBase() = default;
    
    double getResultado() const override;
    
    virtual double sumar(double a, double b);
    virtual double restar(double a, double b);
    virtual double operacionEspecial(double valor) = 0;
};

#endif // HERENCIA_CALCULADORA_BASE_H
