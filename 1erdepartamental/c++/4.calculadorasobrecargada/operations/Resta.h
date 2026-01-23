ss

#ifndef EJ4ESIME_RESTA_H
#define EJ4ESIME_RESTA_H
#include "../interfaces/Operacion.h"


class Resta : public Operacion {
public:
    double ejecutar(const Parametros& params) override;
};


#endif //EJ4ESIME_RESTA_H