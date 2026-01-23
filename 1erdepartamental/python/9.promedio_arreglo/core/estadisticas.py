# Estadísticas con arreglo dinámico

#Clase estadisticas 
class EstadisticasArreglo:
    #Constructor 
    #Inicia la lista de los nuemeros
    def __init__(self, numeros):
        self.__numeros = list(numeros)
    #Función que calcula la suma de los números
    def suma(self):
        return sum(self.__numeros)
    #Función que calcula el promedio de los números
    def promedio(self):
        return self.suma() / len(self.__numeros)
    #Funón que obtiene el valor maximo
    def maximo(self):
        return max(self.__numeros)
    #Función que obtiene el valor minimo
    def minimo(self):
        return min(self.__numeros)
    #Función que agrega un número al arreglo
    def agregar(self, numero):
        self.__numeros.append(numero)
