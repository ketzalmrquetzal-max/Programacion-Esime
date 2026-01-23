#include <iostream>
#include "core/EstadisticasEstudiantes.h"

int main() {
    // Crea estadisticas
    EstadisticasEstudiantes stats;
    
    // Agrega estudiantes
    stats.agregar(Estudiante("Ana", 9.5));
    stats.agregar(Estudiante("Luis", 8.7));
    stats.agregar(Estudiante("Carlos", 9.8));
    
    std::cout << "Promedio general: " << stats.promedioGeneral() << std::endl;
    std::cout << "Mejor estudiante: " << stats.mejorEstudiante() << std::endl;
    
    return 0;
}
