// ============================================
// PROGRAMA: Análisis de Tamaños de Memoria
// DESCRIPCIÓN: Demuestra sizeof para tipos básicos y custom
// ============================================

#include <iostream>
#include <string>
using namespace std;


/**
 * Tipo custom para análisis de tamaño
 */
class Persona {
private:
    string __nombre;
    string __apellido;
    int __edad;

public:
    Persona(string nombre, string apellido, int edad)
        : __nombre(nombre), __apellido(apellido), __edad(edad) {}
    
    friend ostream& operator<<(ostream& os, const Persona& p) {
        os << p.__nombre << " " << p.__apellido;
        return os;
    }
};


/**
 * Analizador de tamaños de memoria
 */
class AnalizadorTamanios {
public:
    void analizarTiposBasicos() const {
        cout << "=== TIPOS BÁSICOS ===" << endl;
        cout << "int: " << sizeof(int) << " bytes" << endl;
        cout << "double: " << sizeof(double) << " bytes" << endl;
        cout << "char: " << sizeof(char) << " bytes" << endl;
        cout << "bool: " << sizeof(bool) << " bytes" << endl;
        cout << "float: " << sizeof(float) << " bytes" << endl;
        cout << "long: " << sizeof(long) << " bytes" << endl;
        cout << endl;
    }
    
    void analizarString() const {
        cout << "=== STRINGS ===" << endl;
        string vacio = "";
        string corto = "Hola";
        string largo = "Este es un string mucho más largo";
        
        cout << "string vacío: " << sizeof(vacio) << " bytes" << endl;
        cout << "string corto: " << sizeof(corto) << " bytes" << endl;
        cout << "string largo: " << sizeof(largo) << " bytes" << endl;
        cout << "Nota: sizeof(string) mide el objeto, no el contenido" << endl;
        cout << endl;
    }
    
    void analizarObjeto() const {
        cout << "=== OBJETO CUSTOM ===" << endl;
        Persona p("Hugo", "Dominguez", 19);
        
        cout << "Persona: " << sizeof(p) << " bytes" << endl;
        cout << "Composición: 2 strings + 1 int" << endl;
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    AnalizadorTamanios analizador;
    
    analizador.analizarTiposBasicos();
    analizador.analizarString();
    analizador.analizarObjeto();
    
    return 0;
}
