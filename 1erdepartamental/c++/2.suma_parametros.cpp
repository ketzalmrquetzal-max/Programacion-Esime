#include <iostream>
using namespace std;

class Sumador {
private:
    double a, b;
public:
    Sumador(double x = 0, double y = 0) : a(x), b(y) {}
    
    double sumar() {
        return a + b;
    }
    
    void establecer(double x, double y) {
        a = x;
        b = y;
    }
};

int main() {
    Sumador s(10, 25);
    cout << "10 + 25 = " << s.sumar() << endl;
    s.establecer(100, 200);
    cout << "100 + 200 = " << s.sumar() << endl;
    return 0;
}
