#Clase que realiza toda la logica
class Sumador:
    #valores por defecto 0
    def __init__(self, a=0, b=0):
        self.__a = a
        self.__b = b
    #Decorador getter a
    @property
    def a(self):
        return self.__a
    #Decorador setter a
    @a.setter
    def a(self, valor):
        self.__a = valor
    #Decorador getter b
    @property
    def b(self):
        return self.__b
    #Decorador setter b
    @b.setter
    def b(self, valor):
        self.__b = valor
    #Funcion que realiza toda la logica
    def sumar(self):
        return self.__a + self.__b

    def __add__(self, otro):
        # Permite s1 + s2
        return Sumador(self.__a + otro.__a, self.__b + otro.__b)

    def __str__(self):
        return f"Sumador(a={self.__a}, b={self.__b}, suma={self.sumar()})"
