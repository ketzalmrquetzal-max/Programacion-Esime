#include "CalculadoraBase.h"

CalculadoraBase::CalculadoraBase() : __resultado(0) {}

double CalculadoraBase::getResultado() const {
    return __resultado;
}
