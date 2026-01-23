#ifndef SUMA_PARAMETROS_IOPERADOR_H
#define SUMA_PARAMETROS_IOPERADOR_H

// Interfaz IOperadorMatematico
class IOperadorMatematico {
public:
    // Método virtual puro para ejecutar operación
    virtual double operar() = 0;
    // Destructor virtual por defecto
    virtual ~IOperadorMatematico() = default;
};

#endif // SUMA_PARAMETROS_IOPERADOR_H
