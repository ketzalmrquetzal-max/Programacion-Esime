#include "FractalesRecursivos.h"
#include <iostream>
#include <string>

void FractalesRecursivos::dibujarTriangulo(int tamano) {
    for (int i = 0; i < tamano; i++) {
        std::cout << std::string(tamano - i - 1, ' ');
        std::cout << std::string(2 * i + 1, '*');
        std::cout << std::endl;
    }
}

void FractalesRecursivos::dibujarLinea(int longitud) {
    std::cout << std::string(longitud, '#');
}

void FractalesRecursivos::sierpinski(int nivel, int tamano) {
    if (nivel == 0) {
        dibujarTriangulo(tamano);
        return;
    }
    std::cout << "Sierpinski nivel " << nivel << ":" << std:: endl;
    sierpinski(nivel - 1, tamano / 2);
    std::cout << std::endl;
}

void FractalesRecursivos::cantor(int nivel, int longitud) {
    if (nivel == 0) {
        dibujarLinea(longitud);
        std::cout << std::endl;
        return;
    }
    cantor(nivel - 1, longitud / 3);
    std::cout << std::string(longitud / 3, ' ');
    cantor(nivel - 1, longitud / 3);
}
