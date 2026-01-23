#ifndef MENU_H
#define MENU_H

#include "../core/Calculadora.h"

/**
 * Clase para mostrar menú interactivo
 */
class Menu {
private:
    Calculadora __calc;

public:
    void mostrar();
    void ejecutar();
};

#endif // MENU_H
