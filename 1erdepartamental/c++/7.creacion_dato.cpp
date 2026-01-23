// ============================================
// PROGRAMA: Creación de Tipos de Datos
// DESCRIPCIÓN: Modela entidades con POO
// ============================================

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


/**
 * Representa una persona con encapsulación completa
 */
class Persona {
private:
    string __nombre;
    string __ap;
    string __am;
    char __genero;
    int __edad;
    
    void validarEdad(int edad) const {
        if (edad < 0) {
            throw invalid_argument("La edad no puede ser negativa");
        }
    }

public:
    Persona(string nombre, string ap, string am, char genero, int edad)
        : __nombre(nombre), __ap(ap), __am(am), __genero(genero), __edad(0) {
        setEdad(edad);  // Usa setter para validación
    }
    
    // Getters
    string getNombre() const { return __nombre; }
    int getEdad() const { return __edad; }
    
    // Setter con validación
    void setEdad(int edad) {
        validarEdad(edad);
        __edad = edad;
    }
    
    string nombreCompleto() const {
        return __nombre + " " + __ap + " " + __am;
    }
    
    // Operador << para imprimir
    friend ostream& operator<<(ostream& os, const Persona& p) {
        os << p.nombreCompleto() << ", " << p.__edad << " años";
        return os;
    }
};


/**
 * Representa un auto con formateo
 */
class Auto {
private:
    string __marca;
    string __modelo;
    double __precio;
    int __anio;
    
    void validarPrecio(double precio) const {
        if (precio < 0) {
            throw invalid_argument("El precio no puede ser negativo");
        }
    }

public:
    Auto(string marca, string modelo, double precio, int anio)
        : __marca(marca), __modelo(modelo), __precio(0), __anio(anio) {
        setPrecio(precio);
    }
    
    double getPrecio() const { return __precio; }
    
    void setPrecio(double precio) {
        validarPrecio(precio);
        __precio = precio;
    }
    
    friend ostream& operator<<(ostream& os, const Auto& a) {
        os << a.__marca << " " << a.__modelo << " (" << a.__anio << ") - $";
        os.precision(2);
        os << fixed << a.__precio;
        return os;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    Persona p("Hugo", "Dominguez", "Lopez", 'M', 19);
    cout << p << endl << endl;
    
    Auto a("Honda", "Civic", 350000, 2022);
    cout << a << endl;
    
    return 0;
}
