#ifndef CALCULADORA_ICALCULADORA_H
#define CALCULADORA_ICALCULADORA_H

/**
 * Interfaz para calculadoras básicas
 */
class ICalculadora {
public:
    virtual double getResultado() const = 0;
    virtual ~ICalculadora() = default;
};

#endif // CALCULADORA_ICALCULADORA_H
