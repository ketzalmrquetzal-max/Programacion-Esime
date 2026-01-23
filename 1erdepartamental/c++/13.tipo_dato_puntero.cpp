// ============================================
// PROGRAMA: Punteros con Tipos Personalizados
// DESCRIPCIÓN: Combina punteros con objetos custom
// ============================================

#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;


/**
 * Tipo: Estudiante
 */
class Estudiante {
private:
    string __nombre;
    double __promedio;

public:
    Estudiante(string nombre, double promedio)
        : __nombre(nombre), __promedio(promedio) {}
    
    string getNombre() const { return __nombre; }
    double getPromedio() const { return __promedio; }
    
    friend ostream& operator<<(ostream& os, const Estudiante& e) {
        os << e.__nombre << " (Promedio: " << e.__promedio << ")";
        return os;
    }
    
    bool operator>(const Estudiante& otro) const {
        return __promedio > otro.__promedio;
    }
};


/**
 * Simulador de puntero para tipos custom
 */
template<typename T>
class PunteroTipado {
private:
    vector<T>* __datos;
    size_t __indice;

public:
    PunteroTipado(vector<T>* datos) : __datos(datos), __indice(0) {}
    
    T& getAt() {
        if (__indice >= __datos->size()) {
            throw out_of_range("Índice fuera de rango");
        }
        return (*__datos)[__indice];
    }
    
    void avanzar() { __indice++; }
    void reset() { __indice = 0; }
    bool enRango() const { return __indice < __datos->size(); }
};


/**
 * Estadísticas sobre colección de estudiantes
 */
class EstadisticasEstudiantes {
private:
    vector<Estudiante> __estudiantes;

public:
    void agregar(const Estudiante& e) {
        __estudiantes.push_back(e);
    }
    
    double promedioGeneral() {
        PunteroTipado<Estudiante> p(&__estudiantes);
        double suma = 0;
        
        while (p.enRango()) {
            suma += p.getAt().getPromedio();
            p.avanzar();
        }
        return suma / __estudiantes.size();
    }
    
    Estudiante mejorEstudiante() {
        PunteroTipado<Estudiante> p(&__estudiantes);
        Estudiante mejor = p.getAt();
        
        while (p.enRango()) {
            if (p.getAt() > mejor) {
                mejor = p.getAt();
            }
            p.avanzar();
        }
        return mejor;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    EstadisticasEstudiantes stats;
    
    stats.agregar(Estudiante("Ana", 9.5));
    stats.agregar(Estudiante("Luis", 8.7));
    stats.agregar(Estudiante("Carlos", 9.8));
    
    cout << "Promedio general: " << stats.promedioGeneral() << endl;
    cout << "Mejor estudiante: " << stats.mejorEstudiante() << endl;
    
    return 0;
}
