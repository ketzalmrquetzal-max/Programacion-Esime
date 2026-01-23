#ifndef AUTO_H
#define AUTO_H

#include <string>
#include <iostream>

class Auto {
private:
    std::string __marca, __modelo;
    double __precio;
    int __anio;
    void validarPrecio(double precio) const;

public:
    Auto(std::string marca, std::string modelo, double precio, int anio);
    double getPrecio() const;
    void setPrecio(double precio);
    friend std::ostream& operator<<(std::ostream& os, const Auto& a);
};

#endif
