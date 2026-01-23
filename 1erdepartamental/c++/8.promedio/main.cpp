#include <iostream>
#include "core/Estadisticas.h"

int main() {
    // Crea estadisticas con 5 numeros
    Estadisticas e(10, 25, 5, 30, 15);
    
    // Muestra resultados
    std::cout << "Suma: " << e.suma() << std::endl;
    std::cout << "Promedio: " << e.promedio() << std::endl;
    std::cout << "Máximo: " << e.maximo() << std::endl;
    std::cout << "Mínimo: " << e.minimo() << std::endl;
    
    return 0;
}
