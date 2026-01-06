#include <iostream>
using namespace std;

class CalculadoraRecursiva {
public:
    int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
    
    int fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    int sumar(int a, int b) {
        if (b == 0) return a;
        return (b > 0) ? sumar(a + 1, b - 1) : sumar(a - 1, b + 1);
    }
    
    int multiplicar(int a, int b) {
        if (b == 0) return 0;
        if (b > 0) return a + multiplicar(a, b - 1);
        return -multiplicar(a, -b);
    }
    
    int potencia(int base, int exp) {
        if (exp == 0) return 1;
        return base * potencia(base, exp - 1);
    }
};

int main() {
    CalculadoraRecursiva c;
    cout << "5! = " << c.factorial(5) << endl;
    cout << "F(10) = " << c.fibonacci(10) << endl;
    cout << "5 + 3 = " << c.sumar(5, 3) << endl;
    cout << "4 * 5 = " << c.multiplicar(4, 5) << endl;
    cout << "2^8 = " << c.potencia(2, 8) << endl;
    return 0;
}
