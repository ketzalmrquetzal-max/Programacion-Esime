#ifndef CALCULADORA_BASE_H
#define CALCULADORA_BASE_H

#include "../interfaces/ICalculadora.h"

// Clase base CalculadoraBase
class CalculadoraBase : public ICalculadora {
protected:
    double __resultado;

public:
    // Constructor - inicialisa resultado
    CalculadoraBase();
    // Destructor virtual
    virtual ~CalculadoraBase() = default;
    // Obtiene el resultado
    double getResultado() const override;
};

#endif
