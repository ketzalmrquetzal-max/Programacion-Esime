
#clase Calculadora 
class Calculadora:

   #Constructor
   #Se inicia con valor cero
    def __init__(self):
        self.__resultado = 0

    #Decorador getter
    @property
    def resultado(self):
        return self.__resultado
    
    #Decorador setter
    @resultado.setter
    def resultado(self, valor):
        self.__resultado = valor
    
    #Función que hace la  suma
    def sumar(self, a, b):
        self.__resultado = a + b
        return self.__resultado
    #Función que hace la resta
    def restar(self, a, b):
        self.__resultado = a - b
        return self.__resultado
    #Función que hace la mulplicación
    def multiplicar(self, a, b):
        self.__resultado = a * b
        return self.__resultado
    #Función que hace la división
    def dividir(self, a, b):
        if b == 0:
            #Aqui una excepción si el usuario divide entre cero
            raise ValueError("División por cero")
        self.__resultado = a / b
        return self.__resultado
