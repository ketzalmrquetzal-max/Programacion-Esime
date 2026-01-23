#include <iostream>
#include "core/Saludo.h"

int main() {
    // Crea una instancia de Saludo
    Saludo s;
    // Muestra el mensaje predeterminado
    s.mostrar();
    
    // Saluda a una persona específica
    std::cout << s.saludarPersona("Hugo") << std::endl;
    
    // Usa el operador << sobrecargado
    std::cout << s << std::endl;
    
    return 0;
}
