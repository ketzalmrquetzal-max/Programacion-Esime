// ============================================
// PROGRAMA: Calculadora con POO
// DESCRIPCIÓN: Calculadora con principios SOLID y excepciones
// ============================================

#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>
using namespace std;


/**
 * Enumeración de operaciones
 */
enum class TipoOperacion {
    SUMA,
    RESTA,
    MULTIPLICACION,
    DIVISION
};


/**
 * Excepción personalizada para división por cero
 */
class ErrorDivisionPorCero : public runtime_error {
public:
    ErrorDivisionPorCero() : runtime_error("No se puede dividir por cero") {}
};


/**
 * Interfaz abstracta para calculadoras
 */
class ICalculadora {
public:
    virtual double calcular(TipoOperacion op, double a, double b) = 0;
    virtual double getResultado() const = 0;
    virtual ~ICalculadora() {}
};


/**
 * Calculadora con operaciones básicas
 * 
 * ENCAPSULACIÓN: Atributos privados con __
 * VALIDACIÓN: En todas las operaciones
 * SOLID: Responsabilidad única, abierta/cerrada
 */
class Calculadora : public ICalculadora {
private:
    double __resultado;
    vector<pair<TipoOperacion, double>> __historial;
    
    static constexpr double MAX_VALOR = 1e308;
    static constexpr double MIN_VALOR = -1e308;
    
    void validar(double valor) const {
        if (valor < MIN_VALOR || valor > MAX_VALOR) {
            throw out_of_range("Valor fuera de rango");
        }
    }
    
    void registrar(TipoOperacion op, double res) {
        __historial.push_back({op, res});
    }

public:
    Calculadora() : __resultado(0) {}
    
    // Getter
    double getResultado() const override {
        return __resultado;
    }
    
    size_t getHistorialSize() const {
        return __historial.size();
    }
    
    double sumar(double a, double b) {
        validar(a);
        validar(b);
        __resultado = a + b;
        registrar(TipoOperacion::SUMA, __resultado);
        return __resultado;
    }
    
    double restar(double a, double b) {
        validar(a);
        validar(b);
        __resultado = a - b;
        registrar(TipoOperacion::RESTA, __resultado);
        return __resultado;
    }
    
    double multiplicar(double a, double b) {
        validar(a);
        validar(b);
        __resultado = a * b;
        registrar(TipoOperacion::MULTIPLICACION, __resultado);
        return __resultado;
    }
    
    double dividir(double a, double b) {
        validar(a);
        validar(b);
        
        if (b == 0) {
            throw ErrorDivisionPorCero();
        }
        
        __resultado = a / b;
        registrar(TipoOperacion::DIVISION, __resultado);
        return __resultado;
    }
    
    // Implementa interfaz - Patrón Strategy
    double calcular(TipoOperacion op, double a, double b) override {
        switch(op) {
            case TipoOperacion::SUMA:
                return sumar(a, b);
            case TipoOperacion::RESTA:
                return restar(a, b);
            case TipoOperacion::MULTIPLICACION:
                return multiplicar(a, b);
            case TipoOperacion::DIVISION:
                return dividir(a, b);
            default:
                throw invalid_argument("Operación no soportada");
        }
    }
    
    void limpiarHistorial() {
        __historial.clear();
    }
    
    void reiniciar() {
        __resultado = 0;
        limpiarHistorial();
    }
    
    // Operador << para imprimir
    friend ostream& operator<<(ostream& os, const Calculadora& c) {
        os << "Calculadora(resultado=" << c.__resultado << ")";
        return os;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    cout << "=== Calculadora con POO ===" << endl << endl;
    
    Calculadora c;
    
    // Operaciones básicas
    cout << "Operaciones básicas:" << endl;
    cout << "10 + 5 = " << c.sumar(10, 5) << endl;
    cout << "10 - 5 = " << c.restar(10, 5) << endl;
    cout << "10 * 5 = " << c.multiplicar(10, 5) << endl;
    cout << "10 / 5 = " << c.dividir(10, 5) << endl << endl;
    
    // Historial
    cout << "Historial: " << c.getHistorialSize() << " operaciones" << endl << endl;
    
    // Manejo de errores
    try {
        c.dividir(10, 0);
    } catch (const ErrorDivisionPorCero& e) {
        cout << "Error: " << e.what() << endl << endl;
    }
    
    // Método genérico
    cout << "Suma genérica: " << c.calcular(TipoOperacion::SUMA, 25, 15) << endl;
    cout << "Multiplicación genérica: " << c.calcular(TipoOperacion::MULTIPLICACION, 7, 8) << endl << endl;
    
    cout << c << endl;
    
    return 0;
}
