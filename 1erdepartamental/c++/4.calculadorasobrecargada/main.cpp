#include <iostream>
#include <ctime>

#include "core/Calculadora.h"
#include "operations/Suma.h"
#include "operations/Resta.h"
#include "operations/Multiplicacion.h"
#include "operations/Division.h"


int main() {
    std::srand(std::time(nullptr));

    Calculadora calc;

    Parametros p1;
    p1.agregar(10);
    p1.agregar(20);
    p1.agregar(30);

    Suma suma;
    std::cout << "Suma: " << calc.calcular(suma, p1) << std::endl;

    Resta resta;
    std::cout << "resta: " << calc.calcular(resta, p1) << std::endl;

    Multiplicacion multiplicacion;
    std::cout << "mult: " << calc.calcular(multiplicacion, p1) << std::endl;

    Division division;
    std::cout << "div: " << calc.calcular(division, p1) << std::endl;




    return 0;
}
