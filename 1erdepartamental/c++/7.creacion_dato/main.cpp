#include <iostream>
#include "core/Persona.h"
#include "core/Auto.h"

int main() {
    Persona p("Hugo", "Dominguez", "Lopez", 'M', 19);
    std::cout << p << std::endl << std::endl;
    
    Auto a("Honda", "Civic", 350000, 2022);
    std::cout << a << std::endl;
    
    return 0;
}
