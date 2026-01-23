#ifndef HOLA_MUNDO_SALUDO_H
#define HOLA_MUNDO_SALUDO_H

#include <string>
#include "../interfaces/ISaludador.h"

/**
 * Clase Saludo con encapsulación completa
 */
class Saludo : public ISaludador {
private:
    std::string __mensaje;
    
    void validarMensaje(const std::string& msg) const;

public:
    explicit Saludo(std::string msg = "Hola Mundo");
    
    std::string getMensaje() const;
    void setMensaje(const std::string& msg);
    
    void mostrar() const override;
    std::string saludarPersona(const std::string& nombre) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Saludo& s);
};

#endif // HOLA_MUNDO_SALUDO_H
