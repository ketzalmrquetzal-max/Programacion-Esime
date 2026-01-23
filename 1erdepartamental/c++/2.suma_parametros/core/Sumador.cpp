#include "Sumador.h"
#include <iostream>
#include <stdexcept>

void Sumador::validarRango(double valor) const {
    if (valor < -1000000 || valor > 1000000) {
        throw std::out_of_range("Valor fuera de rango permitido");
    }
}

Sumador::Sumador(double a, double b) : __a(0), __b(0) {
    setA(a);
    setB(b);
}

double Sumador::getA() const { return __a; }
double Sumador::getB() const { return __b; }

void Sumador::setA(double valor) {
    validarRango(valor);
    __a = valor;
}

void Sumador::setB(double valor) {
    validarRango(valor);
    __b = valor;
}

double Sumador::sumar() const {
    return __a + __b;
}

double Sumador::operar() {
    return sumar();
}

Sumador Sumador::operator+(const Sumador& otro) const {
    return Sumador(__a + otro.__a, __b + otro.__b);
}

std::ostream& operator<<(std::ostream& os, const Sumador& s) {
    os << "Sumador(a=" << s.__a << ", b=" << s.__b << ", suma=" << s.sumar() << ")";
    return os;
}
