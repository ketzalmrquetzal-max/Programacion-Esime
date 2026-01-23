// ============================================
// PROGRAMA: Estadísticas con Vector Dinámico
// DESCRIPCIÓN: Acepta cualquier cantidad de números
// ============================================

#include <iostream>
#include <vector>
using namespace std;


/**
 * Estadísticas sobre vector de tamaño variable
 * 
 * Más flexible que array fijo
 */
class EstadisticasArreglo {
private:
    vector<double> __datos;

public:
    EstadisticasArreglo(const vector<double>& arreglo)
        : __datos(arreglo) {}
    
    // Getter que retorna copia
    vector<double> getDatos() const {
        return __datos;
    }
    
    double suma() const {
        double total = 0;
        for (double n : __datos) {
            total += n;
        }
        return total;
    }
    
    double promedio() const {
        return suma() / __datos.size();
    }
    
    double maximo() const {
        double m = __datos[0];
        for (double n : __datos) {
            if (n > m) m = n;
        }
        return m;
    }
    
    double minimo() const {
        double m = __datos[0];
        for (double n : __datos) {
            if (n < m) m = n;
        }
        return m;
    }
    
    void agregar(double valor) {
        __datos.push_back(valor);
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    EstadisticasArreglo e({10, 25, 5, 30, 15});
    
    cout << "Datos iniciales: " << e.getDatos().size() << " elementos" << endl;
    cout << "Suma: " << e.suma() << endl;
    cout << "Promedio: " << e.promedio() << endl;
    cout << "Máximo: " << e.maximo() << endl;
    cout << "Mínimo: " << e.minimo() << endl << endl;
    
    e.agregar(50);
    cout << "Después de agregar 50:" << endl;
    cout << "Promedio: " << e.promedio() << endl;
    
    return 0;
}
