// ============================================
// PROGRAMA: Estadísticas con Simulación de Punteros
// DESCRIPCIÓN: Simula aritmética de punteros con iteradores
// ============================================

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;


/**
 * Simula comportamiento de punteros en C++
 * 
 * En C++ real usaríamos punteros nativos, pero se encapsula
 * para demostrar control y validación
 */
class Puntero {
private:
    vector<double>* __datos;
    size_t __indice;
    
    void validarIndice() const {
        if (__indice >= __datos->size()) {
            throw out_of_range("Índice fuera de rango");
        }
    }

public:
    Puntero(vector<double>* datos) : __datos(datos), __indice(0) {}
    
    double getAt() const {
        validarIndice();
        return (*__datos)[__indice];
    }
    
    void avanzar() {
        __indice++;
    }
    
    void reset() {
        __indice = 0;
    }
    
    bool enRango() const {
        return __indice < __datos->size();
    }
    
    size_t getIndice() const {
        return __indice;
    }
};


/**
 * Estadísticas usando simulación de punteros
 */
class EstadisticasPuntero {
private:
    vector<double> __datos;

public:
    EstadisticasPuntero(const vector<double>& arreglo)
        : __datos(arreglo) {}
    
    double suma() const {
        Puntero p(const_cast<vector<double>*>(&__datos));
        double total = 0;
        
        while (p.enRango()) {
            total += p.getAt();
            p.avanzar();
        }
        return total;
    }
    
    double promedio() const {
        return suma() / __datos.size();
    }
    
    double maximo() const {
        Puntero p(const_cast<vector<double>*>(&__datos));
        double m = p.getAt();
        
        while (p.enRango()) {
            if (p.getAt() > m) m = p.getAt();
            p.avanzar();
        }
        return m;
    }
    
    double minimo() const {
        Puntero p(const_cast<vector<double>*>(&__datos));
        double m = p.getAt();
        
        while (p.enRango()) {
            if (p.getAt() < m) m = p.getAt();
            p.avanzar();
        }
        return m;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    EstadisticasPuntero e({10, 25, 5, 30, 15});
    
    cout << "Suma: " << e.suma() << endl;
    cout << "Promedio: " << e.promedio() << endl;
    cout << "Máximo: " << e.maximo() << endl;
    cout << "Mínimo: " << e.minimo() << endl;
    
    return 0;
}
