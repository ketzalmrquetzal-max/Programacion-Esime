#include "EstadisticasEstudiantes.h"

void EstadisticasEstudiantes::agregar(const Estudiante& e) {
    __estudiantes.push_back(e);
}

double EstadisticasEstudiantes::promedioGeneral() {
    PunteroTipado<Estudiante> p(&__estudiantes);
    double suma = 0;
    while (p.enRango()) {
        suma += p.getAt().getPromedio();
        p.avanzar();
    }
    return suma / __estudiantes.size();
}

Estudiante EstadisticasEstudiantes::mejorEstudiante() {
    PunteroTipado<Estudiante> p(&__estudiantes);
    Estudiante mejor = p.getAt();
    while (p.enRango()) {
        if (p.getAt() > mejor) {
            mejor = p.getAt();
        }
        p.avanzar();
    }
    return mejor;
}
