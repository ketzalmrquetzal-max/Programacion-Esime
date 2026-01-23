#ifndef HOLA_MUNDO_ISALUDADOR_H
#define HOLA_MUNDO_ISALUDADOR_H

// Interfaz ISaludador
class ISaludador {
public:
    // Método virtual puro para mostrar mensaje
    virtual void mostrar() const = 0;
    // Destructor virtual por defecto
    virtual ~ISaludador() = default;
};

#endif // HOLA_MUNDO_ISALUDADOR_H
