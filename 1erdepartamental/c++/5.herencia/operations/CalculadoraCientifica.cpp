#include "CalculadoraCientifica.h"
#include <cmath>
#include <stdexcept>

double CalculadoraCientifica::raizCuadrada(double n) {
    if (n < 0) {
        throw std::invalid_argument("No se puede calcular raíz de número negativo");
    }
    __resultado = std::sqrt(n);
    return __resultado;
}

double CalculadoraCientifica::potencia(double base, double exponente) {
    __resultado = std::pow(base, exponente);
    return __resultado;
}

double CalculadoraCientifica::seno(double angulo) {
    __resultado = std::sin(angulo);
    return __resultado;
}

double CalculadoraCientifica::operacionEspecial(double valor) {
    return raizCuadrada(valor);
}
