#include <iostream>
#include "operations/OrdenadorIndirectoBurbuja.h"

int main() {
    std::vector<int> numeros = {64, 34, 25, 12, 22, 11, 90};
    
    OrdenadorIndirectoBurbuja<int> ordenador(numeros);
    
    ordenador.mostrarOriginal();
    ordenador.ordenar();
    ordenador.mostrarOrdenado();
    ordenador.mostrarOriginal();
    
    return 0;
}
