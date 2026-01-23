# Tipos de datos personalizados

#Clase Persona
class Persona:
    #Constructor 
    #Inicia 
    def __init__(self, nombre, apellido, edad):
        self.__nombre = nombre
        self.__apellido = apellido
        self.__edad = edad

    @property
    def nombre(self):
        return self.__nombre

    @property
    def edad(self):
        return self.__edad

    def __str__(self):
        return f"{self.__nombre} {self.__apellido}, {self.__edad} años"


class Auto:
    def __init__(self, marca, modelo, precio):
        self.__marca = marca
        self.__modelo = modelo
        self.__precio = precio

    @property
    def precio(self):
        return self.__precio

    def __str__(self):
        return f"{self.__marca} {self.__modelo} - ${self.__precio:,.2f}"
