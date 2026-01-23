#include <iostream>
#include <ctime>

#include "core/Calculadora.h"
#include "operations/Suma.h"
#include "operations/Resta.h"
#include "operations/Multiplicacion.h"
#include "operations/Division.h"


int main() {
    std::srand(std::time(nullptr));

    // Crea la caalculadora
    Calculadora calc;

    // crea parametros y agrega valores
    Parametros p1;
    p1.agregar(10);
    p1.agregar(20);
    p1.agregar(30);

    // Ejecuta operacion suma
    Suma suma;
    std::cout << "Suma: " << calc.calcular(suma, p1) << std::endl;

    // Ejecuta operacion resta
    Resta resta;
    std::cout << "resta: " << calc.calcular(resta, p1) << std::endl;

    // Ejecuta Multipl icacion
    Multiplicacion multiplicacion;
    std::cout << "mult: " << calc.calcular(multiplicacion, p1) << std::endl;

    // ejecuta division
    Division division;
    std::cout << "div: " << calc.calcular(division, p1) << std::endl;




    return 0;
}
