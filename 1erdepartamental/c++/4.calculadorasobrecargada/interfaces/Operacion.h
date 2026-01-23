//
// Created by Embe on 15/01/2026.
//

#ifndef EJ4ESIME_OPERACION_H
#define EJ4ESIME_OPERACION_H

#include "../utils/Parametros.h"

class Operacion {
public:
    virtual double ejecutar(const Parametros& params) = 0 ;
    virtual ~Operacion() = default;
};


#endif //EJ4ESIME_OPERACION_H