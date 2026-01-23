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
    // Constructor - crea matriz con dimensiones
    Matriz(size_t filas, size_t columnas);
    // Obtiene numero de filas
    size_t getFilas() const;
    // Obtiene numero de columnas
    size_t getColumnas() const;
    // Establece valor en posicion
    void set(size_t i, size_t j, double valor);
    // Obtiene valor en posicion
    double get(size_t i, size_t j) const;
    // Llena la matriz con un valor
    void llenar(double valor);
    
    // Multiplicacion por escalar
    Matriz operator*(double escalar) const;
    // Multiplicacion matricial
    Matriz operator*(const Matriz& otra) const;
    // Sobrecarga operador <<
    friend std::ostream& operator<<(std::ostream& os, const Matriz& m);
};

#endif
