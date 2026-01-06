#include <iostream>
using namespace std;

class Calculadora {
private:
    double resultado;
public:
    Calculadora() : resultado(0) {}
    
    double sumar(double a, double b) {
        resultado = a + b;
        return resultado;
    }
    
    double restar(double a, double b) {
        resultado = a - b;
        return resultado;
    }
    
    double multiplicar(double a, double b) {
        resultado = a * b;
        return resultado;
    }
    
    double dividir(double a, double b) {
        if (b != 0) {
            resultado = a / b;
            return resultado;
        }
        return 0;
    }
};

int main() {
    Calculadora c;
    cout << "10 + 5 = " << c.sumar(10, 5) << endl;
    cout << "10 - 5 = " << c.restar(10, 5) << endl;
    cout << "10 * 5 = " << c.multiplicar(10, 5) << endl;
    cout << "10 / 5 = " << c.dividir(10, 5) << endl;
    return 0;
}
