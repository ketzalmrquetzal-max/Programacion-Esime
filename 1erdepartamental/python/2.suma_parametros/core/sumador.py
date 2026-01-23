# Sumador con parámetros por defecto


class Sumador:
    def __init__(self, a=0, b=0):
        self.__a = a
        self.__b = b

    @property
    def a(self):
        return self.__a

    @a.setter
    def a(self, valor):
        self.__a = valor

    @property
    def b(self):
        return self.__b

    @b.setter
    def b(self, valor):
        self.__b = valor

    def sumar(self):
        return self.__a + self.__b

    def __add__(self, otro):
        # Sobrecarga del operador + para permitir s1 + s2
        return Sumador(self.__a + otro.__a, self.__b + otro.__b)

    def __str__(self):
        return f"Sumador(a={self.__a}, b={self.__b}, suma={self.sumar()})"
