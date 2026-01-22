# ============================================
# PROGRAMA: Arreglos de Tipos Personalizados
# DESCRIPCIÓN: Listas especializadas para objetos
# ============================================


class Persona:
    """Representa una persona"""

    def __init__(self, nombre, ap, am, genero, edad):
        self.__nombre = nombre
        self.__ap = ap
        self.__am = am
        self.__genero = genero
        self.__edad = edad

    @property
    def nombre(self):
        return self.__nombre

    @property
    def edad(self):
        return self.__edad

    def __str__(self):
        return f"{self.__nombre} {self.__ap}, {self.__edad} años"


class Coche:
    """Representa un coche"""

    def __init__(self, marca, modelo, precio, anio):
        self.__marca = marca
        self.__modelo = modelo
        self.__precio = precio
        self.__anio = anio

    @property
    def marca(self):
        return self.__marca

    def __str__(self):
        return f"{self.__marca} {self.__modelo} ({self.__anio})"


class ListaPersonas:
    """
    Contenedor especializado para personas.

    Patrón Collection: Encapsula lista con métodos específicos
    """

    def __init__(self):
        self.__personas = []

    @property
    def personas(self):
        return self.__personas.copy()

    def agregar(self, persona):
        """Podría validar que sea instancia de Persona"""
        self.__personas.append(persona)

    def mostrar(self):
        for i, p in enumerate(self.__personas):
            print(f"[{i}] {p}")


class ListaCoches:
    """Contenedor especializado para coches"""

    def __init__(self):
        self.__coches = []

    @property
    def coches(self):
        return self.__coches.copy()

    def agregar(self, coche):
        self.__coches.append(coche)

    def mostrar(self):
        for i, c in enumerate(self.__coches):
            print(f"[{i}] {c}")


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    lp = ListaPersonas()
    lp.agregar(Persona("Juan", "Perez", "Garcia", "M", 25))
    lp.agregar(Persona("Maria", "Lopez", "Sanchez", "F", 30))
    print("Personas:")
    lp.mostrar()

    print()

    lc = ListaCoches()
    lc.agregar(Coche("Honda", "Civic", 350000, 2022))
    lc.agregar(Coche("Toyota", "Corolla", 320000, 2021))
    print("Coches:")
    lc.mostrar()
