#ifndef CALCULADORA_BASE_H
#define CALCULADORA_BASE_H

#include "../interfaces/ICalculadora.h"

class CalculadoraBase : public ICalculadora {
protected:
    double __resultado;

public:
    CalculadoraBase();
    virtual ~CalculadoraBase() = default;
    double getResultado() const override;
};

#endif
