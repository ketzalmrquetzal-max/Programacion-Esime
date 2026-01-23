# Calculadora con sobrecarga simulada usando *args


class Calculadora:
    def __init__(self):
        self.__resultado = 0

    @property
    def resultado(self):
        return self.__resultado

    def sumar(self, *numeros):
        # *args simula sobrecarga: permite sumar(1,2) o sumar(1,2,3,4)
        self.__resultado = sum(numeros)
        return self.__resultado

    def multiplicar(self, *numeros):
        resultado = 1
        for n in numeros:
            resultado *= n
        self.__resultado = resultado
        return self.__resultado
