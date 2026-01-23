//
// Created by Embe on 15/01/2026.
//

#include "Parametros.h"

void Parametros::agregar(double valor) {
    valores.push_back(valor);
}

double Parametros::obtener(int indice) const {
    return valores.at(indice); // at() valida rango
}

int Parametros::cantidad() const {
    return valores.size();
}
