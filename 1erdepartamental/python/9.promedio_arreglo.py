# ============================================
# PROGRAMA: Estadísticas con Arreglo Dinámico
# DESCRIPCIÓN: Acepta cualquier cantidad de números
# ============================================


class EstadisticasArreglo:
    """
    Estadísticas sobre arreglo de tamaño variable.

    Más flexible que la versión de parámetros fijos.
    """

    def __init__(self, arreglo):
        self.__datos = arreglo.copy()

    @property
    def datos(self):
        return self.__datos.copy()

    def suma(self):
        total = 0
        for n in self.__datos:
            total += n
        return total

    def promedio(self):
        return self.suma() / len(self.__datos)

    def maximo(self):
        m = self.__datos[0]
        for n in self.__datos:
            if n > m:
                m = n
        return m

    def minimo(self):
        m = self.__datos[0]
        for n in self.__datos:
            if n < m:
                m = n
        return m

    def agregar(self, valor):
        """Ventaja sobre versión fija: puede crecer"""
        self.__datos.append(valor)


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    e = EstadisticasArreglo([10, 25, 5, 30, 15])

    print(f"Datos: {e.datos}")
    print(f"Suma: {e.suma()}")
    print(f"Promedio: {e.promedio()}")
    print(f"Máximo: {e.maximo()}")
    print(f"Mínimo: {e.minimo()}")

    e.agregar(50)
    print(f"\nDespués de agregar 50:")
    print(f"Datos: {e.datos}")
    print(f"Promedio: {e.promedio()}")
