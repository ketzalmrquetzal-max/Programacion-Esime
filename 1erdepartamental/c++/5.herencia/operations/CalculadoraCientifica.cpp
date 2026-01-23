#include "CalculadoraCientifica.h"
#include <cmath>
#include <stdexcept>

// Calcula la rai zcuadrada con validacion
double CalculadoraCientifica::raizCuadrada(double n) {
    if (n < 0) {
        throw std::invalid_argument("No se puede calcular raíz de número negativo");
    }
    __resultado = std::sqrt(n);
    return __resultado;
}

// Calcula la potencia
double CalculadoraCientifica::potencia(double base, double exponente) {
    __resultado = std::pow(base, exponente);
    return __resultado;
}

// Calcula el seno de un angulo
double CalculadoraCientifica::seno(double angulo) {
    __resultado = std::sin(angulo);
    return __resultado;
}

// Operacion especial - retorna raiz cuadrada
double CalculadoraCientifica::operacionEspecial(double valor) {
    return raizCuadrada(valor);
}
