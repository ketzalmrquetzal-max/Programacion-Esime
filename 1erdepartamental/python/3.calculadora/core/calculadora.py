# Calculadora básica con ABC

from abc import ABC, abstractmethod


class Calculadora(ABC):
    def __init__(self):
        self.__resultado = 0

    @property
    def resultado(self):
        return self.__resultado

    @resultado.setter
    def resultado(self, valor):
        self.__resultado = valor

    def sumar(self, a, b):
        self.__resultado = a + b
        return self.__resultado

    def restar(self, a, b):
        self.__resultado = a - b
        return self.__resultado

    def multiplicar(self, a, b):
        self.__resultado = a * b
        return self.__resultado

    def dividir(self, a, b):
        if b == 0:
            raise ValueError("División por cero")
        self.__resultado = a / b
        return self.__resultado
