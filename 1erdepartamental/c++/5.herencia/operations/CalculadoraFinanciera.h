#ifndef HERENCIA_CALCULADORA_FINANCIERA_H
#define HERENCIA_CALCULADORA_FINANCIERA_H

#include "../core/CalculadoraBase.h"

// clase CalculadoraFinanciera
class CalculadoraFinanciera : public CalculadoraBase {
private:
    void validarTasa(double tasa) const;

public:
    // Calcula interes simple
    double interesSimple(double capital, double tasa, int tiempo);
    // Calcula interescompuesto
    double interesCompuesto(double capital, double tasa, int tiempo);
    // Aplica un descuento
    double descuento(double precio, double porcentaje);
    // Operacion especial - aplica descuento del 15%
    double operacionEspecial(double valor) override;
};

#endif // HERENCIA_CALCULADORA_FINANCIERA_H
