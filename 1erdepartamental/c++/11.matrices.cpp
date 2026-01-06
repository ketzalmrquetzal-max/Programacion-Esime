#include <iostream>
using namespace std;

class Matriz {
private:
    double** datos;
    int filas, cols;
public:
    Matriz(int f, int c) : filas(f), cols(c) {
        datos = new double*[f];
        for (int i = 0; i < f; i++) {
            datos[i] = new double[c];
            for (int j = 0; j < c; j++) datos[i][j] = 0;
        }
    }
    
    ~Matriz() {
        for (int i = 0; i < filas; i++) delete[] datos[i];
        delete[] datos;
    }
    
    void llenar(double vals[], int n) {
        int idx = 0;
        for (int i = 0; i < filas && idx < n; i++)
            for (int j = 0; j < cols && idx < n; j++)
                datos[i][j] = vals[idx++];
    }
    
    Matriz* multiplicarEscalar(double k) {
        Matriz* r = new Matriz(filas, cols);
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < cols; j++)
                r->datos[i][j] = datos[i][j] * k;
        return r;
    }
    
    Matriz* multiplicar(Matriz& b) {
        Matriz* r = new Matriz(filas, b.cols);
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < b.cols; j++) {
                double s = 0;
                for (int k = 0; k < cols; k++)
                    s += datos[i][k] * b.datos[k][j];
                r->datos[i][j] = s;
            }
        return r;
    }
    
    void mostrar() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < cols; j++) cout << datos[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matriz A(2, 3);
    double va[] = {1, 2, 3, 4, 5, 6};
    A.llenar(va, 6);
    cout << "A:" << endl; A.mostrar();
    
    cout << "A * 2:" << endl;
    Matriz* A2 = A.multiplicarEscalar(2);
    A2->mostrar();
    
    Matriz B(3, 2);
    double vb[] = {7, 8, 9, 10, 11, 12};
    B.llenar(vb, 6);
    cout << "B:" << endl; B.mostrar();
    
    cout << "A * B:" << endl;
    Matriz* C = A.multiplicar(B);
    C->mostrar();
    
    delete A2; delete C;
    return 0;
}
