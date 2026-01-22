# ============================================
# PROGRAMA: Fractales con Recursividad
# DESCRIPCIÓN: Sierpinski y Cantor con recursión
# ============================================


class Sierpinski:
    """
    Triángulo de Sierpinski fractal.

    Cada nivel tiene 3^n triángulos
    """

    def __init__(self, nivel):
        self.__nivel = nivel

    @property
    def nivel(self):
        return self.__nivel

    def contar_triangulos(self, n=None):
        """
        T(n) = 3 × T(n-1)
        Base: T(0) = 1
        """
        if n is None:
            n = self.__nivel
        if n == 0:
            return 1
        return 3 * self.contar_triangulos(n - 1)

    def total_acumulado(self, n=None):
        """Suma de triángulos desde nivel 0 hasta n"""
        if n is None:
            n = self.__nivel
        if n == 0:
            return 1
        return self.contar_triangulos(n) + self.total_acumulado(n - 1)

    def dibujar(self, nivel=None):
        """Genera representación ASCII del fractal"""
        if nivel is None:
            nivel = self.__nivel
        if nivel == 0:
            return ["*"]

        t = self.dibujar(nivel - 1)
        h = len(t)

        # Superior: triángulo centrado
        resultado = [" " * h + linea for linea in t]
        # Inferior: dos copias
        for i in range(h):
            resultado.append(t[i] + " " + t[i])

        return resultado


class Cantor:
    """
    Conjunto de Cantor fractal.

    Cada nivel tiene 2^n segmentos
    """

    def __init__(self, nivel):
        self.__nivel = nivel

    @property
    def nivel(self):
        return self.__nivel

    def contar_segmentos(self, n=None):
        """
        S(n) = 2 × S(n-1)
        Base: S(0) = 1
        """
        if n is None:
            n = self.__nivel
        if n == 0:
            return 1
        return 2 * self.contar_segmentos(n - 1)

    def generar_segmentos(self, n, inicio=0, fin=81):
        """
        Genera posiciones de segmentos.
        Divide en 3, elimina tercio central
        """
        if n == 0:
            return [[inicio, fin]]

        tercio = (fin - inicio) / 3

        # Recursión en tercios izquierdo y derecho
        izq = self.generar_segmentos(n - 1, inicio, inicio + tercio)
        der = self.generar_segmentos(n - 1, inicio + 2 * tercio, fin)

        return izq + der


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    s = Sierpinski(4)
    print(f"Triángulos nivel 4: {s.contar_triangulos()}")
    print(f"Total acumulado: {s.total_acumulado()}")

    print("\nSierpinski nivel 3:")
    for linea in s.dibujar(3):
        print(linea)

    c = Cantor(4)
    print(f"\nSegmentos Cantor nivel 4: {c.contar_segmentos()}")
