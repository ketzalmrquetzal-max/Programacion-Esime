#ifndef HERENCIA_CALCULADORA_BASE_H
#define HERENCIA_CALCULADORA_BASE_H

#include "../interfaces/ICalculadora.h"

// Clase base abstracta - define comportamiento común
class CalculadoraBase : public ICalculadora {
protected:
    double __resultado;  // Protected permite acceso a clases hijas

public:
    // Constructor - inicializa resultado
    CalculadoraBase();
    // Destructor virtual
    virtual ~CalculadoraBase() = default;
    
    // Obtiene el resultado
    double getResultado() const override;
    
    // Suma dos numeros virtuales
    virtual double sumar(double a, double b);
    // Resta dosn umeros
    virtual double restar(double a, double b);
    // Metodo abstracto para operaciones especiales
    virtual double operacionEspecial(double valor) = 0;
};

#endif // HERENCIA_CALCULADORA_BASE_H
