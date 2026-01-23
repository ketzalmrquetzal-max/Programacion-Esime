#include "Matriz.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

void Matriz::validarDimensiones(size_t f, size_t c) const {
    if (f == 0 || c == 0) throw std::invalid_argument("Dimensiones deben ser > 0");
}

Matriz::Matriz(size_t filas, size_t columnas) : __filas(filas), __columnas(columnas) {
    validarDimensiones(filas, columnas);
    __datos.resize(filas, std::vector<double>(columnas, 0));
}

size_t Matriz::getFilas() const { return __filas; }
size_t Matriz::getColumnas() const { return __columnas; }

void Matriz::set(size_t i, size_t j, double valor) {
    if (i >= __filas || j >= __columnas) throw std::out_of_range("Índice fuera de rango");
    __datos[i][j] = valor;
}

double Matriz::get(size_t i, size_t j) const {
    if (i >= __filas || j >= __columnas) throw std::out_of_range("Índice fuera de rango");
    return __datos[i][j];
}

void Matriz::llenar(double valor) {
    for (auto& fila : __datos) {
        for (auto& elem : fila) {
            elem = valor;
        }
    }
}

Matriz Matriz::operator*(double escalar) const {
    Matriz resultado(__filas, __columnas);
    for (size_t i = 0; i < __filas; i++) {
        for (size_t j = 0; j < __columnas; j++) {
            resultado.set(i, j, __datos[i][j] * escalar);
        }
    }
    return resultado;
}

Matriz Matriz::operator*(const Matriz& otra) const {
    if (__columnas != otra.__filas) {
        throw std::invalid_argument("Dimensiones incompatibles");
    }
    Matriz resultado(__filas, otra.__columnas);
    for (size_t i = 0; i < __filas; i++) {
        for (size_t j = 0; j < otra.__columnas; j++) {
            double suma = 0;
            for (size_t k = 0; k < __columnas; k++) {
                suma += __datos[i][k] * otra.__datos[k][j];
            }
            resultado.set(i, j, suma);
        }
    }
    return resultado;
}

std::ostream& operator<<(std::ostream& os, const Matriz& m) {
    for (size_t i = 0; i < m.__filas; i++) {
        os << "[ ";
        for (size_t j = 0; j < m.__columnas; j++) {
            os << std::setw(6) << std::fixed << std::setprecision(2) << m.__datos[i][j];
            if (j < m.__columnas - 1) os << ", ";
        }
        os << " ]" << std::endl;
    }
    return os;
}
