#include <iostream>
#include "operations/OrdenadorBurbuja.h"

int main() {
    std::vector<int> numeros = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Array original: ";
    for (int n : numeros) std::cout << n << " ";
    std::cout << std::endl << std::endl;
    
    OrdenadorBurbuja<int> ordenador;
    ordenador.ordenar(numeros);
    
    std::cout << "Array ordenado: ";
    for (int n : numeros) std::cout << n << " ";
    std::cout << std::endl << std::endl;
    
    ordenador.mostrarEstadisticas();
    
    return 0;
}
