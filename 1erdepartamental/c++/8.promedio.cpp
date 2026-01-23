// ============================================
// PROGRAMA: Estadísticas con Parámetros Fijos
// DESCRIPCIÓN: Calcula suma, promedio, máximo, mínimo
// ============================================

#include <iostream>
#include <array>
using namespace std;


/**
 * Estadísticas sobre 5 números fijos
 * 
 * Implementaciones manuales sin usar algorithms
 */
class Estadisticas {
private:
    array<double, 5> __numeros;

public:
    Estadisticas(double n1, double n2, double n3, double n4, double n5) {
        __numeros = {n1, n2, n3, n4, n5};
    }
    
    // Getter que retorna copia
    array<double, 5> getNumeros() const {
        return __numeros;
    }
    
    double suma() const {
        double total = 0;
        for (double n : __numeros) {
            total += n;
        }
        return total;
    }
    
    double promedio() const {
        return suma() / __numeros.size();
    }
    
    double maximo() const {
        double m = __numeros[0];
        for (double n : __numeros) {
            if (n > m) m = n;
        }
        return m;
    }
    
    double minimo() const {
        double m = __numeros[0];
        for (double n : __numeros) {
            if (n < m) m = n;
        }
        return m;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    Estadisticas e(10, 25, 5, 30, 15);
    
    cout << "Suma: " << e.suma() << endl;
    cout << "Promedio: " << e.promedio() << endl;
    cout << "Máximo: " << e.maximo() << endl;
    cout << "Mínimo: " << e.minimo() << endl;
    
    return 0;
}
