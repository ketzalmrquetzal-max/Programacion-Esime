#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "../interfaces/ICalculadora.h"

// Calculadora con operaciones básicas y manejo de excepciones
class Calculadora : public ICalculadora {
private:
    double __resultado;  // Almacena el último resultado calculado

public:
    // Constructor - Inicializa el resultado en cero
    Calculadora();
    
    // Obtiene el último resultado calculado
    double getResultado() const override;
    
    // Suma dos numeros
    double sumar(double a, double b);
    // Resta dos números
    double restar(double a, double b);
    // Multiplica dos números
    double multiplicar(double a, double b);
    // Divide dos números con validación de cero
    double dividir(double a, double b);
};

#endif // CALCULADORA_H
