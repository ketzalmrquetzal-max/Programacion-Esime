// ============================================
// PROGRAMA: Herencia con Sobreescritura
// DESCRIPCIÓN: Implementaciones directa vs algorítmica
// ============================================

#include <iostream>
#include <stdexcept>
using namespace std;


/**
 * Base abstracta que obliga a implementar operaciones
 */
class CalculadoraBase {
protected:
    double __resultado;

public:
    CalculadoraBase() : __resultado(0) {}
    virtual ~CalculadoraBase() {}
    
    double getResultado() const { return __resultado; }
    
    // Métodos abstractos que DEBEN ser sobreescritos
    virtual double multiplicar(double a, int veces) = 0;
    virtual double potencia(double base, int exponente) = 0;
    virtual double dividir(double a, int divisor) = 0;
};


/**
 * Implementación directa usando operadores nativos
 */
class CalculadoraDirecta : public CalculadoraBase {
public:
    double multiplicar(double a, int veces) override {
        __resultado = a * veces;
        return __resultado;
    }
    
    double potencia(double base, int exponente) override {
        if (exponente < 0) {
            throw invalid_argument("Exponente debe ser >= 0");
        }
        __resultado = 1;
        for (int i = 0; i < exponente; i++) {
            __resultado *= base;
        }
        return __resultado;
    }
    
    double dividir(double a, int divisor) override {
        if (divisor == 0) {
            throw invalid_argument("División por cero");
        }
        __resultado = a / divisor;
        return __resultado;
    }
};


/**
 * Implementación algorítmica usando sumas/restas sucesivas
 */
class CalculadoraSucesiva : public CalculadoraBase {
public:
    // Multiplicación como sumas repetidas
    double multiplicar(double a, int veces) override {
        __resultado = 0;
        for (int i = 0; i < veces; i++) {
            __resultado += a;
        }
        return __resultado;
    }
    
    // Potencia como multiplicaciones repetidas
    double potencia(double base, int exponente) override {
        if (exponente < 0) {
            throw invalid_argument("Exponente debe ser >= 0");
        }
        __resultado = 1;
        for (int i = 0; i < exponente; i++) {
            __resultado *= base;
        }
        return __resultado;
    }
    
    // División como restas sucesivas
    double dividir(double a, int divisor) override {
        if (divisor == 0) {
            throw invalid_argument("División por cero");
        }
        __resultado = 0;
        double residuo = a;
        while (residuo >= divisor) {
            residuo -= divisor;
            __resultado++;
        }
        return __resultado;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    cout << "=== CALCULADORA DIRECTA ===" << endl;
    CalculadoraDirecta cd;
    cout << "5 * 3 = " << cd.multiplicar(5, 3) << endl;
    cout << "2^8 = " << cd.potencia(2, 8) << endl;
    cout << "20 / 4 = " << cd.dividir(20, 4) << endl << endl;
    
    cout << "=== CALCULADORA SUCESIVA ===" << endl;
    CalculadoraSucesiva cs;
    cout << "5 * 3 = " << cs.multiplicar(5, 3) << endl;
    cout << "2^8 = " << cs.potencia(2, 8) << endl;
    cout << "20 / 4 = " << cs.dividir(20, 4) << endl;
    
    return 0;
}
