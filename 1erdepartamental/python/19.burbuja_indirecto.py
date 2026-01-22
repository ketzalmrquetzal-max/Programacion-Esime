# ============================================
# PROGRAMA: Ordenamiento Indirecto con Burbuja
# DESCRIPCIÓN: Ordena mediante índices sin modificar original
# ============================================

from abc import ABC, abstractmethod


class OrdenadorIndirectoAbstracto(ABC):
    """
    Base para ordenamiento indirecto.

    INDIRECTO: No modifica datos originales, solo reordena índices
    """

    def __init__(self, datos):
        self.__datos = datos  # NO se modifica
        self.__indices = list(range(len(datos)))
        self.__comparaciones = 0

    @property
    def datos_originales(self):
        """Los datos nunca cambian"""
        return self.__datos

    @property
    def indices(self):
        return self.__indices.copy()

    @property
    def comparaciones(self):
        return self.__comparaciones

    def _incrementar_comparaciones(self):
        self.__comparaciones += 1

    @abstractmethod
    def _ordenar_indices(self):
        """Ordena solo los índices"""
        pass

    def ordenar(self):
        self.__comparaciones = 0
        self._ordenar_indices()
        return self.__indices

    def acceder_ordenado(self):
        """Accede a datos en orden sin modificarlos"""
        return [self.__datos[i] for i in self.__indices]


class OrdenadorBurbujaIndirecto(OrdenadorIndirectoAbstracto):
    """Bubble Sort indirecto: solo reordena índices"""

    def _ordenar_indices(self):
        """Compara datos[indices[j]] en lugar de datos[j]"""
        n = len(self._OrdenadorIndirectoAbstracto__indices)

        for i in range(n - 1):
            for j in range(n - 1 - i):
                self._incrementar_comparaciones()

                # Compara usando índices
                if (
                    self._OrdenadorIndirectoAbstracto__datos[
                        self._OrdenadorIndirectoAbstracto__indices[j]
                    ]
                    > self._OrdenadorIndirectoAbstracto__datos[
                        self._OrdenadorIndirectoAbstracto__indices[j + 1]
                    ]
                ):
                    # Intercambia índices, NO datos
                    (
                        self._OrdenadorIndirectoAbstracto__indices[j],
                        self._OrdenadorIndirectoAbstracto__indices[j + 1],
                    ) = (
                        self._OrdenadorIndirectoAbstracto__indices[j + 1],
                        self._OrdenadorIndirectoAbstracto__indices[j],
                    )


class Persona:
    """Persona simple para demostración"""

    def __init__(self, nombre, edad):
        self.__nombre = nombre
        self.__edad = edad

    @property
    def nombre(self):
        return self.__nombre

    @property
    def edad(self):
        return self.__edad

    def __gt__(self, otro):
        return self.__edad > otro.edad

    def __str__(self):
        return f"{self.__nombre}({self.__edad})"


class OrdenadorBurbujaIndirectoPersonas(OrdenadorBurbujaIndirecto):
    """Ordenador indirecto para personas"""

    pass


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    datos = [64, 34, 25, 12, 22, 11, 90]
    o = OrdenadorBurbujaIndirecto(datos)
    o.ordenar()

    print(f"Datos originales (sin cambios): {datos}")
    print(f"Índices ordenados: {o.indices}")
    print(f"Acceso ordenado: {o.acceder_ordenado()}")

    print()

    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    op = OrdenadorBurbujaIndirectoPersonas(personas)
    op.ordenar()
    print(f"Por edad: {[str(p) for p in op.acceder_ordenado()]}")
