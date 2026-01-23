//
// Created by Embe on 15/01/2026.
//

#include "Parametros.h"

// Agrega un valor al vector
void Parametros::agregar(double valor) {
    valores.push_back(valor);
}

// Obtieno el valor en el indice especificado
double Parametros::obtener(int indice) const {
    return valores.at(indice); // at() valida rango
}

// Retorna el numero de valores
int Parametros::cantidad() const {
    return valores.size();
}
