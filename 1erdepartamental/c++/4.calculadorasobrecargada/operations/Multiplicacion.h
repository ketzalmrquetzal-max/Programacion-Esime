//
// Created by Embe on 15/01/2026.
//

#ifndef EJ4ESIME_MULTIPLICACION_H
#define EJ4ESIME_MULTIPLICACION_H
#include "../interfaces/Operacion.h"

class Multiplicacion : public Operacion {
public:
    double ejecutar(const Parametros& params) override;
};

#endif //EJ4ESIME_MULTIPLICACION_H