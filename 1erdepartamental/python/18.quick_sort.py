# ============================================
# PROGRAMA: Quick Sort con POO
# DESCRIPCIÓN: Implementa QuickSort con patrón Strategy
# ============================================

from abc import ABC, abstractmethod
from enum import Enum, auto


class EstrategiaPivote(Enum):
    """Estrategias para selección de pivote"""

    PRIMERO = auto()
    ULTIMO = auto()
    MEDIO = auto()


class OrdenadorQuickSort:
    """
    Quick Sort: Selecciona pivote, particiona, ordena recursivamente.

    Complejidad: O(n log n) promedio, O(n²) peor caso
    Patrón Strategy: Permite cambiar estrategia de pivote
    """

    def __init__(self, datos, estrategia=EstrategiaPivote.MEDIO):
        self.__datos = datos.copy()
        self.__estrategia = estrategia
        self.__comparaciones = 0
        self.__particiones = 0

    @property
    def datos(self):
        return self.__datos.copy()

    @property
    def comparaciones(self):
        return self.__comparaciones

    @property
    def particiones(self):
        return self.__particiones

    @property
    def estrategia(self):
        return self.__estrategia

    @estrategia.setter
    def estrategia(self, nueva):
        """Permite cambiar estrategia en runtime"""
        if not isinstance(nueva, EstrategiaPivote):
            raise TypeError("Debe ser una EstrategiaPivote válida")
        self.__estrategia = nueva

    def _seleccionar_indice_pivote(self, arr):
        """Patrón Strategy: delega a la estrategia seleccionada"""
        if self.__estrategia == EstrategiaPivote.PRIMERO:
            return 0
        elif self.__estrategia == EstrategiaPivote.ULTIMO:
            return len(arr) - 1
        else:  # MEDIO
            return len(arr) // 2

    def _particionar(self, arr):
        """Divide en: menores, iguales, mayores al pivote"""
        if len(arr) <= 1:
            return arr, [], []

        self.__particiones += 1

        indice_pivote = self._seleccionar_indice_pivote(arr)
        pivote = arr[indice_pivote]

        menores = []
        iguales = []
        mayores = []

        for elemento in arr:
            self.__comparaciones += 1
            if elemento < pivote:
                menores.append(elemento)
            elif elemento == pivote:
                iguales.append(elemento)
            else:
                mayores.append(elemento)

        return menores, iguales, mayores

    def _quick_sort_recursivo(self, arr):
        """Recursión: divide, conquista, combina"""
        if len(arr) <= 1:
            return arr

        menores, iguales, mayores = self._particionar(arr)

        return (
            self._quick_sort_recursivo(menores)
            + iguales
            + self._quick_sort_recursivo(mayores)
        )

    def ordenar(self):
        self.__comparaciones = 0
        self.__particiones = 0
        self.__datos = self._quick_sort_recursivo(self.__datos)
        return self.datos

    def __str__(self):
        return (
            f"QuickSort({self.__estrategia.name}): {self.__comparaciones} comparaciones"
        )


class Persona:
    """Representa una persona con validación"""

    def __init__(self, nombre, edad):
        self.__nombre = self._validar_nombre(nombre)
        self.__edad = 0
        self.edad = edad

    @staticmethod
    def _validar_nombre(nombre):
        """Valida y normaliza el nombre"""
        if not nombre or not nombre.strip():
            raise ValueError("El nombre no puede estar vacío")
        return nombre.strip().title()

    @property
    def nombre(self):
        return self.__nombre

    @property
    def edad(self):
        return self.__edad

    @edad.setter
    def edad(self, valor):
        if not isinstance(valor, int):
            raise TypeError("La edad debe ser un entero")
        if valor < 0 or valor > 150:
            raise ValueError("Edad fuera de rango (0-150)")
        self.__edad = valor

    def __lt__(self, otro):
        return self.__edad < otro.edad

    def __le__(self, otro):
        return self.__edad <= otro.edad

    def __gt__(self, otro):
        return self.__edad > otro.edad

    def __ge__(self, otro):
        return self.__edad >= otro.edad

    def __eq__(self, otro):
        if not isinstance(otro, Persona):
            return NotImplemented
        return self.__edad == otro.edad

    def __hash__(self):
        return hash((self.__nombre, self.__edad))

    def __str__(self):
        return f"{self.__nombre}({self.__edad})"

    def __repr__(self):
        return f"Persona('{self.__nombre}', {self.__edad})"


class OrdenadorQuickSortPersonas(OrdenadorQuickSort):
    """Ordenador especializado para Personas"""

    def ordenar_por_nombre(self):
        """Ordena alfabéticamente por nombre"""
        datos_copia = self._OrdenadorQuickSort__datos.copy()
        datos_copia.sort(key=lambda p: p.nombre)
        return datos_copia


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    # Enteros
    print("=== QuickSort: Enteros ===")
    ordenador = OrdenadorQuickSort([64, 34, 25, 12, 22, 11, 90, 25, 12])
    print(f"Resultado: {ordenador.ordenar()}")
    print(f"{ordenador}\n")

    # Diferentes estrategias
    print("=== QuickSort: Diferentes Estrategias ===")
    datos = [5, 2, 8, 1, 9, 3]
    for estrategia in [
        EstrategiaPivote.PRIMERO,
        EstrategiaPivote.MEDIO,
        EstrategiaPivote.ULTIMO,
    ]:
        ord = OrdenadorQuickSort(datos, estrategia)
        ord.ordenar()
        print(f"{ord}\n")

    # Personas
    print("=== QuickSort: Personas ===")
    personas = [
        Persona("Juan", 25),
        Persona("Ana", 30),
        Persona("Pedro", 20),
        Persona("María", 28),
    ]
    ordenador = OrdenadorQuickSortPersonas(personas)

    print("Por edad:")
    print([str(p) for p in ordenador.ordenar()])

    print("\nPor nombre:")
    print([str(p) for p in ordenador.ordenar_por_nombre()])
