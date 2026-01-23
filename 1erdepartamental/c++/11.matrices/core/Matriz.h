#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>

class Matriz {
private:
    std::vector<std::vector<double>> __datos;
    size_t __filas, __columnas;
    void validarDimensiones(size_t f, size_t c) const;

public:
    Matriz(size_t filas, size_t columnas);
    size_t getFilas() const;
    size_t getColumnas() const;
    void set(size_t i, size_t j, double valor);
    double get(size_t i, size_t j) const;
    void llenar(double valor);
    
    Matriz operator*(double escalar) const;
    Matriz operator*(const Matriz& otra) const;
    friend std::ostream& operator<<(std::ostream& os, const Matriz& m);
};

#endif
