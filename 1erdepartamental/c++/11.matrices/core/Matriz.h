#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>

// Clase Matriz con sobrecarga de operador * para escalar y multiplicación matricial
class Matriz {
private:
    std::vector<std::vector<double>> __datos;  // Vector 2D para almacenar la matriz
    size_t __filas, __columnas;
    void validarDimensiones(size_t f, size_t c) const;

public:
    Matriz(size_t filas, size_t columnas);
    size_t getFilas() const;
    size_t getColumnas() const;
    void set(size_t i, size_t j, double valor);
    double get(size_t i, size_t j) const;
    void llenar(double valor);
    
    Matriz operator*(double escalar) const;  // Multiplicación por escalar
    Matriz operator*(const Matriz& otra) const;  // Multiplicación matricial
    friend std::ostream& operator<<(std::ostream& os, const Matriz& m);
};

#endif
