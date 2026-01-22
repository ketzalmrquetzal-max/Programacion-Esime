class Sierpinski:
    def __init__(self, nivel):
        self.nivel = nivel

    def contar_triangulos(self, n=None):
        if n is None:
            n = self.nivel
        if n == 0:
            return 1
        return 3 * self.contar_triangulos(n - 1)

    def total_acumulado(self, n=None):
        if n is None:
            n = self.nivel
        if n == 0:
            return 1
        return self.contar_triangulos(n) + self.total_acumulado(n - 1)

    def dibujar(self, nivel=None):
        if nivel is None:
            nivel = self.nivel
        if nivel == 0:
            return ["*"]
        t = self.dibujar(nivel - 1)
        h = len(t)
        resultado = [" " * h + linea for linea in t]
        for i in range(h):
            resultado.append(t[i] + " " + t[i])
        return resultado


class Cantor:
    def __init__(self, nivel):
        self.nivel = nivel

    def contar_segmentos(self, n=None):
        if n is None:
            n = self.nivel
        if n == 0:
            return 1
        return 2 * self.contar_segmentos(n - 1)

    def generar_segmentos(self, n, inicio=0, fin=81):
        if n == 0:
            return [[inicio, fin]]
        tercio = (fin - inicio) / 3
        izq = self.generar_segmentos(n - 1, inicio, inicio + tercio)
        der = self.generar_segmentos(n - 1, inicio + 2 * tercio, fin)
        return izq + der


if __name__ == "__main__":
    s = Sierpinski(4)
    print(f"Triangulos nivel 4: {s.contar_triangulos()}")
    print(f"Total acumulado: {s.total_acumulado()}")
    for linea in s.dibujar(3):
        print(linea)

    c = Cantor(4)
    print(f"\nSegmentos Cantor nivel 4: {c.contar_segmentos()}")
