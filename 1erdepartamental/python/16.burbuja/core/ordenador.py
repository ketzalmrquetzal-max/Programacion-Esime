# Ordenador burbuja


class OrdenadorBurbuja:
    def __init__(self):
        self.__comparaciones = 0
        self.__intercambios = 0

    def ordenar(self, datos):
        self.__comparaciones = 0
        self.__intercambios = 0
        n = len(datos)

        for i in range(n - 1):
            hubo_intercambio = False
            for j in range(n - i - 1):
                self.__comparaciones += 1
                if datos[j] > datos[j + 1]:
                    datos[j], datos[j + 1] = datos[j + 1], datos[j]
                    self.__intercambios += 1
                    hubo_intercambio = True
            if not hubo_intercambio:  # Optimización: termina si ya está ordenado
                break

    @property
    def comparaciones(self):
        return self.__comparaciones

    @property
    def intercambios(self):
        return self.__intercambios
