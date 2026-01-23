#include "AlgoritmosRecursivos.h"
#include <stdexcept>

// Valida numero no negativo
void AlgoritmosRecursivos::validarNoNegativo(int n) const {
    if (n < 0) throw std::invalid_argument("El valor no puede ser negativo");
}

// Calcula factorial recursivamente
long long AlgoritmosRecursivos::factorial(int n) {
    validarNoNegativo(n);
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

// Calcula fibonacci recursivamente
long long AlgoritmosRecursivos::fibonacci(int n) {
    validarNoNegativo(n);
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Suma recursiva hasta n
long long AlgoritmosRecursivos::sumaHasta(int n) {
    if (n < 1) throw std::invalid_argument("n debe ser >= 1");
    if (n == 1) return 1;
    return n + sumaHasta(n - 1);
}

// Calcula potencia recursivamente
double AlgoritmosRecursivos::potenciar(double base, int potencia) {
    validarNoNegativo(potencia);
    if (potencia == 0) return 1;
    return base * potenciar(base, potencia - 1);
}
