#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <iostream>

class Producto {
private:
    std::string __nombre;
    double __precio;
    void validarPrecio(double precio) const;

public:
    Producto(std::string nombre, double precio);
    std::string getNombre() const;
    double getPrecio() const;
    void setPrecio(double precio);
    
    bool operator<(const Producto& otro) const;
    friend std::ostream& operator<<(std::ostream& os, const Producto& p);
};

#endif
