# Estadísticas con arreglo dinámico


class EstadisticasArreglo:
    def __init__(self, numeros):
        self.__numeros = list(numeros)

    def suma(self):
        return sum(self.__numeros)

    def promedio(self):
        return self.suma() / len(self.__numeros)

    def maximo(self):
        return max(self.__numeros)

    def minimo(self):
        return min(self.__numeros)

    def agregar(self, numero):
        self.__numeros.append(numero)
