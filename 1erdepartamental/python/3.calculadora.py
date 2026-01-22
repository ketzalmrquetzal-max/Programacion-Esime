# ============================================
# PROGRAMA: Calculadora con POO
# DESCRIPCIÓN: Calculadora con principios SOLID
# ============================================

from abc import ABC, abstractmethod
from enum import Enum, auto
from decimal import Decimal


class TipoOperacion(Enum):
    """Operaciones disponibles"""

    SUMA = auto()
    RESTA = auto()
    MULTIPLICACION = auto()
    DIVISION = auto()


class ErrorCalculadora(Exception):
    """Excepción base para errores de calculadora"""

    pass


class ErrorDivisionPorCero(ErrorCalculadora):
    """Excepción para división por cero"""

    pass


class ICalculadora(ABC):
    """Interfaz para calculadoras"""

    @abstractmethod
    def calcular(self, operacion, a, b):
        pass

    @property
    @abstractmethod
    def resultado(self):
        pass


class Calculadora(ICalculadora):
    """
    Calculadora con operaciones aritméticas básicas.

    ENCAPSULACIÓN: Atributos privados con __
    VALIDACIÓN: En todas las operaciones
    PRINCIPIOS SOLID aplicados
    """

    MAX_VALOR = Decimal("1e308")
    MIN_VALOR = Decimal("-1e308")

    def __init__(self):
        self.__resultado = Decimal("0")
        self.__historial = []
        self.__usar_decimal = False

    @property
    def resultado(self):
        return float(self.__resultado) if not self.__usar_decimal else self.__resultado

    @property
    def historial(self):
        return self.__historial.copy()

    @property
    def usar_decimal(self):
        return self.__usar_decimal

    @usar_decimal.setter
    def usar_decimal(self, valor):
        """Activa/desactiva precisión decimal"""
        if not isinstance(valor, bool):
            raise TypeError("usar_decimal debe ser booleano")
        self.__usar_decimal = valor

    def _convertir_a_decimal(self, valor):
        if isinstance(valor, Decimal):
            return valor
        return Decimal(str(valor))

    def _validar_operandos(self, a, b):
        """Valida tipos y rangos"""
        if not isinstance(a, (int, float, Decimal)):
            raise TypeError(f"Operando 'a' debe ser numérico")
        if not isinstance(b, (int, float, Decimal)):
            raise TypeError(f"Operando 'b' debe ser numérico")

        a_dec = self._convertir_a_decimal(a)
        b_dec = self._convertir_a_decimal(b)

        if not (self.MIN_VALOR <= a_dec <= self.MAX_VALOR):
            raise ValueError(f"Operando 'a' fuera de rango")
        if not (self.MIN_VALOR <= b_dec <= self.MAX_VALOR):
            raise ValueError(f"Operando 'b' fuera de rango")

        return a_dec, b_dec

    def _registrar_operacion(self, op, a, b, res):
        self.__historial.append((op, a, b, res))

    def sumar(self, a, b):
        a_dec, b_dec = self._validar_operandos(a, b)
        self.__resultado = a_dec + b_dec
        resultado = self.resultado
        self._registrar_operacion(TipoOperacion.SUMA, a, b, resultado)
        return resultado

    def restar(self, a, b):
        a_dec, b_dec = self._validar_operandos(a, b)
        self.__resultado = a_dec - b_dec
        resultado = self.resultado
        self._registrar_operacion(TipoOperacion.RESTA, a, b, resultado)
        return resultado

    def multiplicar(self, a, b):
        a_dec, b_dec = self._validar_operandos(a, b)
        self.__resultado = a_dec * b_dec
        resultado = self.resultado
        self._registrar_operacion(TipoOperacion.MULTIPLICACION, a, b, resultado)
        return resultado

    def dividir(self, a, b):
        a_dec, b_dec = self._validar_operandos(a, b)

        if b_dec == 0:
            raise ErrorDivisionPorCero("No se puede dividir por cero")

        self.__resultado = a_dec / b_dec
        resultado = self.resultado
        self._registrar_operacion(TipoOperacion.DIVISION, a, b, resultado)
        return resultado

    def calcular(self, operacion, a, b):
        """Patrón Strategy: selecciona operación según tipo"""
        if operacion == TipoOperacion.SUMA:
            return self.sumar(a, b)
        elif operacion == TipoOperacion.RESTA:
            return self.restar(a, b)
        elif operacion == TipoOperacion.MULTIPLICACION:
            return self.multiplicar(a, b)
        elif operacion == TipoOperacion.DIVISION:
            return self.dividir(a, b)
        else:
            raise ValueError(f"Operación no soportada")

    def limpiar_historial(self):
        self.__historial.clear()

    def reiniciar(self):
        self.__resultado = Decimal("0")
        self.limpiar_historial()

    def __str__(self):
        return f"Calculadora(resultado={self.resultado})"

    def __repr__(self):
        return f"Calculadora(operaciones={len(self.__historial)})"


# ============================================
# EJECUCIÓN
# ============================================
if __name__ == "__main__":
    print("=== Calculadora con POO ===\n")

    c = Calculadora()

    # Operaciones básicas
    print("Operaciones básicas:")
    print(f"10 + 5 = {c.sumar(10, 5)}")
    print(f"10 - 5 = {c.restar(10, 5)}")
    print(f"10 * 5 = {c.multiplicar(10, 5)}")
    print(f"10 / 5 = {c.dividir(10, 5)}\n")

    # Historial
    print("Historial:")
    for op, a, b, res in c.historial:
        print(f"  {op.name}: {a} y {b} = {res}")
    print()

    # Manejo de errores
    try:
        c.dividir(10, 0)
    except ErrorDivisionPorCero as e:
        print(f"Error: {e}\n")

    # Precisión decimal
    c.usar_decimal = True
    print(f"1 / 3 con precisión = {c.dividir(1, 3)}\n")

    # Método genérico
    print(f"Suma genérica: {c.calcular(TipoOperacion.SUMA, 25, 15)}")
    print(f"Multiplicación genérica: {c.calcular(TipoOperacion.MULTIPLICACION, 7, 8)}")
