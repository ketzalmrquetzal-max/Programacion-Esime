# Estadísticas usando simulador de puntero

from utils.puntero import Puntero


class EstadisticasPuntero:
    def __init__(self, numeros):
        self.__numeros = list(numeros)

    def suma(self):
        p = Puntero(self.__numeros)
        total = 0
        while p.en_rango():
            total += p.get_at()
            p.avanzar()
        return total

    def promedio(self):
        return self.suma() / len(self.__numeros)

    def maximo(self):
        p = Puntero(self.__numeros)
        maximo = p.get_at()
        while p.en_rango():
            if p.get_at() > maximo:
                maximo = p.get_at()
            p.avanzar()
        return maximo

    def minimo(self):
        p = Puntero(self.__numeros)
        minimo = p.get_at()
        while p.en_rango():
            if p.get_at() < minimo:
                minimo = p.get_at()
            p.avanzar()
        return minimo
