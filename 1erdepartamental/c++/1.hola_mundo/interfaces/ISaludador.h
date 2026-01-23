#ifndef HOLA_MUNDO_ISALUDADOR_H
#define HOLA_MUNDO_ISALUDADOR_H

/**
 * Interfaz para objetos que pueden saludar
 */
class ISaludador {
public:
    virtual void mostrar() const = 0;
    virtual ~ISaludador() = default;
};

#endif // HOLA_MUNDO_ISALUDADOR_H
