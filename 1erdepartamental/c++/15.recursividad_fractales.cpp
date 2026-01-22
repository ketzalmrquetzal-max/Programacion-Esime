#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Sierpinski {
private:
    int nivel;
public:
    Sierpinski(int n) : nivel(n) {}
    
    int contarTriangulos(int n) {
        if (n == 0) return 1;
        return 3 * contarTriangulos(n - 1);
    }
    
    int contarTriangulos() { return contarTriangulos(nivel); }
    
    int totalAcumulado(int n) {
        if (n == 0) return 1;
        return contarTriangulos(n) + totalAcumulado(n - 1);
    }
    
    int totalAcumulado() { return totalAcumulado(nivel); }
};

class Cantor {
private:
    int nivel;
public:
    Cantor(int n) : nivel(n) {}
    
    int contarSegmentos(int n) {
        if (n == 0) return 1;
        return 2 * contarSegmentos(n - 1);
    }
    
    int contarSegmentos() { return contarSegmentos(nivel); }
};

int main() {
    Sierpinski s(4);
    cout << "Triangulos nivel 4: " << s.contarTriangulos() << endl;
    cout << "Total acumulado: " << s.totalAcumulado() << endl;
    
    Cantor c(4);
    cout << "Segmentos Cantor nivel 4: " << c.contarSegmentos() << endl;
    return 0;
}
