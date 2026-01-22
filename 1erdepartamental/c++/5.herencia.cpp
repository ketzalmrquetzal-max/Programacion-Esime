#include <iostream>
#include <cmath>
using namespace std;

class CalculadoraBase {
protected:
    double resultado;
public:
    CalculadoraBase() : resultado(0) {}
    virtual double operar(double a, double b) = 0;
    
    double sumar(double a, double b) { resultado = a + b; return resultado; }
    double restar(double a, double b) { resultado = a - b; return resultado; }
    double multiplicar(double a, double b) { resultado = a * b; return resultado; }
    double dividir(double a, double b) {
        if (b != 0) { resultado = a / b; return resultado; }
        return 0;
    }
};

class CalculadoraCientifica : public CalculadoraBase {
private:
    double memoria;
public:
    CalculadoraCientifica() : memoria(0) {}
    
    double operar(double a, double b) override { return sumar(a, b); }
    
    double potencia(double base, double exp) {
        resultado = pow(base, exp);
        return resultado;
    }
    
    double raizCuadrada(double n) {
        resultado = sqrt(n);
        return resultado;
    }
    
    double logaritmo(double n) {
        resultado = log(n);
        return resultado;
    }
    
    double seno(double angulo) {
        resultado = sin(angulo);
        return resultado;
    }
    
    double coseno(double angulo) {
        resultado = cos(angulo);
        return resultado;
    }
};

class CalculadoraFinanciera : public CalculadoraBase {
public:
    double operar(double a, double b) override { return multiplicar(a, b); }
    
    double interesSimple(double capital, double tasa, double tiempo) {
        resultado = capital * (tasa / 100) * tiempo;
        return resultado;
    }
    
    double interesCompuesto(double capital, double tasa, double tiempo) {
        resultado = capital * pow(1 + tasa / 100, tiempo);
        return resultado;
    }
};

int main() {
    CalculadoraCientifica cc;
    cout << "Suma: " << cc.sumar(10, 5) << endl;
    cout << "Potencia 2^8: " << cc.potencia(2, 8) << endl;
    cout << "Raiz de 144: " << cc.raizCuadrada(144) << endl;
    cout << "Logaritmo de 100: " << cc.logaritmo(100) << endl;
    
    CalculadoraFinanciera cf;
    cout << "Interes simple: " << cf.interesSimple(10000, 5, 2) << endl;
    return 0;
}
