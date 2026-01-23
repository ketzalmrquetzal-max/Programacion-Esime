//
// Created by Embe on 15/01/2026.
//
#include "Suma.h"

double Suma::ejecutar(const Parametros& params) {
    double resultado = 0.0;

    for (int i = 0; i < params.cantidad(); i++) {
        resultado += params.obtener(i);
    }

    return resultado;
}
