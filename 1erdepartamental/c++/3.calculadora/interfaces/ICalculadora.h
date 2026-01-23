#ifndef CALCULADORA_ICALCULADORA_H
#define CALCULADORA_ICALCULADORA_H

// Interfaz ICalculadora
class ICalculadora {
public:
    // Obt iene el último resultado calculado
    virtual double getResultado() const = 0;
    // Destructor virtual por defecto
    virtual ~ICalculadora() = default;
};

#endif // CALCULADORA_ICALCULADORA_H
