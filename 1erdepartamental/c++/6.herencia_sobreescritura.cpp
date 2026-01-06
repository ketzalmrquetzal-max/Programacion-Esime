#include <iostream>
#include <cmath>
using namespace std;

class CalculadoraBase {
protected:
    double resultado;
public:
    CalculadoraBase() : resultado(0) {}
    virtual double multiplicar(double a, double b) = 0;
    virtual double potencia(double base, int exp) = 0;
    virtual double dividir(double a, double b) = 0;
};

class CalculadoraDirecta : public CalculadoraBase {
public:
    double multiplicar(double a, double b) override {
        resultado = a * b;
        return resultado;
    }
    
    double potencia(double base, int exp) override {
        resultado = pow(base, exp);
        return resultado;
    }
    
    double dividir(double a, double b) override {
        if (b != 0) { resultado = a / b; return resultado; }
        return 0;
    }
};

class CalculadoraSucesiva : public CalculadoraBase {
public:
    double multiplicar(double a, double b) override {
        resultado = 0;
        int absB = abs((int)b);
        for (int i = 0; i < absB; i++) {
            resultado += abs(a);
        }
        if ((a < 0) != (b < 0)) resultado = -resultado;
        return resultado;
    }
    
    double potencia(double base, int exp) override {
        resultado = 1;
        for (int i = 0; i < abs(exp); i++) {
            double temp = 0;
            for (int j = 0; j < abs((int)base); j++) {
                temp += abs(resultado);
            }
            resultado = temp;
        }
        return resultado;
    }
    
    double dividir(double a, double b) override {
        if (b == 0) return 0;
        int cociente = 0;
        double residuo = abs(a);
        while (residuo >= abs(b)) {
            residuo -= abs(b);
            cociente++;
        }
        resultado = ((a >= 0) == (b >= 0)) ? cociente : -cociente;
        return resultado;
    }
};

int main() {
    CalculadoraDirecta cd;
    cout << "Directa: 4*5 = " << cd.multiplicar(4, 5) << endl;
    cout << "Directa: 2^4 = " << cd.potencia(2, 4) << endl;
    
    CalculadoraSucesiva cs;
    cout << "Sucesiva: 4*5 = " << cs.multiplicar(4, 5) << endl;
    cout << "Sucesiva: 17/5 = " << cs.dividir(17, 5) << endl;
    return 0;
}
