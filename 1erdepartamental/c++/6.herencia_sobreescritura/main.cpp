#include <iostream>
#include "operations/CalculadoraDirecta.h"
#include "operations/CalculadoraSucesiva.h"

int main() {
    std::cout << "=== CALCULADORA DIRECTA ===" << std::endl;
    CalculadoraDirecta cd;
    std::cout << "5 * 3 = " << cd.multiplicar(5, 3) << std::endl;
    std::cout << "2^8 = " << cd.potencia(2, 8) << std::endl;
    std::cout << "20 / 4 = " << cd.dividir(20, 4) << std::endl << std::endl;
    
    std::cout << "=== CALCULADORA SUCESIVA ===" << std::endl;
    CalculadoraSucesiva cs;
    std::cout << "5 * 3 = " << cs.multiplicar(5, 3) << std::endl;
    std::cout << "2^8 = " << cs.potencia(2, 8) << std::endl;
    std::cout << "20 / 4 = " << cs.dividir(20, 4) << std::endl;
    
    return 0;
}
