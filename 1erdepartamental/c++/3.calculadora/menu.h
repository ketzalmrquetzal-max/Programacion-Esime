#include <iostream>
#include "resultadoFinal.h"
using namespace std;

class menu : public resultado_final {
public:
    menu() {
        pedir_datos();
        int opcion;
        cout << "Selecciona una operacion:" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicacion" << endl;
        cout << "4. Division" << endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
                sumar();
                break;
            case 2:
                restar();
                break;
            case 3:
                multiplicar();
                break;
            case 4:
                dividir();
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
        mostrar(resultado);
    }
};