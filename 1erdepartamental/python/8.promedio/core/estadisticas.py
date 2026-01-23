# Estadísticas simples con 5 números fijos

#Clase Principal
class Estadisticas:
    def __init__(self, n1, n2, n3, n4, n5):
        self.__numeros = [n1, n2, n3, n4, n5] #Atributos guardados en lista
    
    def suma(self):
        return sum(self.__numeros)#suma todos los atributos que estan en la lista

    def promedio(self):#suma y divide todos los atributos que estan en la lista
        return self.suma() / len(self.__numeros)#len : numero de elementos en la lista

    def maximo(self):#maximo todos los atributos que estan en la lista
        return max(self.__numeros)

    def minimo(self):#minimo todos los atributos que estan en la lista
        return min(self.__numeros)
