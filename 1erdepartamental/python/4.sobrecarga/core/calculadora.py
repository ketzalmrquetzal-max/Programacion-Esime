# Calculadora con sobrecarga simulada usando *args


class Calculadora:
    def __init__(self):
        self.__resultado = 0 #valor por defecto

    #Decorador getter 
    @property
    def resultado(self):
        return self.__resultado #solo permite ver el resultado no cambiarlo

    #Funcion que hace la logica de sumar
    def sumar(self, *numeros):
        # Simula sobrecarga aceptando cantidad variable de argumentos
        self.__resultado = sum(numeros)
        return self.__resultado
    
    #Funcion que hace la logica de multiplicar
    def multiplicar(self, *numeros):
        resultado = 1
        for n in numeros:
            resultado *= n
        self.__resultado = resultado
        return self.__resultado
