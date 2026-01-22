# ============================================
# PROGRAMA: Merge Sort con POO
# DESCRIPCIÓN: Implementa algoritmo Divide y Conquista
# ============================================

from abc import ABC, abstractmethod


class OrdenadorDividirConquistar(ABC):
    """
    Clase base para algoritmos Divide y Conquista.

    Patrón Template Method:
        1. Dividir el problema
        2. Conquistar (resolver subproblemas)
        3. Combinar soluciones
    """

    def __init__(self, datos):
        self.__datos = datos.copy()
        self.__comparaciones = 0
        self.__fusiones = 0
        self.__divisiones = 0

    @property
    def datos(self):
        return self.__datos.copy()

    @property
    def estadisticas(self):
        """Retorna tupla (comparaciones, fusiones, divisiones)"""
        return (self.__comparaciones, self.__fusiones, self.__divisiones)

    def _incrementar_comparaciones(self):
        self.__comparaciones += 1

    def _incrementar_fusiones(self):
        self.__fusiones += 1

    def _incrementar_divisiones(self):
        self.__divisiones += 1

    @abstractmethod
    def _dividir(self, arr):
        """Divide recursivamente y ordena"""
        pass

    @abstractmethod
    def _combinar(self, izq, der):
        """Fusiona dos subarreglos ordenados"""
        pass

    def ordenar(self):
        self.__comparaciones = 0
        self.__fusiones = 0
        self.__divisiones = 0
        self.__datos = self._dividir(self.__datos)
        return self.datos

    def __str__(self):
        comp, fus, div = self.estadisticas
        return f"{self.__class__.__name__}: {comp} comparaciones, {fus} fusiones, {div} divisiones"


class OrdenadorMergeSort(OrdenadorDividirConquistar):
    """
    Merge Sort: Divide a la mitad, ordena recursivamente, fusiona.

    Complejidad: O(n log n) tiempo siempre, O(n) espacio
    """

    def _dividir(self, arr):
        """Caso base: arreglo de <= 1 elementos ya está ordenado"""
        if len(arr) <= 1:
            return arr

        # Dividir
        medio = len(arr) // 2
        self._incrementar_divisiones()

        # Conquistar (recursión)
        izquierda = self._dividir(arr[:medio])
        derecha = self._dividir(arr[medio:])

        # Combinar
        return self._combinar(izquierda, derecha)

    def _combinar(self, izq, der):
        """Fusiona dos arreglos ordenados en uno solo ordenado"""
        resultado = []
        i = j = 0

        self._incrementar_fusiones()

        # Compara y fusiona
        while i < len(izq) and j < len(der):
            self._incrementar_comparaciones()

            if izq[i] <= der[j]:
                resultado.append(izq[i])
                i += 1
            else:
                resultado.append(der[j])
                j += 1

        # Añade elementos restantes
        resultado.extend(izq[i:])
        resultado.extend(der[j:])

        return resultado


class Persona:
    """Representa una persona con edad validada"""

    def __init__(self, nombre, edad):
        if not nombre or not nombre.strip():
            raise ValueError("El nombre no puede estar vacío")

        self.__nombre = nombre.strip()
        self.__edad = 0
        self.edad = edad

    @property
    def nombre(self):
        return self.__nombre

    @property
    def edad(self):
        return self.__edad

    @edad.setter
    def edad(self, valor):
        if valor < 0:
            raise ValueError("La edad no puede ser negativa")
        if valor > 150:
            raise ValueError("Edad no realista")
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
        return self.__edad == otro.edad and self.__nombre == otro.nombre

    def __str__(self):
        return f"{self.__nombre}({self.__edad})"

    def __repr__(self):
        return f"Persona('{self.__nombre}', {self.__edad})"


class OrdenadorMergeSortPersonas(OrdenadorMergeSort):
    """Ordenador especializado para Personas"""

    def ordenar_por_nombre(self):
        """Ordena alfabéticamente por nombre"""
        datos_copia = self._OrdenadorDividirConquistar__datos.copy()
        datos_copia.sort(key=lambda p: p.nombre)
        return datos_copia


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    # Enteros
    print("=== Merge Sort: Enteros ===")
    ordenador = OrdenadorMergeSort([64, 34, 25, 12, 22, 11, 90])
    print(f"Resultado: {ordenador.ordenar()}")
    print(f"{ordenador}\n")

    # Strings
    print("=== Merge Sort: Strings ===")
    ordenador = OrdenadorMergeSort(["zorro", "abeja", "mono", "elefante"])
    print(f"Resultado: {ordenador.ordenar()}")
    print(f"{ordenador}\n")

    # Personas por edad
    print("=== Merge Sort: Personas por Edad ===")
    personas = [
        Persona("Juan", 25),
        Persona("Ana", 30),
        Persona("Pedro", 20),
        Persona("María", 28),
    ]
    ordenador = OrdenadorMergeSortPersonas(personas)
    print(f"Por edad: {[str(p) for p in ordenador.ordenar()]}")
    print(f"{ordenador}\n")

    # Por nombre
    print("=== Merge Sort: Personas por Nombre ===")
    print(f"Por nombre: {[str(p) for p in ordenador.ordenar_por_nombre()]}")
