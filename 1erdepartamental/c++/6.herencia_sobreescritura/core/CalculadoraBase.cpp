#include "CalculadoraBase.h"

// Constructor - inicializa resultado en cero
CalculadoraBase::CalculadoraBase() : __resultado(0) {}

// Obtiene el resultado
double CalculadoraBase::getResultado() const {
    return __resultado;
}
