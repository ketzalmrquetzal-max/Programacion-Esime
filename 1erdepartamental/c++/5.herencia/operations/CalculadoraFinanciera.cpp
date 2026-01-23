#include "CalculadoraFinanciera.h"
#include <cmath>
#include <stdexcept>

void CalculadoraFinanciera::validarTasa(double tasa) const {
    if (tasa < 0 || tasa > 1) {
        throw std::invalid_argument("Tasa debe estar entre 0 y 1");
    }
}

double CalculadoraFinanciera::interesSimple(double capital, double tasa, int tiempo) {
    validarTasa(tasa);
    __resultado = capital * tasa * tiempo;
    return __resultado;
}

double CalculadoraFinanciera::interesCompuesto(double capital, double tasa, int tiempo) {
    validarTasa(tasa);
    __resultado = capital * (std::pow(1 + tasa, tiempo) - 1);
    return __resultado;
}

double CalculadoraFinanciera::descuento(double precio, double porcentaje) {
    if (porcentaje < 0 || porcentaje > 100) {
        throw std::invalid_argument("Porcentaje debe estar entre 0 y 100");
    }
    __resultado = precio * (porcentaje / 100);
    return __resultado;
}

double CalculadoraFinanciera::operacionEspecial(double valor) {
    return descuento(valor, 15);
}
