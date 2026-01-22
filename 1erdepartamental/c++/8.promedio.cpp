#include <iostream>
using namespace std;

class Estadisticas {
private:
    double n1, n2, n3, n4, n5;
public:
    Estadisticas(double a, double b, double c, double d, double e)
        : n1(a), n2(b), n3(c), n4(d), n5(e) {}
    
    double suma() {
        return n1 + n2 + n3 + n4 + n5;
    }
    
    double promedio() {
        return suma() / 5;
    }
    
    double maximo() {
        double m = n1;
        if (n2 > m) m = n2;
        if (n3 > m) m = n3;
        if (n4 > m) m = n4;
        if (n5 > m) m = n5;
        return m;
    }
    
    double minimo() {
        double m = n1;
        if (n2 < m) m = n2;
        if (n3 < m) m = n3;
        if (n4 < m) m = n4;
        if (n5 < m) m = n5;
        return m;
    }
};

int main() {
    Estadisticas e(10, 25, 5, 30, 15);
    cout << "Suma: " << e.suma() << endl;
    cout << "Promedio: " << e.promedio() << endl;
    cout << "Maximo: " << e.maximo() << endl;
    cout << "Minimo: " << e.minimo() << endl;
    return 0;
}
