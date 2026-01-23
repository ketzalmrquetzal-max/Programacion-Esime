#ifndef MENU_H
#define MENU_H

#include "../core/Calculadora.h"

// Clase Menu
class Menu {
private:
    Calculadora __calc;

public:
    // Muestra las opciones del menú
    void mostrar();
    // Ejecuta el bucle principal del menú
    void ejecutar();
};

#endif // MENU_H
