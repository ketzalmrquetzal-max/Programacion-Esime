#ifndef AUTO_H
#define AUTO_H

#include <string>
#include <iostream>

// Clase Auto
class Auto {
private:
    std::string __marca, __modelo;
    double __precio;
    int __anio;
    void validarPrecio(double precio) const;

public:
    // Constructor - inicializa atributos
    Auto(std::string marca, std::string modelo, double precio, int anio);
    // Obtiene el precio
    double getPrecio() const;
    // Establece el precio con validacion
    void setPrecio(double precio);
    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Auto& a);
};

#endif
