#include <iostream>
#include "core/FractalesRecursivos.h"

int main() {
    FractalesRecursivos fractales;
    
    fractales.sierpinski(1, 8);
    std::cout << std::endl;
    
    std::cout << "Conjunto de Cantor (nivel 1):" << std::endl;
    fractales.cantor(1, 27);
    
    return 0;
}
