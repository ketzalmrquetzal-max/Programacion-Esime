#include <iostream>
#include "core/EstadisticasArreglo.h"

int main() {
    EstadisticasArreglo e({10, 25, 5, 30, 15});
    
    std::cout << "Datos iniciales: " << e.getDatos().size() << " elementos" << std::endl;
    std::cout << "Suma: " << e.suma() << std::endl;
    std::cout << "Promedio: " << e.promedio() << std::endl;
    std::cout << "Máximo: " << e.maximo() << std::endl;
    std::cout << "Mínimo: " << e.minimo() << std::endl << std::endl;
    
    e.agregar(50);
    std::cout << "Después de agregar 50:" << std::endl;
    std::cout << "Promedio: " << e.promedio() << std::endl;
    
    return 0;
}
