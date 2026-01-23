#include "Puntero.h"

// Valida que el indice esté en rango
void Puntero::validarIndice() const {
    if (__indice >= __datos->size()) {
        throw std::out_of_range("Índice fuera de rango");
    }
}

// Constructor - inicializa puntero
Puntero::Puntero(std::vector<double>* datos) : __datos(datos), __indice(0) {}

// Obtiene el valor en la posicion actual
double Puntero::getAt() const {
    validarIndice();
    return (*__datos)[__indice];
}

// Avanza el indice
void Puntero::avanzar() { __indice++; }
// Reinicia el indice a cero
void Puntero::reset() { __indice = 0; }
// Verifica si esta en rango valido
bool Puntero::enRango() const { return __indice < __datos->size(); }
// Obtiene el indice actual
size_t Puntero::getIndice() const { return __indice; }
