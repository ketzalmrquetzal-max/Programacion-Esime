#ifndef HERENCIA_SOBREESCRITURA_ICALCULADORA_H
#define HERENCIA_SOBREESCRITURA_ICALCULADORA_H

class ICalculadora {
public:
    // Obtiene el resultado
    virtual double getResultado() const = 0;
    // Multiplca un numero por veces
    virtual double multiplicar(double a, int veces) = 0;
    // Calcula la potencia
    virtual double potencia(double base, int exponente) = 0;
    // Divide un numero
    virtual double dividir(double a, int divisor) = 0;
    // Destructor virtual
    virtual ~ICalculadora() = default;
};

#endif
