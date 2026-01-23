#Libreria para cear clases abstractas
from abc import ABC, abstractmethod


class CalculadoraBase(ABC):
    def __init__(self):
        self.__resultado = 0

    @property
    def resultado(self):
        return self.__resultado
    #Obliga a las clases hijas tener el metodo multiplicar
    @abstractmethod
    #idea
    def multiplicar(self, a, b):
        pass
    #Obliga a las clases hijas tener el metodo potencia
    @abstractmethod
    def potencia(self, base, exp):
        pass
    #Obliga a las clases hijas tener el metodo dividir
    @abstractmethod
    def dividir(self, a, b):
        pass

#Clase Hija 1
class CalculadoraDirecta(CalculadoraBase):
    # Implementación directa - usa operadores nativos de Python
    def multiplicar(self, a, b):
        self._CalculadoraBase__resultado = (
            a * b
        )  # Name mangling para acceder a __resultado
        return self._CalculadoraBase__resultado

    def potencia(self, base, exp):
        self._CalculadoraBase__resultado = base**exp
        return self._CalculadoraBase__resultado

    def dividir(self, a, b):
        if b == 0:
            raise ValueError("División por cero")#Evitamos que el programa se rompa
        self._CalculadoraBase__resultado = a / b
        return self._CalculadoraBase__resultado

#Clase Hija 2
class CalculadoraSucesiva(CalculadoraBase):#Hereda de CalculadoraBase
    # Implementación algorítmica - usa loops en lugar de operadores
    def multiplicar(self, a, b):
        resultado = 0
        for _ in range(int(b)):  # Multiplica sumando repetidamente
            resultado += a
        self._CalculadoraBase__resultado = resultado
        return self._CalculadoraBase__resultado

    def potencia(self, base, exp):
        resultado = 1
        for _ in range(int(exp)):#repetimos el ciclo la misma cantidad que exp
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
