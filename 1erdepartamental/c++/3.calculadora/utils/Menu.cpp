#include "Menu.h"
#include <iostream>

// Muestra las opciones del menu
void Menu::mostrar() {
    std::cout << "\n=== CALCULADORA ===" << std::endl;
    std::cout << "1. Suma" << std::endl;
    std::cout << "2. Resta" << std::endl;
    std::cout << "3. Multiplicación" << std::endl;
    std::cout << "4. División" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Selecciona una opción: ";
}

// Ejecuta el bucle principal del menú
void Menu::ejecutar() {
    int opcion;
    double a, b, resultado;
    
    do {
        mostrar();
        std::cin >> opcion;
        
        if (opcion == 0) break;
        
        if (opcion >= 1 && opcion <= 4) {
            std::cout << "Ingresa el primer número: ";
            std::cin >> a;
            std::cout << "Ingresa el segundo número: ";
            std::cin >> b;
            
            try {
                switch(opcion) {
                    case 1:
                        resultado = __calc.sumar(a, b);
                        std::cout << "Resultado: " << resultado << std::endl;
                        break;
                    case 2:
                        resultado = __calc.restar(a, b);
                        std::cout << "Resultado: " << resultado << std::endl;
                        break;
                    case 3:
                        resultado = __calc.multiplicar(a, b);
                        std::cout << "Resultado: " << resultado << std::endl;
                        break;
                    case 4:
                        resultado = __calc.dividir(a, b);
                        std::cout << "Resultado: " << resultado << std::endl;
                        break;
                }
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
            }
        } else {
            std::cout << "Opción no válida" << std::endl;
        }
        
    } while (opcion != 0);
}
