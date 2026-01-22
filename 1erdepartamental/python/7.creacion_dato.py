# ============================================
# PROGRAMA: Creación de Tipos de Datos
# DESCRIPCIÓN: Modela entidades del mundo real con POO
# ============================================


class Persona:
    """
    Representa una persona con encapsulación completa.

    __str__ define cómo se imprime el objeto
    """

    def __init__(self, nombre, ap, am, genero, edad):
        self.__nombre = nombre
        self.__ap = ap
        self.__am = am
        self.__genero = genero
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

    def nombre_completo(self):
        return f"{self.__nombre} {self.__ap} {self.__am}"

    def __str__(self):
        """Representación legible para print()"""
        return f"{self.nombre_completo()}, {self.__edad} años"

    def __repr__(self):
        """Representación técnica para debugging"""
        return f"Persona('{self.__nombre}', '{self.__ap}', '{self.__am}', '{self.__genero}', {self.__edad})"


class Auto:
    """Representa un automóvil con formateo de precio"""

    def __init__(self, marca, modelo, precio, anio):
        self.__marca = marca
        self.__modelo = modelo
        self.__precio = 0
        self.__anio = anio
        self.precio = precio  # Usa setter

    @property
    def precio(self):
        return self.__precio

    @precio.setter
    def precio(self, valor):
        if valor < 0:
            raise ValueError("El precio no puede ser negativo")
        self.__precio = valor

    def __str__(self):
        """Formatea precio con separadores de miles"""
        return f"{self.__marca} {self.__modelo} ({self.__anio}) - ${self.__precio:,.2f}"

    def __repr__(self):
        return (
            f"Auto('{self.__marca}', '{self.__modelo}', {self.__precio}, {self.__anio})"
        )


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    p = Persona("Hugo", "Dominguez", "Lopez", "M", 19)
    print(p)
    print(repr(p))

    print()

    a = Auto("Honda", "Civic", 350000, 2022)
    print(a)
    print(repr(a))
