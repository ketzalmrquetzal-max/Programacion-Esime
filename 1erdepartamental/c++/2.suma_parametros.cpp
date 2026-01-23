// ============================================
// PROGRAMA: Suma con Parámetros y POO
// DESCRIPCIÓN: Operaciones con encapsulación completa
// ============================================

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;


/**
 * Interfaz abstracta para operadores matemáticos
 * 
 * ABSTRACCIÓN: Define contrato sin implementación
 */
class IOperadorMatematico {
public:
    virtual double operar() = 0;  // Virtual puro
    virtual void reiniciar() = 0;
    virtual ~IOperadorMatematico() {}  // Destructor virtual
};


/**
 * Sumador con validación y encapsulación completa
 * 
 * ENCAPSULACIÓN: Atributos privados
 * VALIDACIÓN: Getters/Setters con validación
 */
class Sumador : public IOperadorMatematico {
private:
    double __a;  // Privado (convención __)
    double __b;
    vector<double> __historial;
    
    static constexpr double MIN_VALOR = -1000000.0;
    static constexpr double MAX_VALOR = 1000000.0;
    
    void validar(double valor) const {
        if (valor < MIN_VALOR || valor > MAX_VALOR) {
            throw out_of_range("Valor fuera de rango");
        }
    }

public:
    // Constructor con valores por defecto
    Sumador(double a = 0, double b = 0) : __a(0), __b(0) {
        setA(a);  // Usa setter para validación
        setB(b);
    }
    
    // Getters
    double getA() const { return __a; }
    double getB() const { return __b; }
    
    // Getters que retornan copia del historial
    vector<double> getHistorial() const { return __historial; }
    
    // Setters con validación
    void setA(double valor) {
        validar(valor);
        __a = valor;
    }
    
    void setB(double valor) {
        validar(valor);
        __b = valor;
    }
    
    // Implementa interfaz
    double operar() override {
        return sumar();
    }
    
    double sumar() {
        double resultado = __a + __b;
        __historial.push_back(resultado);
        return resultado;
    }
    
    void establecer(double a, double b) {
        setA(a);  // Usa setters para validación
        setB(b);
    }
    
    void reiniciar() override {
        __a = 0;
        __b = 0;
        __historial.clear();
    }
    
    // Operador de suma sobrecargado
    double operator+(const Sumador& otro) const {
        return (__a + __b) + (otro.__a + otro.__b);
    }
    
    // Operador << para imprimir
    friend ostream& operator<<(ostream& os, const Sumador& s) {
        os << s.__a << " + " << s.__b << " = " << (s.__a + s.__b);
        return os;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    cout << "=== Sumador con POO ===" << endl << endl;
    
    // Básico
    Sumador s(10, 25);
    cout << s << endl;
    cout << "Resultado: " << s.sumar() << endl << endl;
    
    // Modificación
    s.establecer(100, 200);
    cout << s << endl << endl;
    
    // Getters
    cout << "a = " << s.getA() << ", b = " << s.getB() << endl << endl;
    
    // Validación
    try {
        s.setA(2000000);  // Fuera de rango
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl << endl;
    }
    
    // Historial
    s.establecer(5, 3);
    s.sumar();
    s.establecer(10, 20);
    s.sumar();
    cout << "Historial tiene " << s.getHistorial().size() << " resultados" << endl << endl;
    
    // Operadores
    Sumador s1(5, 10);
    Sumador s2(3, 7);
    cout << "s1 + s2 = " << (s1 + s2) << endl;
    
    return 0;
}
