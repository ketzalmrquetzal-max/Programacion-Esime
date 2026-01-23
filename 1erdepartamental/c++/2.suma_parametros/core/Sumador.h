#ifndef SUMA_PARAMETROS_SUMADOR_H
#define SUMA_PARAMETROS_SUMADOR_H

#include "../interfaces/IOperadorMatematico.h"

// Sumador con parámetros por defecto y operator overloading
class Sumador : public IOperadorMatematico {
private:
    double __a;
    double __b;
    
    void validarRango(double valor) const;  // Valida que el valor esté en rango permitido

public:
    Sumador(double a = 0, double b = 0);
    
    double getA() const;
    double getB() const;
    void setA(double valor);
    void setB(double valor);
    
    double sumar() const;
    double operar() override;
    
    Sumador operator+(const Sumador& otro) const;  // Permite s1 + s2
    friend std::ostream& operator<<(std::ostream& os, const Sumador& s);  // Para std::cout << sumador
};

#endif // SUMA_PARAMETROS_SUMADOR_H
