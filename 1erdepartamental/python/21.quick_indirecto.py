# ============================================
# PROGRAMA: Quick Sort Indirecto
# DESCRIPCIÓN: Quick Sort ordenando índices
# ============================================

from abc import ABC, abstractmethod


class OrdenadorIndirectoBase(ABC):
    """Base para ordenadores indirectos"""

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
    def _ordenar_indices(self, idx):
        pass

    def ordenar(self):
        self.__indices = self._ordenar_indices(self.__indices)
        return self.__indices

    def acceder_ordenado(self):
        return [self.__datos[i] for i in self.__indices]


class OrdenadorQuickSortIndirecto(OrdenadorIndirectoBase):
    """Quick Sort que ordena índices"""

    def _ordenar_indices(self, idx):
        if len(idx) <= 1:
            return idx

        # Pivote: índice del medio
        pivote_val = self._OrdenadorIndirectoBase__datos[idx[len(idx) // 2]]

        # Particiona índices según su valor en datos
        menores = [
            i for i in idx if self._OrdenadorIndirectoBase__datos[i] < pivote_val
        ]
        iguales = [
            i for i in idx if self._OrdenadorIndirectoBase__datos[i] == pivote_val
        ]
        mayores = [
            i for i in idx if self._OrdenadorIndirectoBase__datos[i] > pivote_val
        ]

        return self._ordenar_indices(menores) + iguales + self._ordenar_indices(mayores)


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

    def __lt__(self, otro):
        return self.__edad < otro.edad

    def __eq__(self, otro):
        if not isinstance(otro, Persona):
            return False
        return self.__edad == otro.edad

    def __str__(self):
        return f"{self.__nombre}({self.__edad})"


class OrdenadorQuickSortIndirectoPersonas(OrdenadorQuickSortIndirecto):
    pass


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    datos = [64, 34, 25, 12, 22, 11, 90]
    o = OrdenadorQuickSortIndirecto(datos)
    o.ordenar()

    print(f"Datos originales: {datos}")
    print(f"Acceso ordenado: {o.acceder_ordenado()}")

    print()

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorQuickSortIndirectoPersonas(personas)
    op.ordenar()
    print(f"Por edad: {[str(p) for p in op.acceder_ordenado()]}")
