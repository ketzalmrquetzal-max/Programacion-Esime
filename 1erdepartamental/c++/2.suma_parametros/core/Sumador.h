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
    // Constructor - Inicializa los dos números
    Sumador(double a = 0, double b = 0);
    
    // Obtiene el valor de a
    double getA() const;
    // Obtiene el valor de b
    double getB() const;
    // Establece el valor de a con validación
    void setA(double valor);
    // Establece el valor de b con validación
    void setB(double valor);
    
    // Retorna la suma de a y b
    double sumar() const;
    // Implementa el método de la interfaz
    double operar() override;
    
    Sumador operator+(const Sumador& otro) const;  // Permite s1 + s2
    friend std::ostream& operator<<(std::ostream& os, const Sumador& s);  // Para std::cout << sumador
};

#endif // SUMA_PARAMETROS_SUMADOR_H
