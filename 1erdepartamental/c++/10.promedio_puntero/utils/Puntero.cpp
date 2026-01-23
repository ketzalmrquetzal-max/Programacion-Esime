#include "Puntero.h"

void Puntero::validarIndice() const {
    if (__indice >= __datos->size()) {
        throw std::out_of_range("Índice fuera de rango");
    }
}

Puntero::Puntero(std::vector<double>* datos) : __datos(datos), __indice(0) {}

double Puntero::getAt() const {
    validarIndice();
    return (*__datos)[__indice];
}

void Puntero::avanzar() { __indice++; }
void Puntero::reset() { __indice = 0; }
bool Puntero::enRango() const { return __indice < __datos->size(); }
size_t Puntero::getIndice() const { return __indice; }
