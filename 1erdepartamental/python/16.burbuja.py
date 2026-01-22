# ============================================
# PROGRAMA: Ordenamiento Burbuja con POO
# DESCRIPCIÓN: Implementa Bubble Sort con principios OOP profesionales
# ============================================

from abc import ABC, abstractmethod


class OrdenadorAbstracto(ABC):
    """
    Clase base abstracta para algoritmos de ordenamiento.

    ABSTRACCIÓN: Define interfaz común para todos los ordenadores
    ENCAPSULACIÓN: Datos privados con __
    POLIMORFISMO: Método abstracto para implementación específica
    """

    def __init__(self, datos):
        """Copia defensiva: evita modificación del original"""
        self.__datos = datos.copy()
        self.__comparaciones = 0
        self.__intercambios = 0

    @property
    def datos(self):
        """Retorna copia para evitar modificaciones externas"""
        return self.__datos.copy()

    @property
    def comparaciones(self):
        return self.__comparaciones

    @property
    def intercambios(self):
        return self.__intercambios

    def _incrementar_comparaciones(self):
        self.__comparaciones += 1

    def _incrementar_intercambios(self):
        self.__intercambios += 1

    @abstractmethod
    def _ordenar_implementacion(self):
        """Cada subclase implementa su algoritmo específico"""
        pass

    def ordenar(self):
        """Patrón Template Method: define flujo, delega implementación"""
        self.__comparaciones = 0
        self.__intercambios = 0
        self._ordenar_implementacion()
        return self.datos

    def __str__(self):
        return f"{self.__class__.__name__}: {self.__comparaciones} comparaciones, {self.__intercambios} intercambios"


class OrdenadorBurbuja(OrdenadorAbstracto):
    """
    Implementación del algoritmo Bubble Sort.

    Complejidad: O(n²) tiempo, O(1) espacio
    """

    def _ordenar_implementacion(self):
        """Algoritmo: compara pares adyacentes y los intercambia si están desordenados"""
        n = len(self._OrdenadorAbstracto__datos)

        for i in range(n - 1):
            for j in range(n - 1 - i):
                self._incrementar_comparaciones()

                if (
                    self._OrdenadorAbstracto__datos[j]
                    > self._OrdenadorAbstracto__datos[j + 1]
                ):
                    # Swap
                    (
                        self._OrdenadorAbstracto__datos[j],
                        self._OrdenadorAbstracto__datos[j + 1],
                    ) = (
                        self._OrdenadorAbstracto__datos[j + 1],
                        self._OrdenadorAbstracto__datos[j],
                    )
                    self._incrementar_intercambios()


class Persona:
    """
    Representa una persona con validación completa.

    ENCAPSULACIÓN: Atributos privados con __
    VALIDACIÓN: Properties con setters
    POLIMORFISMO: Operadores sobrecargados
    """

    def __init__(self, nombre, edad):
        self.__nombre = nombre
        self.__edad = 0
        self.edad = edad  # Usa setter para validación

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
        self.__edad = valor

    def __lt__(self, otro):
        return self.__edad < otro.edad

    def __gt__(self, otro):
        return self.__edad > otro.edad

    def __eq__(self, otro):
        if not isinstance(otro, Persona):
            return NotImplemented
        return self.__edad == otro.edad and self.__nombre == otro.nombre

    def __str__(self):
        return f"{self.__nombre}({self.__edad})"

    def __repr__(self):
        return f"Persona('{self.__nombre}', {self.__edad})"


class OrdenadorBurbujaPersonas(OrdenadorBurbuja):
    """
    Ordenador especializado para personas.

    HERENCIA: Extiende OrdenadorBurbuja
    POLIMORFISMO: Puede usarse como OrdenadorAbstracto
    """

    def ordenar_por_nombre(self):
        """Ordena alfabéticamente por nombre"""
        self._OrdenadorAbstracto__datos.sort(key=lambda p: p.nombre)
        return self.datos


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    # Enteros
    print("=== Enteros ===")
    ordenador = OrdenadorBurbuja([64, 34, 25, 12, 22, 11, 90])
    print(f"Resultado: {ordenador.ordenar()}")
    print(f"{ordenador}\n")

    # Strings
    print("=== Strings ===")
    ordenador = OrdenadorBurbuja(["d", "a", "c", "b", "e"])
    print(f"Resultado: {ordenador.ordenar()}")
    print(f"{ordenador}\n")

    # Personas por edad
    print("=== Personas por Edad ===")
    personas = [Persona("Juan", 25), Persona("Ana", 30), Persona("Pedro", 20)]
    ordenador = OrdenadorBurbujaPersonas(personas)
    resultado = ordenador.ordenar()
    print(f"Por edad: {[str(p) for p in resultado]}")
    print(f"{ordenador}\n")

    # Personas por nombre
    print("=== Personas por Nombre ===")
    resultado = ordenador.ordenar_por_nombre()
    print(f"Por nombre: {[str(p) for p in resultado]}")
