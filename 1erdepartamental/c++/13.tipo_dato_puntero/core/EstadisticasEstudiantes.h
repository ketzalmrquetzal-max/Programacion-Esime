#ifndef ESTADISTICAS_ESTUDIANTES_H
#define ESTADISTICAS_ESTUDIANTES_H

#include <vector>
#include "Estudiante.h"
#include "../utils/PunteroTipado.h"

class EstadisticasEstudiantes {
private:
    std::vector<Estudiante> __estudiantes;

public:
    void agregar(const Estudiante& e);
    double promedioGeneral();
    Estudiante mejorEstudiante();
};

#endif
