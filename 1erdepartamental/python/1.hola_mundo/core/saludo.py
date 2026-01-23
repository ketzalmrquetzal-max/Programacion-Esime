# Clase Saludo con encapsulación básica


class Saludo:
    def __init__(self, mensaje="Hola Mundo"):
        self.__mensaje = mensaje

    def mostrar(self):
        print(self.__mensaje)

    def saludar_persona(self, nombre):
        return f"Hola {nombre}"
