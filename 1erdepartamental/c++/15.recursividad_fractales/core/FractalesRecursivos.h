#ifndef FRACTALES_RECURSIVOS_H
#define FRACTALES_RECURSIVOS_H

class FractalesRecursivos {
private:
    void dibujarTriangulo(int tamano);
    void dibujarLinea(int longitud);

public:
    void sierpinski(int nivel, int tamano = 16);
    void cantor(int nivel, int longitud = 81);
};

#endif
