# ============================================
# PROGRAMA: Sobrecarga de Métodos con POO
# DESCRIPCIÓN: Simula sobrecarga usando parámetros por defecto
# ============================================

from abc import ABC, abstractmethod


class IOperadorFlexible(ABC):
    """Interfaz para operadores que aceptan cantidad variable de argumentos"""

    @abstractmethod
    def operar(self, *args):
        pass


class CalculadoraSobrecarga(IOperadorFlexible):
    """
    Simula sobrecarga de métodos con parámetros por defecto.

    Python no soporta sobrecarga nativa, pero se simula con defaults.
    """

    VALOR_DEFECTO = 0
    MULTIPLICADOR_DEFECTO = 1

    def __init__(self):
        self.__resultado = 0

    @property
    def resultado(self):
        return self.__resultado

    def sumar(self, a=VALOR_DEFECTO, b=VALOR_DEFECTO, c=VALOR_DEFECTO):
        """Suma 1, 2 o 3 números"""
        self.__resultado = a + b + c
        return self.__resultado

    def restar(self, a=VALOR_DEFECTO, b=VALOR_DEFECTO, c=VALOR_DEFECTO):
        """Resta sucesiva: a - b - c"""
        self.__resultado = a - b - c
        return self.__resultado

    def multiplicar(
        self, a=MULTIPLICADOR_DEFECTO, b=MULTIPLICADOR_DEFECTO, c=MULTIPLICADOR_DEFECTO
    ):
        """Multiplica 1, 2 o 3 números"""
        self.__resultado = a * b * c
        return self.__resultado

    def dividir(
        self, a=MULTIPLICADOR_DEFECTO, b=MULTIPLICADOR_DEFECTO, c=MULTIPLICADOR_DEFECTO
    ):
        """División sucesiva con validación"""
        if b != 0 and c != 0:
            self.__resultado = a / b / c
            return self.__resultado
        return None

    def operar(self, *args):
        """Suma cantidad variable de argumentos"""
        return sum(args)

    def __str__(self):
        return f"CalculadoraSobrecarga(resultado={self.__resultado})"


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    c = CalculadoraSobrecarga()

    # Demuestra "sobrecarga" con diferente cantidad de argumentos
    print(f"sumar() = {c.sumar()}")
    print(f"sumar(5, 3) = {c.sumar(5, 3)}")
    print(f"sumar(5, 3, 2) = {c.sumar(5, 3, 2)}")

    print(f"\nmultiplicar(4, 5) = {c.multiplicar(4, 5)}")
    print(f"multiplicar(4, 5, 2) = {c.multiplicar(4, 5, 2)}")

    print(f"\noperar(1, 2, 3, 4, 5) = {c.operar(1, 2, 3, 4, 5)}")
