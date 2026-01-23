#ifndef HERENCIA_ICALCULADORA_H
#define HERENCIA_ICALCULADORA_H

// Interfaz ICalculadora
class ICalculadora {
public:
    // Obtiene el resultado acutal
    virtual double getResult ado() const = 0;
    // Operacion especial de cada calculadora
    virtual double operacionEspecial(double valor) = 0;
    // Destructor virtual
    virtual ~ICalculadora() = default;
};

#endif // HERENCIA_ICALCULADORA_H
