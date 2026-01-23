#ifndef PUNTERO_H
#define PUNTERO_H

#include <vector>
#include <stdexcept>

class Puntero {
private:
    std::vector<double>* __datos;
    size_t __indice;
    void validarIndice() const;

public:
    Puntero(std::vector<double>* datos);
    double getAt() const;
    void avanzar();
    void reset();
    bool enRango() const;
    size_t getIndice() const;
};

#endif
