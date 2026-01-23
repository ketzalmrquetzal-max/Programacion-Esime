# Estadísticas de estudiantes con puntero tipado
#Importa la clase PunteroTipado
from utils.puntero_tipado import PunteroTipado

#Clase Estudiante
class Estudiante:
    #Constructor 
    #Inicializa el nombre y el promedio 
    def __init__(self, nombre, promedio):
        self.__nombre = nombre
        self.__promedio = promedio
    #Decorador getter nombre
    @property
    def nombre(self):
        return self.__nombre
    #Decorador getter nombre
    @property
    def promedio(self):
        return self.__promedio
    #Función que compara promedios entre estudiantes 
    def __gt__(self, otro):
        return self.__promedio > otro.__promedio
    #Método especial _str_
    #Define cómo se muestra el estudiante
    def __str__(self):
        return f"{self.__nombre} (Promedio: {self.__promedio})"

#Clase EstadisticasEstudiantes
class EstadisticasEstudiantes:
    #Constructor 
    #Inicializa la lista de estudianes 
    def __init__(self):
        self.__estudiantes = []
    #Función que agrega estudiantes 
    def agregar(self, estudiante):
        self.__estudiantes.append(estudiante)
    #Función que calcula el promedio general 
    def promedio_general(self):
        p = PunteroTipado(self.__estudiantes)
        suma = 0
        while p.en_rango():
            suma += p.get_at().promedio
            p.avanzar()
        return suma / len(self.__estudiantes)
    #Función para obtener quien es el mejor estudiante 
    def mejor_estudiante(self):
        p = PunteroTipado(self.__estudiantes)
        mejor = p.get_at()
        while p.en_rango():
            if p.get_at() > mejor:
                mejor = p.get_at()
            p.avanzar()
        return mejor
