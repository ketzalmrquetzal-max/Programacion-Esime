#include "core/AnalizadorTamanios.h"

int main() {
    // Crea el analizador y ejecuta analisys
    AnalizadorTamanios analizador;
    analizador.analizarTiposBasicos();
    analizador.analizarString();
    analizador.analizarObjeto();
    return 0;
}
