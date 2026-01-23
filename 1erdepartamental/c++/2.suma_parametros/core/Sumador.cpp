#include "Sumador.h"
#include <iostream>
#include <stdexcept>

// Valida que el valor esté dentro del rango permitido
void Sumador::validarRango(double valor) const {
    if (valor < -1000000 || valor > 1000000) {
        throw std::out_of_range("Valor fuera de rango permitido");
    }
}

// Constructor - Inicializa los valores con validación
Sumador::Sumador(double a, double b) : __a(0), __b(0) {
    setA(a);
    setB(b);
}

// Obtiene el valor de a
double Sumador::getA() const { return __a; }
// Obtiene el valor de b
double Sumador::getB() const { return __b; }

// Establece el valor de a con validación
void Sumador::setA(double valor) {
    validarRango(valor);
    __a = valor;
}

// Establece el valor de b con validación
void Sumador::setB(double valor) {
    validarRango(valor);
    __b = valor;
}

// Retorna la suma de a y b
double Sumador::sumar() const {
    return __a + __b;
}

// Implementa el método de la interfaz
double Sumador::operar() {
    return sumar();
}

// Sobrecarga del operador +
Sumador Sumador::operator+(const Sumador& otro) const {
    return Sumador(__a + otro.__a, __b + otro.__b);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const Sumador& s) {
    os << "Sumador(a=" << s.__a << ", b=" << s.__b << ", suma=" << s.sumar() << ")";
    return os;
}
