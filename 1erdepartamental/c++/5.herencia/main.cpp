#include <iostream>
#include "operations/CalculadoraCientifica.h"
#include "operations/CalculadoraFinanciera.h"

int main() {
    // Crea calculadora cientifica y prueba operaciones
    CalculadoraCientifica cientifica;
    std::cout << "Raíz de 16: " << cientifica.raizCuadrada(16) << std::endl;
    std::cout << "2^10: " << cientifica.potencia(2, 10) << std::endl;
    std::cout << "Operación especial (raíz de 25): " << cientifica.operacionEspecial(25) << std::endl << std::endl;
    
    // crea calculadora financiera  y prueba operaciones
    CalculadoraFinanciera financiera;
    std::cout << "Interés simple ($1000, 5%, 3 años): $" << financiera.interesSimple(1000, 0.05, 3) << std::endl;
    std::cout << "Descuento 20% sobre $500: $" << financiera.descuento(500, 20) << std::endl;
    std::cout << "Operación especial (15% sobre $100): $" << financiera.operacionEspecial(100) << std::endl;
    
    return 0;
}
