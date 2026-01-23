#ifndef PUNTERO_TIPADO_H
#define PUNTERO_TIPADO_H

#include <vector>
#include <stdexcept>

// Puntero tipado generico
template<typename T>
class PunteroTipado {
private:
    std::vector<T>* __datos;
    size_t __indice;

public:
    // Constructor
    PunteroTipado(std::vector<T>* datos) : __datos(datos), __indice(0) {}
    
    // Obtiene elemento actual
    T& getAt() {
        if (__indice >= __datos->size()) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return (*__datos)[__indice];
    }
    
    // Avanza puntero
    void avanzar() { __indice++; }
    // Reinicia puntero
    void reset() { __indice = 0; }
    // Verifica rango
    bool enRango() const { return __indice < __datos->size(); }
};

#endif
