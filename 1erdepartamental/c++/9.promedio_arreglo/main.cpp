#include <iostream>
#include "core/EstadisticasArreglo.h"

int main() {
    // Crea estadisticas con inicializer list
    EstadisticasArreglo e({10, 25, 5, 30, 15});
    
    // Muestra estadisticas iniciales
    std::cout << "Datos iniciales: " << e.getDatos().size() << " elementos" << std::endl;
    std::cout << "Suma: " << e.suma() << std::endl;
    std::cout << "Promedio: " << e.promedio() << std::endl;
    std::cout << "Máximo: " << e.maximo() << std::endl;
    std::cout << "Mínimo: " << e.minimo() << std::endl << std::endl;
    
    // Agrega un valor y recalcula
    e.agregar(50);
    std::cout << "Después de agregar 50:" << std::endl;
    std::cout << "Promedio: " << e.promedio() << std::endl;
    
    return 0;
}
