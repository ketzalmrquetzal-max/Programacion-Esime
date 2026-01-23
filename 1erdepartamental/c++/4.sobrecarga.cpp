// ============================================
// PROGRAMA: Sobrecarga con POO
// DESCRIPCIÓN: Simula sobrecarga usando parámetros por defecto
// ============================================

#include <iostream>
#include <stdexcept>
using namespace std;


/**
 * Interfaz para operadores flexibles
 */
class IOperadorFlexible {
public:
    virtual double operar() = 0;
    virtual ~IOperadorFlexible() {}
};


/**
 * Simula sobrecarga con parámetros por defecto
 * 
 * C++ SÍ soporta sobrecarga nativa, pero se demuestra con defaults
 */
class CalculadoraSobrecarga : public IOperadorFlexible {
private:
    double __resultado;

public:
    CalculadoraSobrecarga() : __resultado(0) {}
    
    double getResultado() const { return __resultado; }
    
    // "Sobrecarga" con parámetros por defecto
    double sumar(double a = 0, double b = 0, double c = 0) {
        __resultado = a + b + c;
        return __resultado;
    }
    
    double restar(double a = 0, double b = 0, double c = 0) {
        __resultado = a - b - c;
        return __resultado;
    }
    
    double multiplicar(double a = 1, double b = 1, double c = 1) {
        __resultado = a * b * c;
        return __resultado;
    }
    
    double dividir(double a = 1, double b = 1, double c = 1) {
        if (b != 0 && c != 0) {
            __resultado = a / b / c;
            return __resultado;
        }
        throw runtime_error("División por cero");
    }
    
    double operar() override {
        return __resultado;
    }
    
    friend ostream& operator<<(ostream& os, const CalculadoraSobrecarga& c) {
        os << "CalculadoraSobrecarga(resultado=" << c.__resultado << ")";
        return os;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    CalculadoraSobrecarga c;
    
    // Demuestra "sobrecarga" con diferente cantidad de argumentos
    cout << "sumar() = " << c.sumar() << endl;
    cout << "sumar(5, 3) = " << c.sumar(5, 3) << endl;
    cout << "sumar(5, 3, 2) = " << c.sumar(5, 3, 2) << endl << endl;
    
    cout << "multiplicar(4, 5) = " << c.multiplicar(4, 5) << endl;
    cout << "multiplicar(4, 5, 2) = " << c.multiplicar(4, 5, 2) << endl << endl;
    
    cout << c << endl;
    
    return 0;
}
