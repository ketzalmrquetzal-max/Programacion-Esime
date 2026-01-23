//
// Created by Embe on 15/01/2026.
//

#ifndef EJ4ESIME_PARAMETROS_H
#define EJ4ESIME_PARAMETROS_H

#include <vector>

//CONST -> SOLO LEER DATOS


// Clase Parametros
class Parametros {
private:
    std::vector<double> valores;

public:
    // Agrega un valor al arreglo
    void agregar(double valor);
    // Obtiene un balor por indice
    double obtener(int indice) const;
    // Retorna la cantida d de valores
    int cantidad() const;
};


#endif //EJ4ESIME_ENTRADADATOS_H