#include <iostream>
#include "core/Saludo.h"

int main() {
    Saludo s;
    s.mostrar();
    
    std::cout << s.saludarPersona("Hugo") << std::endl;
    
    std::cout << s << std::endl;
    
    return 0;
}
