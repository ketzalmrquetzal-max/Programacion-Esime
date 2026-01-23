#ifndef IORDENADOR_INDIRECTO_H
#define IORDENADOR_INDIRECTO_H

#include <vector>

template<typename T>
class IOrdenadorIndirecto {
public:
    virtual void ordenar() = 0;
    virtual std::vector<int> getIndices() const = 0;
    virtual ~IOrdenadorIndirecto() = default;
};

#endif
