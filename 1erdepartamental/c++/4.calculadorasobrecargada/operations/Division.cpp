//
// Created by Embe on 15/01/2026.
//

#include "Division.h"
#include "../utils/Parametros.h"
#include <stdexcept>

double Division::ejecutar(const Parametros& params) {
    if (params.cantidad() < 2) {
        throw std::runtime_error("ingresa 2 ");
    }

    double resultado = params.obtener(0);

    for (int i = 1; i < params.cantidad(); i++) {
        double divisor = params.obtener(i);

        if (divisor == 0.0) {
            throw std::runtime_error("indefinidoa");
        }

        resultado /= divisor;
    }

    return resultado;
}
