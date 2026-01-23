# Generador de fractales recursivos


class FractalesRecursivos:
    def sierpinski(self, nivel, tamano=16):
        if nivel == 0:
            self._dibujar_triangulo(tamano)
            return
        print(f"Sierpinski nivel {nivel}:")
        self.sierpinski(nivel - 1, tamano // 2)
        print()

    def cantor(self, nivel, longitud=81):
        if nivel == 0:
            print("#" * longitud)
            return
        self.cantor(nivel - 1, longitud // 3)
        print(" " * (longitud // 3), end="")
        self.cantor(nivel - 1, longitud // 3)

    def _dibujar_triangulo(self, tamano):
        for i in range(tamano):
            print(" " * (tamano - i - 1) + "*" * (2 * i + 1))
