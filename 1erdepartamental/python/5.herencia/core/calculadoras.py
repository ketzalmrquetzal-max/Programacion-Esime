# Calculadoras especializadas con herencia

from abc import ABC, abstractmethod
import math


class CalculadoraBase(ABC):
    def __init__(self):
        self.__resultado = 0

    @property
    def resultado(self):
        return self.__resultado

    @abstractmethod
    def operacion_especial(self, valor):
        # Cada subclase define su operación especial
        pass


class CalculadoraCientifica(CalculadoraBase):
    def raiz_cuadrada(self, n):
        if n < 0:
            raise ValueError("No se puede calcular raíz de número negativo")
        self._CalculadoraBase__resultado = math.sqrt(n)
        return self._CalculadoraBase__resultado

    def potencia(self, base, exponente):
        self._CalculadoraBase__resultado = base**exponente
        return self._CalculadoraBase__resultado

    def operacion_especial(self, valor):
        return self.raiz_cuadrada(valor)


class CalculadoraFinanciera(CalculadoraBase):
    def interes_simple(self, capital, tasa, tiempo):
        self._CalculadoraBase__resultado = capital * tasa * tiempo
        return self._CalculadoraBase__resultado

    def descuento(self, precio, porcentaje):
        self._CalculadoraBase__resultado = precio * (porcentaje / 100)
        return self._CalculadoraBase__resultado

    def operacion_especial(self, valor):
        return self.descuento(valor, 15)
