#ifndef IORDENADOR_H
#define IORDENADOR_H

#include <vector>

template<typename T>
class IOrdenador {
public:
    virtual void ordenar(std::vector<T>& datos) = 0;
    virtual ~IOrdenador() = default;
};

#endif
