// ============================================
// PROGRAMA: Algoritmos Recursivos
// DESCRIPCIÓN: Factorial, Fibonacci, Suma
// ============================================

#include <iostream>
#include <stdexcept>
using namespace std;


/**
 * Algoritmos recursivos encapsulados
 * 
 * Cada método tiene caso base y caso recursivo claros
 */
class AlgoritmosRecursivos {
private:
    void validarNoNegativo(int n) const {
        if (n < 0) {
            throw invalid_argument("El valor no puede ser negativo");
        }
    }

public:
    // Base: n == 0 -> 1
    // Recursivo: n * factorial(n-1)
    long long factorial(int n) {
        validarNoNegativo(n);
        if (n == 0) return 1;
        return n * factorial(n - 1);
    }
    
    // Base: n <= 1 -> n
    // Recursivo: fib(n-1) + fib(n-2)
    long long fibonacci(int n) {
        validarNoNegativo(n);
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    // Base: n == 1 -> 1
    // Recursivo: n + sumaHasta(n-1)
    long long sumaHasta(int n) {
        if (n < 1) {
            throw invalid_argument("n debe ser >= 1");
        }
        if (n == 1) return 1;
        return n + sumaHasta(n - 1);
    }
    
    // Base: potencia == 0 -> 1
    // Recursivo: base * potenciar(base, potencia-1)
    double potenciar(double base, int potencia) {
        validarNoNegativo(potencia);
        if (potencia == 0) return 1;
        return base * potenciar(base, potencia - 1);
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    AlgoritmosRecursivos algo;
    
    cout << "Factorial de 5: " << algo.factorial(5) << endl;
    cout << "Fibonacci de 7: " << algo.fibonacci(7) << endl;
    cout << "Suma hasta 10: " << algo.sumaHasta(10) << endl;
    cout << "2^8: " << algo.potenciar(2, 8) << endl;
    
    return 0;
}
