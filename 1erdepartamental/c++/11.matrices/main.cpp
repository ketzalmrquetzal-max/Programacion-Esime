#include <iostream>
#include "core/Matriz.h"

int main() {
    // Crea matriz 2x2
    Matriz m1(2, 2);
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);
    
    std::cout << "Matriz original:" << std::endl << m1 << std::endl;
    
    // Multiplica por escalar
    Matriz m2 = m1 * 2;
    std::cout << "Multiplicación escalar (x2):" << std::endl << m2 << std::endl;
    
    // Multiplicacion matricial
    Matriz m3 = m1 * m1;
    std::cout << "Multiplicación matricial:" << std::endl << m3 << std::endl;
    
    return 0;
}
