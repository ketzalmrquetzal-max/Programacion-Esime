#ifndef HERENCIA_ICALCULADORA_H
#define HERENCIA_ICALCULADORA_H

/**
 * Interfaz base para calculadoras
 */
class ICalculadora {
public:
    virtual double getResultado() const = 0;
    virtual double operacionEspecial(double valor) = 0;
    virtual ~ICalculadora() = default;
};

#endif // HERENCIA_ICALCULADORA_H
