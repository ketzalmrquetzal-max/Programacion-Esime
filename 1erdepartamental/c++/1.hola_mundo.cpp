// ============================================
// PROGRAMA: Hola Mundo con POO
// DESCRIPCIÓN: Introducción a clases y encapsulación
// ============================================

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


/**
 * Interfaz para objetos que pueden saludar
 */
class ISaludador {
public:
    virtual void mostrar() const = 0;
    virtual ~ISaludador() {}
};


/**
 * Clase Saludo con encapsulación completa
 * 
 * Demuestra: constructor, atributos privados, getters/setters, const
 */
class Saludo : public ISaludador {
private:
    string __mensaje;
    
    void validarMensaje(const string& msg) const {
        if (msg.empty()) {
            throw invalid_argument("El mensaje no puede estar vacío");
        }
    }

public:
    Saludo(string msg = "Hola Mundo") : __mensaje("") {
        setMensaje(msg);
    }
    
    string getMensaje() const { return __mensaje; }
    
    void setMensaje(const string& msg) {
        validarMensaje(msg);
        __mensaje = msg;
    }
    
    void mostrar() const override {
        cout << __mensaje << endl;
    }
    
    string saludarPersona(const string& nombre) const {
        if (nombre.empty()) {
            throw invalid_argument("El nombre no puede estar vacío");
        }
        return "Hola " + nombre;
    }
    
    // Operator overloading
    friend ostream& operator<<(ostream& os, const Saludo& s) {
        os << "Saludo(mensaje=\"" << s.__mensaje << "\")";
        return os;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    Saludo s;
    s.mostrar();
    
    cout << s.saludarPersona("Hugo") << endl;
    
    cout << s << endl;
    
    return 0;
}
