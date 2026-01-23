#ifndef ALGORITMOS_RECURSIVOS_H
#define ALGORITMOS_RECURSIVOS_H

// Algoritmos clásicos implementados con recursividad
class AlgoritmosRecursivos {
private:
    void validarNoNegativo(int n) const;

public:
    // Calcula factorial
    long long factorial(int n);
    // Calcula fibonacci
    long long fibonacci(int n);
    // Suma hasta n
    long long sumaHasta(int n);
    // Calcula potencia
    double potenciar(double base, int potencia);
};

#endif
