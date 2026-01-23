// ============================================
// PROGRAMA: Fractales Recursivos
// DESCRIPCIÓN: Triángulo de Sierpinski y Conjunto de Cantor
// ============================================

#include <iostream>
#include <string>
using namespace std;


/**
 * Generador de fractales con recursión
 */
class FractalesRecursivos {
public:
    // Base: nivel == 0 -> imprime triángulo simple
    // Recursivo: dibuja 3 sub-triángulos más pequeños
    void sierpinski(int nivel, int tamano = 16) {
        if (nivel == 0) {
            dibujarTriangulo(tamano);
            return;
        }
        
        cout << "Sierpinski nivel " << nivel << ":" << endl;
        sierpinski(nivel - 1, tamano / 2);
        cout << endl;
    }
    
    // Base: nivel == 0 -> línea completa
    // Recursivo: divide en tercios, borra el del medio
    void cantor(int nivel, int longitud = 81) {
        if (nivel == 0) {
            dibujarLinea(longitud);
            cout << endl;
            return;
        }
        
        cantor(nivel - 1, longitud / 3);
        cout << string(longitud / 3, ' ');
        cantor(nivel - 1, longitud / 3);
    }
    
    void mostrarCantor(int niveles) {
        cout << "Conjunto de Cantor (nivel " << niveles << "):" << endl;
        cantorIterativo(0, niveles, 81);
    }

private:
    void dibujarTriangulo(int tamano) {
        for (int i = 0; i < tamano; i++) {
            cout << string(tamano - i - 1, ' ');
            cout << string(2 * i + 1, '*');
            cout << endl;
        }
    }
    
    void dibujarLinea(int longitud) {
        cout << string(longitud, '#');
    }
    
    // Versión iterativa para mejor visualización
    void cantorIterativo(int nivelActual, int nivelMax, int longitud) {
        if (nivelActual > nivelMax) return;
        
        if (nivelActual == 0) {
            dibujarLinea(longitud);
            cout << endl;
        } else {
            int seg = longitud / (1 << nivelActual);  // 2^nivelActual
            for (int i = 0; i < (1 << nivelActual); i++) {
                if (esSegmentoActivo(i, nivelActual)) {
                    cout << string(seg, '#');
                } else {
                    cout << string(seg, ' ');
                }
            }
            cout << endl;
        }
        
        cantorIterativo(nivelActual + 1, nivelMax, longitud);
    }
    
    bool esSegmentoActivo(int seg, int nivel) {
        // Un segmento está activo si no está en el tercio medio
        for (int i = 0; i < nivel; i++) {
            if ((seg % 3) == 1) return false;
            seg /= 3;
        }
        return true;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    FractalesRecursivos fractales;
    
    fractales.sierpinski(1, 8);
    cout << endl;
    
    fractales.mostrarCantor(3);
    
    return 0;
}
