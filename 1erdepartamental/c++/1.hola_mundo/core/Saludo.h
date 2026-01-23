#ifndef HOLA_MUNDO_SALUDO_H
#define HOLA_MUNDO_SALUDO_H

#include <string>
#include "../interfaces/ISaludador.h"

// Clase Saludo
class Saludo : public ISaludador {
private:
    std::string __mensaje;
    
    // Valida que el mensaje no esté vacío
    void validarMensaje(const std::string& msg) const;

public:
    // Constructor - Inicializa el mensaje
    explicit Saludo(std::string msg = "Hola Mundo");
    
    // Obtiene el mensaje
    std::string getMensaje() const;
    // Establece el mensaje con validación
    void setMensaje(const std::string& msg);
    
    // Muestra el mensaje en consola
    void mostrar() const override;
    // Retorna un saludo personalizado
    std::string saludarPersona(const std::string& nombre) const;
    
    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Saludo& s);
};

#endif // HOLA_MUNDO_SALUDO_H
