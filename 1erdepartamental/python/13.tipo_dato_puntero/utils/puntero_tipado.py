# Puntero tipado genérico

#Clase Puntero tipado
class PunteroTipado:
    #Constructor
    #Inicia los datos y el índice 
    def __init__(self, datos):
        self.__datos = datos
        self.__indice = 0
    #Función para obteener el valor actual 
    def get_at(self):
        #Verifica que el indice este dentro del rango
        if self.__indice >= len(self.__datos):
            raise IndexError("Fuera de rango")
        return self.__datos[self.__indice]
    #Función que avanza el puntero
    def avanzar(self):
        self.__indice += 1
    #Función que reinicia el puntero 
    def reset(self):
        self.__indice = 0
    #Función que el puntero si este en rango
    def en_rango(self):
        return self.__indice < len(self.__datos)
