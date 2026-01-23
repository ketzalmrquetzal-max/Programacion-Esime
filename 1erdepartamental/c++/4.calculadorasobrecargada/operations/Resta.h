ss

#ifndef EJ4ESIME_RESTA_H
#define EJ4ESIME_RESTA_H
#include "../interfaces/Operacion.h"


// Clase Resta
class Resta : public Operacion {
public:
    //Resta todos los parametros
    double ejecutar(const Parametros& params) override;
};


#endif //EJ4ESIME_RESTA_H