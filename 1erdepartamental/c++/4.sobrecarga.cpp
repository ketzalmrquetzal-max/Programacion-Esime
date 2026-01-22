#include <iostream>
using namespace std;

class CalculadoraSobrecarga {
private:
    double resultado;
public:
    CalculadoraSobrecarga() : resultado(0) {}
    
    double sumar() { return 0; }
    double sumar(double a, double b) { resultado = a + b; return resultado; }
    double sumar(double a, double b, double c) { resultado = a + b + c; return resultado; }
    
    double restar() { return 0; }
    double restar(double a, double b) { resultado = a - b; return resultado; }
    double restar(double a, double b, double c) { resultado = a - b - c; return resultado; }
    
    double multiplicar() { return 1; }
    double multiplicar(double a, double b) { resultado = a * b; return resultado; }
    double multiplicar(double a, double b, double c) { resultado = a * b * c; return resultado; }
    
    double dividir() { return 1; }
    double dividir(double a, double b) { 
        if (b != 0) { resultado = a / b; return resultado; }
        return 0;
    }
    double dividir(double a, double b, double c) {
        if (b != 0 && c != 0) { resultado = a / b / c; return resultado; }
        return 0;
    }
};

int main() {
    CalculadoraSobrecarga c;
    cout << "sumar() = " << c.sumar() << endl;
    cout << "sumar(5, 3) = " << c.sumar(5, 3) << endl;
    cout << "sumar(5, 3, 2) = " << c.sumar(5, 3, 2) << endl;
    cout << "multiplicar(4, 5) = " << c.multiplicar(4, 5) << endl;
    cout << "multiplicar(4, 5, 2) = " << c.multiplicar(4, 5, 2) << endl;
    return 0;
}
