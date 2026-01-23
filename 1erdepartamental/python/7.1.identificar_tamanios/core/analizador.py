# Analizador de tamaños en memoria

import sys

#Clase para analizar el tamaño de los tipos de datos
class AnalizadorTamanios:
    #Funcion que sirve para analizar tipos de dato basicos 
    def analizar_tipos_basicos(self):
        print("=== TIPOS BÁSICOS ===")
        print(f"int: {sys.getsizeof(10)} bytes")
        print(f"float: {sys.getsizeof(3.14)} bytes")
        print(f"str: {sys.getsizeof('Hola')} bytes")
        print(f"bool: {sys.getsizeof(True)} bytes")

    #Función que sirve para analizar tipos de cadenas 
    def analizar_strings(self):
        print("\n=== STRINGS ===")
        vacio = ""
        corto = "Hola"
        largo = "Este es un string mucho más largo"
        print(f"Vacío: {sys.getsizeof(vacio)} bytes")
        print(f"Corto: {sys.getsizeof(corto)} bytes")
        print(f"Largo: {sys.getsizeof(largo)} bytes")
    #Función que sirve para analizar el tamaño del objeto 
    def analizar_objeto(self, obj):
        print(f"\n=== OBJETO ===")
        print(f"Tamaño: {sys.getsizeof(obj)} bytes")

#clase persona 
class Persona:
   #Constructor
    def __init__(self, nombre, edad):
        self.nombre = nombre
        self.edad = edad
