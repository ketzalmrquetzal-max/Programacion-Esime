//
// Created by Embe on 15/01/2026.
//

#ifndef EJ4ESIME_CALCULADORA_H
#define EJ4ESIME_CALCULADORA_H


#include "../interfaces/Operacion.h"

class Calculadora {
public:
    double calcular(Operacion& op, const Parametros& params);
};

#endif //EJ4ESIME_CALCULADORA_H