// ============================================
// PROGRAMA: Colección de Tipos de Datos Personalizados
// DESCRIPCIÓN: Array de objetos custom
// ============================================

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;


/**
 * Tipo de dato: Producto
 */
class Producto {
private:
    string __nombre;
    double __precio;
    
    void validarPrecio(double precio) const {
        if (precio < 0) {
            throw invalid_argument("Precio no puede ser negativo");
        }
    }

public:
    Producto(string nombre, double precio)
        : __nombre(nombre), __precio(0) {
        setPrecio(precio);
    }
    
    string getNombre() const { return __nombre; }
    double getPrecio() const { return __precio; }
    
    void setPrecio(double precio) {
        validarPrecio(precio);
        __precio = precio;
    }
    
    friend ostream& operator<<(ostream& os, const Producto& p) {
        os << p.__nombre << ": $" << p.__precio;
        return os;
    }
    
    bool operator<(const Producto& otro) const {
        return __precio < otro.__precio;
    }
};


/**
 * Colección especializada de productos
 */
class ColeccionProductos {
private:
    vector<Producto> __productos;

public:
    void agregar(const Producto& p) {
        __productos.push_back(p);
    }
    
    size_t cantidad() const {
        return __productos.size();
    }
    
    Producto& obtener(size_t indice) {
        if (indice >= __productos.size()) {
            throw out_of_range("Índice fuera de rango");
        }
        return __productos[indice];
    }
    
    double precioTotal() const {
        double total = 0;
        for (const auto& p : __productos) {
            total += p.getPrecio();
        }
        return total;
    }
    
    double precioPromedio() const {
        if (__productos.empty()) return 0;
        return precioTotal() / __productos.size();
    }
    
    void mostrar() const {
        for (size_t i = 0; i < __productos.size(); i++) {
            cout << i << ": " << __productos[i] << endl;
        }
    }
};


// ============================================
// EJECUCIÓN
// ============================================
int main() {
    ColeccionProductos inventario;
    
    inventario.agregar(Producto("Laptop", 15000));
    inventario.agregar(Producto("Mouse", 250));
    inventario.agregar(Producto("Teclado", 800));
    
    cout << "=== INVENTARIO ===" << endl;
    inventario.mostrar();
    cout << "\nTotal de productos: " << inventario.cantidad() << endl;
    cout << "Precio total: $" << inventario.precioTotal() << endl;
    cout << "Precio promedio: $" << inventario.precioPromedio() << endl;
    
    return 0;
}
