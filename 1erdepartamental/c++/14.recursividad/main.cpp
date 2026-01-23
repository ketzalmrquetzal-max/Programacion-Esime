#include <iostream>
#include "core/AlgoritmosRecursivos.h"

int main() {
    AlgoritmosRecursivos algo;
    
    std::cout << "Factorial de 5: " << algo.factorial(5) << std::endl;
    std::cout << "Fibonacci de 7: " << algo.fibonacci(7) << std::endl;
    std::cout << "Suma hasta 10: " << algo.sumaHasta(10) << std::endl;
    std::cout << "2^8: " << algo.potenciar(2, 8) << std::endl;
    
    return 0;
}
