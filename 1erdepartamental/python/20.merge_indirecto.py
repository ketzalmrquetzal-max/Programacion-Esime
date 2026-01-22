# ============================================
# PROGRAMA: Merge Sort Indirecto
# DESCRIPCIÓN: Fusión ordenando índices
# ============================================

from abc import ABC, abstractmethod


class OrdenadorIndirecto(ABC):
    """Base para ordenamiento indirecto"""

    def __init__(self, datos):
        self.__datos = datos
        self.__indices = list(range(len(datos)))

    @property
    def datos_originales(self):
        return self.__datos

    @property
    def indices(self):
        return self.__indices.copy()

    @abstractmethod
    def _ordenar_indices_impl(self, idx):
        pass

    def ordenar(self):
        self.__indices = self._ordenar_indices_impl(self.__indices)
        return self.__indices

    def acceder_ordenado(self):
        return [self.__datos[i] for i in self.__indices]


class OrdenadorMergeSortIndirecto(OrdenadorIndirecto):
    """Merge Sort que ordena índices"""

    def _ordenar_indices_impl(self, idx):
        if len(idx) <= 1:
            return idx

        medio = len(idx) // 2
        izq = self._ordenar_indices_impl(idx[:medio])
        der = self._ordenar_indices_impl(idx[medio:])

        return self._fusionar_indices(izq, der)

    def _fusionar_indices(self, izq, der):
        """Fusiona comparando datos[índice]"""
        resultado = []
        i = j = 0

        while i < len(izq) and j < len(der):
            # Compara usando índices para acceder datos
            if (
                self._OrdenadorIndirecto__datos[izq[i]]
                <= self._OrdenadorIndirecto__datos[der[j]]
            ):
                resultado.append(izq[i])
                i += 1
            else:
                resultado.append(der[j])
                j += 1

        resultado.extend(izq[i:])
        resultado.extend(der[j:])

        return resultado


class Persona:
    def __init__(self, nombre, edad):
        self.__nombre = nombre
        self.__edad = edad

    @property
    def nombre(self):
        return self.__nombre

    @property
    def edad(self):
        return self.__edad

    def __le__(self, otro):
        return self.__edad <= otro.edad

    def __str__(self):
        return f"{self.__nombre}({self.__edad})"


class OrdenadorMergeSortIndirectoPersonas(OrdenadorMergeSortIndirecto):
    pass


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    datos = [64, 34, 25, 12, 22, 11, 90]
    o = OrdenadorMergeSortIndirecto(datos)
    o.ordenar()

    print(f"Datos originales: {datos}")
    print(f"Acceso ordenado: {o.acceder_ordenado()}")

    print()

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorMergeSortIndirectoPersonas(personas)
    op.ordenar()
    print(f"Por edad: {[str(p) for p in op.acceder_ordenado()]}")
