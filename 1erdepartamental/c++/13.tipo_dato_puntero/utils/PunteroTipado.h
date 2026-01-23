#ifndef PUNTERO_TIPADO_H
#define PUNTERO_TIPADO_H

#include <vector>
#include <stdexcept>

template<typename T>
class PunteroTipado {
private:
    std::vector<T>* __datos;
    size_t __indice;

public:
    PunteroTipado(std::vector<T>* datos) : __datos(datos), __indice(0) {}
    
    T& getAt() {
        if (__indice >= __datos->size()) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return (*__datos)[__indice];
    }
    
    void avanzar() { __indice++; }
    void reset() { __indice = 0; }
    bool enRango() const { return __indice < __datos->size(); }
};

#endif
