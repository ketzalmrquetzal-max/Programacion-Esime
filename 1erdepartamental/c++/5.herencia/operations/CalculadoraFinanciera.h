#ifndef HERENCIA_CALCULADORA_FINANCIERA_H
#define HERENCIA_CALCULADORA_FINANCIERA_H

#include "../core/CalculadoraBase.h"

/**
 * Calculadora financiera con operaciones de negocio
 */
class CalculadoraFinanciera : public CalculadoraBase {
private:
    void validarTasa(double tasa) const;

public:
    double interesSimple(double capital, double tasa, int tiempo);
    double interesCompuesto(double capital, double tasa, int tiempo);
    double descuento(double precio, double porcentaje);
    double operacionEspecial(double valor) override;
};

#endif // HERENCIA_CALCULADORA_FINANCIERA_H
