#ifndef OPERACIONES_H
#define OPERACIONES_H
#include <iostream>
#include "obtenerDatos.h"
using namespace std;

class operaciones : public obtener_datos {
public:
    double resultado;

    operaciones() {
        resultado = 0;
    }

    double sumar() {
        resultado = a + b;
        return resultado;
    }

    double restar() {
        resultado = a - b;
        return resultado;
    }

    double multiplicar() {
        resultado = a * b;
        return resultado;
    }

    double dividir() {
        if (b != 0) {
            resultado = a / b;
        } else {
            cout << "Error: division entre cero" << endl;
            resultado = 0;
        }
        return resultado;
    }
};

#endif