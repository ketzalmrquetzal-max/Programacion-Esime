#ifndef ESTADISTICAS_ESTUDIANTES_H
#define ESTADISTICAS_ESTUDIANTES_H

#include <vector>
#include "Estudiante.h"
#include "../utils/PunteroTipado.h"

// Clase EstadisticasEstudiantes
class EstadisticasEstudiantes {
private:
    std::vector<Estudiante> __estudiantes;

public:
    // Agrega estudiante
    void agregar(const Estudiante& e);
    // Calcula promedio general
    double promedioGeneral();
    // Encuentra mejor estudiante
    Estudiante mejorEstudiante();
};

#endif
