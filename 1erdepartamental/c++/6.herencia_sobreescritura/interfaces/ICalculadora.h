#ifndef HERENCIA_SOBREESCRITURA_ICALCULADORA_H
#define HERENCIA_SOBREESCRITURA_ICALCULADORA_H

class ICalculadora {
public:
    virtual double getResultado() const = 0;
    virtual double multiplicar(double a, int veces) = 0;
    virtual double potencia(double base, int exponente) = 0;
    virtual double dividir(double a, int divisor) = 0;
    virtual ~ICalculadora() = default;
};

#endif
