//
// Created by Embe on 15/01/2026.
//

#ifndef EJ4ESIME_SUMA_H
#define EJ4ESIME_SUMA_H
#include "../interfaces/Operacion.h"

// Clase Suma
class Suma : public Operacion {
public:
    // Suma todos los paramteros
    double ejecutar(const Parametros& params) override;
};


#endif //EJ4ESIME_SUMA_H