# ============================================
# PROGRAMA: Suma con Parámetros y POO
# DESCRIPCIÓN: Operaciones con encapsulación completa
# ============================================

from abc import ABC, abstractmethod


class IOperadorMatematico(ABC):
    """
    Interfaz para operadores matemáticos.

    ABSTRACCIÓN: Define contrato sin implementación
    """

    @abstractmethod
    def operar(self):
        pass

    @abstractmethod
    def reiniciar(self):
        pass


class Sumador(IOperadorMatematico):
    """
    Sumador con validación y encapsulación completa.

    ENCAPSULACIÓN: Atributos privados con __
    VALIDACIÓN: Properties con setters
    """

    VALOR_DEFECTO = 0
    MIN_VALOR = -1_000_000
    MAX_VALOR = 1_000_000

    def __init__(self, a=VALOR_DEFECTO, b=VALOR_DEFECTO):
        self.__a = self.VALOR_DEFECTO
        self.__b = self.VALOR_DEFECTO
        self.__historial = []

        # Usa properties para validación
        self.a = a
        self.b = b

    @property
    def a(self):
        return self.__a

    @a.setter
    def a(self, valor):
        """Valida tipo y rango"""
        if not isinstance(valor, (int, float)):
            raise TypeError(f"Se esperaba número, recibido {type(valor).__name__}")
        if not (self.MIN_VALOR <= valor <= self.MAX_VALOR):
            raise ValueError(f"Valor fuera de rango")
        self.__a = valor

    @property
    def b(self):
        return self.__b

    @b.setter
    def b(self, valor):
        if not isinstance(valor, (int, float)):
            raise TypeError(f"Se esperaba número, recibido {type(valor).__name__}")
        if not (self.MIN_VALOR <= valor <= self.MAX_VALOR):
            raise ValueError(f"Valor fuera de rango")
        self.__b = valor

    @property
    def historial(self):
        """Retorna copia para evitar modificaciones externas"""
        return self.__historial.copy()

    def operar(self):
        """Implementa interfaz IOperadorMatematico"""
        return self.sumar()

    def sumar(self):
        """Suma y guarda en historial"""
        resultado = self.__a + self.__b
        self.__historial.append(resultado)
        return resultado

    def establecer(self, a, b):
        """Modifica ambos valores (usa setters para validación)"""
        self.a = a
        self.b = b

    def reiniciar(self):
        self.__a = self.VALOR_DEFECTO
        self.__b = self.VALOR_DEFECTO
        self.__historial.clear()

    @classmethod
    def desde_lista(cls, valores):
        """Factory method: constructor alternativo"""
        if len(valores) < 2:
            raise ValueError("Se requieren al menos 2 valores")
        return cls(valores[0], valores[1])

    def __add__(self, otro):
        """Sobrecarga del operador +"""
        if isinstance(otro, Sumador):
            return self.sumar() + otro.sumar()
        elif isinstance(otro, (int, float)):
            return self.sumar() + otro
        return NotImplemented

    def __str__(self):
        return f"{self.__a} + {self.__b} = {self.sumar()}"

    def __repr__(self):
        return f"Sumador(a={self.__a}, b={self.__b})"

    def __eq__(self, otro):
        if not isinstance(otro, Sumador):
            return NotImplemented
        return self.__a == otro.__a and self.__b == otro.__b


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    print("=== Sumador con POO ===\n")

    # Básico
    s = Sumador(10, 25)
    print(f"{s}")
    print(f"repr: {repr(s)}\n")

    # Modificación
    s.establecer(100, 200)
    print(f"{s}\n")

    # Properties
    print(f"a = {s.a}, b = {s.b}\n")

    # Validación
    try:
        s.a = "texto"
    except TypeError as e:
        print(f"Error: {e}\n")

    # Historial
    s.establecer(5, 3)
    s.sumar()
    s.establecer(10, 20)
    s.sumar()
    print(f"Historial: {s.historial}\n")

    # Factory method
    s2 = Sumador.desde_lista([50, 75])
    print(f"{s2}\n")

    # Operadores
    s1 = Sumador(5, 10)
    s2 = Sumador(3, 7)
    print(f"s1 + s2 = {s1 + s2}")
    print(f"s1 + 100 = {s1 + 100}")
