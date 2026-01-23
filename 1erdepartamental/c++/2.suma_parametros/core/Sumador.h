#ifndef SUMA_PARAMETROS_SUMADOR_H
#define SUMA_PARAMETROS_SUMADOR_H

#include "../interfaces/IOperadorMatematico.h"

/**
 * Sumador con parámetros por defecto
 */
class Sumador : public IOperadorMatematico {
private:
    double __a;
    double __b;
    
    void validarRango(double valor) const;

public:
    Sumador(double a = 0, double b = 0);
    
    double getA() const;
    double getB() const;
    void setA(double valor);
    void setB(double valor);
    
    double sumar() const;
    double operar() override;
    
    Sumador operator+(const Sumador& otro) const;
    friend std::ostream& operator<<(std::ostream& os, const Sumador& s);
};

#endif // SUMA_PARAMETROS_SUMADOR_H
