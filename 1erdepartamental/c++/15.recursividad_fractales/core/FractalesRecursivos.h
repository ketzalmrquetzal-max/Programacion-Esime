#ifndef FRACTALES_RECURSIVOS_H
#define FRACTALES_RECURSIVOS_H

// Clase FractalesRecursivos
class FractalesRecursivos {
private:
    void dibujarTriangulo(int tamano);
    void dibujarLinea(int longitud);

public:
    // Dibuja fractal Sierpinski
    void sierpinski(int nivel, int tamano = 16);
    // Dibuja conjunto Cantor
    void cantor(int nivel, int longitud = 81);
};

#endif
