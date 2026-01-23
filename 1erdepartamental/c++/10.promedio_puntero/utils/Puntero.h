#ifndef PUNTERO_H
#define PUNTERO_H

#include <vector>
#include <stdexcept>

// Clase Puntero - simula punteros
class Puntero {
private:
    std::vector<double>* __datos;
    size_t __indice;
    void validarIndice() const;

public:
    // Constructor - inicialisa con un vector
    Puntero(std::vector<double>* datos);
    // Obtiene el valor actual
    double getAt() const;
    // Avanza el puntero
    void avanzar();
    // Reinicia el puntero
    void reset();
    // Verifica si esta en rango
    bool enRango() const;
    // Obtiene el indice actual
    size_t getIndice() const;
};

#endif
