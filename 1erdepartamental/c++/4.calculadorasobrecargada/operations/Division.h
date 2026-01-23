//
// Created by Embe on 15/01/2026.
//

#ifndef EJ4ESIME_DIVISION_H
#define EJ4ESIME_DIVISION_H
#include "../interfaces/Operacion.h"



// Clase Divison
class Division : public Operacion {
public:
    // Divide los parametros secuencialmente
    double ejecutar(const Parametros& params) override;
};


#endif //EJ4ESIME_DIVISION_H