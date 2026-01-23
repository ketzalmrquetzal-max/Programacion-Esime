#ifndef ALGORITMOS_RECURSIVOS_H
#define ALGORITMOS_RECURSIVOS_H

// Algoritmos clásicos implementados con recursividad
class AlgoritmosRecursivos {
private:
    void validarNoNegativo(int n) const;

public:
    long long factorial(int n);
    long long fibonacci(int n);
    long long sumaHasta(int n);
    double potenciar(double base, int potencia);
};

#endif
