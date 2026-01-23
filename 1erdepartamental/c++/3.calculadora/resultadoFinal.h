#ifndef RESULTADOFINAL_H
#define RESULTADOFINAL_H

#include <iostream>
#include "operaciones.h"
using namespace std;

class resultado_final : public operaciones {
public:
    void mostrar(double r) {
        cout << "Resultado: " << r << endl;
    }
};

#endif