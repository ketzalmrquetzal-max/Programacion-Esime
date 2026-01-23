#include "AnalizadorTamanios.h"
#include "Persona.h"
#include <iostream>
#include <string>

void AnalizadorTamanios::analizarTiposBasicos() const {
    std::cout << "=== TIPOS BÁSICOS ===" << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "bool: " << sizeof(bool) << " bytes" << std::endl;
    std::cout << "float: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "long: " << sizeof(long) << " bytes" << std::endl << std::endl;
}

void AnalizadorTamanios::analizarString() const {
    std::cout << "=== STRINGS ===" << std::endl;
    std::string vacio = "";
    std::string corto = "Hola";
    std::string largo = "Este es un string mucho más largo";
    
    std::cout << "string vacío: " << sizeof(vacio) << " bytes" << std::endl;
    std::cout << "string corto: " << sizeof(corto) << " bytes" << std::endl;
    std::cout << "string largo: " << sizeof(largo) << " bytes" << std::endl;
    std::cout << "Nota: sizeof(string) mide el objeto, no el contenido" << std::endl << std::endl;
}

void AnalizadorTamanios::analizarObjeto() const {
    std::cout << "=== OBJETO CUSTOM ===" << std::endl;
    Persona p("Hugo", "Dominguez", 19);
    std::cout << "Persona: " << sizeof(p) << " bytes" << std::endl;
    std::cout << "Composición: 2 strings + 1 int" << std::endl;
}
