// ============================================
// PROGRAMA: Herencia con Calculadoras Especializadas
// DESCRIPCIÓN: ABC y subclases concretas
// ============================================

#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;


/**
 * Clase base abstracta para calculadoras
 */
class CalculadoraBase {
protected:
    double __resultado;

public:
    CalculadoraBase() : __resultado(0) {}
    virtual ~CalculadoraBase() {}
    
    double getResultado() const { return __resultado; }
    
    // Operaciones básicas (implementación por defecto)
    virtual double sumar(double a, double b) {
        __resultado = a + b;
        return __resultado;
    }
    
    virtual double restar(double a, double b) {
        __resultado = a - b;
        return __resultado;
    }
    
    // Operaciones especializadas (abstractas)
    virtual double operacionEspecial(double valor) = 0;
};


/**
 * Calculadora científica con funciones matemáticas
 */
class CalculadoraCientifica : public CalculadoraBase {
public:
    double raizCuadrada(double n) {
        if (n < 0) {
            throw invalid_argument("No se puede calcular raíz de número negativo");
        }
        __resultado = sqrt(n);
        return __resultado;
    }
    
    double potencia(double base, double exponente) {
        __resultado = pow(base, exponente);
        return __resultado;
    }
    
    double seno(double angulo) {
        __resultado = sin(angulo);
        return __resultado;
    }
    
    // Implementación de operación especial
    double operacionEspecial(double valor) override {
        return raizCuadrada(valor);
    }
};


/**
 * Calculadora financiera con operaciones de negocio
 */
class CalculadoraFinanciera : public CalculadoraBase {
private:
    void validarTasa(double tasa) const {
        if (tasa < 0 || tasa > 1) {
            throw invalid_argument("Tasa debe estar entre 0 y 1");
        }
    }

public:
    double intereSimple(double capital, double tasa, int tiempo) {
        validarTasa(tasa);
        __resultado = capital * tasa * tiempo;
        return __resultado;
    }
    
    double interesCompuesto(double capital, double tasa, int tiempo) {
        validarTasa(tasa);
        __resultado = capital * (pow(1 + tasa, tiempo) - 1);
        return __resultado;
    }
    
    double descuento(double precio, double porcentaje) {
        if (porcentaje < 0 || porcentaje > 100) {
            throw invalid_argument("Porcentaje debe estar entre 0 y 100");
        }
        __resultado = precio * (porcentaje / 100);
        return __resultado;
    }
    
    // Implementación de operación especial
    double operacionEspecial(double valor) override {
        return descuento(valor, 15);  // 15% de descuento por defecto
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    CalculadoraCientifica cientifica;
    cout << "Raíz de 16: " << cientifica.raizCuadrada(16) << endl;
    cout << "2^10: " << cientifica.potencia(2, 10) << endl;
    cout << "Operación especial (raíz de 25): " << cientifica.operacionEspecial(25) << endl << endl;
    
    CalculadoraFinanciera financiera;
    cout << "Interés simple ($1000, 5%, 3 años): $" << financiera.intereSimple(1000, 0.05, 3) << endl;
    cout << "Descuento 20% sobre $500: $" << financiera.descuento(500, 20) << endl;
    cout << "Operación especial (15% sobre $100): $" << financiera.operacionEspecial(100) << endl;
    
    return 0;
}
