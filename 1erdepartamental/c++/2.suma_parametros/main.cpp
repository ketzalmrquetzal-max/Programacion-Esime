#include <iostream>
#include "core/Sumador.h"

int main() {
    // Crea primer sumador
    Sumador s1(10, 20);
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "Suma: " << s1.sumar() << std::endl << std::endl;
    
    // Crea segundo sumador y suma con el primero
    Sumador s2(5, 15);
    // Usa el operador + sobrecargado
    Sumador s3 = s1 + s2;
    std::cout << "s1 + s2 = " << s3 << std::endl;
    
    return 0;
}
