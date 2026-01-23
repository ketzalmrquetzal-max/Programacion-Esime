# Estadísticas de estudiantes con puntero tipado

from utils.puntero_tipado import PunteroTipado


class Estudiante:
    def __init__(self, nombre, promedio):
        self.__nombre = nombre
        self.__promedio = promedio

    @property
    def nombre(self):
        return self.__nombre

    @property
    def promedio(self):
        return self.__promedio

    def __gt__(self, otro):
        return self.__promedio > otro.__promedio

    def __str__(self):
        return f"{self.__nombre} (Promedio: {self.__promedio})"


class EstadisticasEstudiantes:
    def __init__(self):
        self.__estudiantes = []

    def agregar(self, estudiante):
        self.__estudiantes.append(estudiante)

    def promedio_general(self):
        p = PunteroTipado(self.__estudiantes)
        suma = 0
        while p.en_rango():
            suma += p.get_at().promedio
            p.avanzar()
        return suma / len(self.__estudiantes)

    def mejor_estudiante(self):
        p = PunteroTipado(self.__estudiantes)
        mejor = p.get_at()
        while p.en_rango():
            if p.get_at() > mejor:
                mejor = p.get_at()
            p.avanzar()
        return mejor
