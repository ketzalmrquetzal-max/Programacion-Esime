// ============================================
// PROGRAMA: Operaciones con Matrices
// DESCRIPCIÓN: Multiplicación escalar y matricial
// ============================================

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;


/**
 * Matriz con operaciones sobrecargadas
 * 
 * Demuestra operator* para escalar y matrices
 */
class Matriz {
private:
    vector<vector<double>> __datos;
    size_t __filas;
    size_t __columnas;
    
    void validarDimensiones(size_t filas, size_t columnas) const {
        if (filas == 0 || columnas == 0) {
            throw invalid_argument("Dimensiones deben ser > 0");
        }
    }

public:
    Matriz(size_t filas, size_t columnas) 
        : __filas(filas), __columnas(columnas) {
        validarDimensiones(filas, columnas);
        __datos.resize(filas, vector<double>(columnas, 0));
    }
    
    size_t getFilas() const { return __filas; }
    size_t getColumnas() const { return __columnas; }
    
    void set(size_t i, size_t j, double valor) {
        if (i >= __filas || j >= __columnas) {
            throw out_of_range("Índice fuera de rango");
        }
        __datos[i][j] = valor;
    }
    
    double get(size_t i, size_t j) const {
        if (i >= __filas || j >= __columnas) {
            throw out_of_range("Índice fuera de rango");
        }
        return __datos[i][j];
    }
    
    void llenar(double valor) {
        for (auto& fila : __datos) {
            for (auto& elem : fila) {
                elem = valor;
            }
        }
    }
    
    // Multiplicación escalar
    Matriz operator*(double escalar) const {
        Matriz resultado(__filas, __columnas);
        for (size_t i = 0; i < __filas; i++) {
            for (size_t j = 0; j < __columnas; j++) {
                resultado.set(i, j, __datos[i][j] * escalar);
            }
        }
        return resultado;
    }
    
    // Multiplicación matricial
    Matriz operator*(const Matriz& otra) const {
        if (__columnas != otra.__filas) {
            throw invalid_argument("Dimensiones incompatibles para multiplicación");
        }
        
        Matriz resultado(__filas, otra.__columnas);
        for (size_t i = 0; i < __filas; i++) {
            for (size_t j = 0; j < otra.__columnas; j++) {
                double suma = 0;
                for (size_t k = 0; k < __columnas; k++) {
                    suma += __datos[i][k] * otra.__datos[k][j];
                }
                resultado.set(i, j, suma);
            }
        }
        return resultado;
    }
    
    friend ostream& operator<<(ostream& os, const Matriz& m) {
        for (size_t i = 0; i < m.__filas; i++) {
            os << "[ ";
            for (size_t j = 0; j < m.__columnas; j++) {
                os << setw(6) << fixed << setprecision(2) << m.__datos[i][j];
                if (j < m.__columnas - 1) os << ", ";
            }
            os << " ]" << endl;
        }
        return os;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    Matriz m1(2, 2);
    m1.set(0, 0, 1); m1.set(0, 1, 2);
    m1.set(1, 0, 3); m1.set(1, 1, 4);
    
    cout << "Matriz original:" << endl << m1 << endl;
    
    Matriz m2 = m1 * 2;
    cout << "Multiplicación escalar (x2):" << endl << m2 << endl;
    
    Matriz m3 = m1 * m1;
    cout << "Multiplicación matricial:" << endl << m3 << endl;
    
    return 0;
}
