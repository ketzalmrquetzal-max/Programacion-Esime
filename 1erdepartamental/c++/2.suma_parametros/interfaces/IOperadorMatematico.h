#ifndef SUMA_PARAMETROS_IOPERADOR_H
#define SUMA_PARAMETROS_IOPERADOR_H

/**
 * Interfaz para operadores matemáticos
 */
class IOperadorMatematico {
public:
    virtual double operar() = 0;
    virtual ~IOperadorMatematico() = default;
};

#endif // SUMA_PARAMETROS_IOPERADOR_H
