# Calculadoras especializadas con herencia


from abc import ABC, abstractmethod
import math

#clase base abstracta
class CalculadoraBase(ABC):
    #constructor
    #Inicia el resultado en cero
    def __init__(self):
        self.__resultado = 0
    #Decorador getter resultado
    @property
    def resultado(self):
        return self.__resultado

    #Metodo abstraacto 
    @abstractmethod
    def operacion_especial(self, valor):
        # Cada subclase define su operación especial
        pass

#Clase calculadora científica
class CalculadoraCientifica(CalculadoraBase):
    #Función que hace el calculo de la raíz cuadrada
    def raiz_cuadrada(self, n):
        #Validación de número negativo
        if n < 0:
            raise ValueError("No se puede calcular raíz de número negativo")
        self._CalculadoraBase__resultado = math.sqrt(n)
        return self._CalculadoraBase__resultado
    #Función que hace el calculo de la potencia
    def potencia(self, base, exponente):
        self._CalculadoraBase__resultado = base**exponente
        return self._CalculadoraBase__resultado
    #Implementacion de la función especial 
    def operacion_especial(self, valor):
        return self.raiz_cuadrada(valor)

#Clase calculadora financiera
class CalculadoraFinanciera(CalculadoraBase):
    #Funcion que hace el calculo el interes simple 
    def interes_simple(self, capital, tasa, tiempo):
        self._CalculadoraBase__resultado = capital * tasa * tiempo
        return self._CalculadoraBase__resultado
    #Función que hace el calculo el descuento 
    def descuento(self, precio, porcentaje):
        self._CalculadoraBase__resultado = precio * (porcentaje / 100)
        return self._CalculadoraBase__resultado
    #Implementacion de función especial
    def operacion_especial(self, valor):
        return self.descuento(valor, 15)
