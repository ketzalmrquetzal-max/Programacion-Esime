# ============================================
# PROGRAMA: Estadísticas con Parámetros Fijos
# DESCRIPCIÓN: Calcula suma, promedio, máximo, mínimo
# ============================================


class Estadisticas:
    """
    Estadísticas sobre 5 números fijos.

    Implementaciones manuales (sin usar sum(), max(), min())
    """

    def __init__(self, n1, n2, n3, n4, n5):
        self.__numeros = [n1, n2, n3, n4, n5]

    @property
    def numeros(self):
        return self.__numeros.copy()

    def suma(self):
        """Suma manual con bucle"""
        total = 0
        for n in self.__numeros:
            total += n
        return total

    def promedio(self):
        """Media aritmética"""
        return self.suma() / len(self.__numeros)

    def maximo(self):
        """Encuentra el mayor sin usar max()"""
        m = self.__numeros[0]
        for n in self.__numeros:
            if n > m:
                m = n
        return m

    def minimo(self):
        """Encuentra el menor sin usar min()"""
        m = self.__numeros[0]
        for n in self.__numeros:
            if n < m:
                m = n
        return m


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    e = Estadisticas(10, 25, 5, 30, 15)

    print(f"Números: {e.numeros}")
    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Máximo: {e.maximo()}")
    print(f"Mínimo: {e.minimo()}")
