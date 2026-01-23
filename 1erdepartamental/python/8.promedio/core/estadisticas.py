# Estadísticas simples con 5 números fijos


class Estadisticas:
    def __init__(self, n1, n2, n3, n4, n5):
        self.__numeros = [n1, n2, n3, n4, n5]

    def suma(self):
        return sum(self.__numeros)

    def promedio(self):
        return self.suma() / len(self.__numeros)

    def maximo(self):
        return max(self.__numeros)

    def minimo(self):
        return min(self.__numeros)
