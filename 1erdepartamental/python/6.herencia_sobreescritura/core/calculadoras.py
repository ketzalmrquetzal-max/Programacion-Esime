# Calculadoras con sobreescritura de métodos

from abc import ABC, abstractmethod


class CalculadoraBase(ABC):
    def __init__(self):
        self.__resultado = 0

    @property
    def resultado(self):
        return self.__resultado

    @abstractmethod
    def multiplicar(self, a, b):
        pass

    @abstractmethod
    def potencia(self, base, exp):
        pass

    @abstractmethod
    def dividir(self, a, b):
        pass


class CalculadoraDirecta(CalculadoraBase):
    # Sobreescribe métodos usando operadores nativos (*, **, /)
    def multiplicar(self, a, b):
        self._CalculadoraBase__resultado = a * b
        return self._CalculadoraBase__resultado

    def potencia(self, base, exp):
        self._CalculadoraBase__resultado = base**exp
        return self._CalculadoraBase__resultado

    def dividir(self, a, b):
        if b == 0:
            raise ValueError("División por cero")
        self._CalculadoraBase__resultado = a / b
        return self._CalculadoraBase__resultado


class CalculadoraSucesiva(CalculadoraBase):
    # Sobreescribe métodos usando loops (enfoque educativo)
    def multiplicar(self, a, b):
        resultado = 0
        for _ in range(int(b)):
            resultado += a
        self._CalculadoraBase__resultado = resultado
        return self._CalculadoraBase__resultado

    def potencia(self, base, exp):
        resultado = 1
        for _ in range(int(exp)):
            resultado *= base
        self._CalculadoraBase__resultado = resultado
        return self._CalculadoraBase__resultado

    def dividir(self, a, b):
        if b == 0:
            raise ValueError("División por cero")
        resultado = 0
        residuo = a
        while residuo >= b:
            residuo -= b
            resultado += 1
        self._CalculadoraBase__resultado = resultado
        return self._CalculadoraBase__resultado
