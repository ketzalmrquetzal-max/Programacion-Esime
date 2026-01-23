//
// Created by Embe on 15/01/2026.
//

#include "Calculadora.h"


double Calculadora::calcular(Operacion& op, const Parametros &params) {
    return op.ejecutar(params);
}
