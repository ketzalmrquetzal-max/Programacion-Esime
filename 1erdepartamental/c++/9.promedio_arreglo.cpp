#include <iostream>
using namespace std;

class EstadisticasArreglo {
private:
    double* datos;
    int tam;
public:
    EstadisticasArreglo(double arr[], int t) : tam(t) {
        datos = new double[t];
        for (int i = 0; i < t; i++) datos[i] = arr[i];
    }
    
    ~EstadisticasArreglo() { delete[] datos; }
    
    double suma() {
        double total = 0;
        for (int i = 0; i < tam; i++) total += datos[i];
        return total;
    }
    
    double promedio() { return suma() / tam; }
    
    double maximo() {
        double m = datos[0];
        for (int i = 1; i < tam; i++) if (datos[i] > m) m = datos[i];
        return m;
    }
    
    double minimo() {
        double m = datos[0];
        for (int i = 1; i < tam; i++) if (datos[i] < m) m = datos[i];
        return m;
    }
    
    void mostrar() {
        cout << "Datos: ";
        for (int i = 0; i < tam; i++) cout << datos[i] << " ";
        cout << endl;
    }
};

int main() {
    double arr[] = {10, 25, 5, 30, 15};
    EstadisticasArreglo e(arr, 5);
    e.mostrar();
    cout << "Suma: " << e.suma() << endl;
    cout << "Promedio: " << e.promedio() << endl;
    cout << "Maximo: " << e.maximo() << endl;
    cout << "Minimo: " << e.minimo() << endl;
    return 0;
}
