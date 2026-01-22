# ============================================
# PROGRAMA: Herencia de Clases
# DESCRIPCIÓN: Implementa herencia simple con clases abstractas
# ============================================

from abc import ABC, abstractmethod  # ABC = Abstract Base Class
import cmath  # Matemáticas complejas


class CalculadoraBase(ABC):
    """
    Clase abstracta base para calculadoras.

    Una clase abstracta (ABC) define una interfaz que las clases hijas deben implementar.
    No se puede instanciar directamente, solo se puede heredar.
    """

    def __init__(self):
        """
        Constructor de la clase base.
        Inicializa el atributo resultado.
        """
        self.resultado = 0

    @abstractmethod
    def operar(self, a, b):
        """
        Método abstracto que debe ser implementado por las clases hijas.

        El decorador @abstractmethod obliga a las clases que hereden
        de CalculadoraBase a implementar este método.

        Parámetros:
            a: Primer operando
            b: Segundo operando
        """
        pass

    def sumar(self, a, b):
        """
        Suma dos números.
        Este método es heredado por todas las clases hijas.
        """
        self.resultado = a + b
        return self.resultado

    def restar(self, a, b):
        """Resta dos números."""
        self.resultado = a - b
        return self.resultado

    def multiplicar(self, a, b):
        """Multiplica dos números."""
        self.resultado = a * b
        return self.resultado

    def dividir(self, a, b):
        """
        Divide dos números con validación.

        Returns:
            float: El resultado de a / b
            None: Si b es 0
        """
        if b != 0:
            self.resultado = a / b
            return self.resultado
        return None


class CalculadoraCientifica(CalculadoraBase):
    """
    Calculadora especializada en operaciones científicas.
    Hereda de CalculadoraBase e implementa funciones matemáticas avanzadas.
    """

    def __init__(self):
        """
        Constructor de CalculadoraCientifica.

        super().__init__() llama al constructor de la clase padre (CalculadoraBase)
        para inicializar el atributo 'resultado'.
        """
        super().__init__()  # Llama al constructor de la clase padre
        self.memoria = 0  # Atributo adicional específico de esta clase

    def operar(self, a, b):
        """
        Implementación del método abstracto.
        En este caso, realiza una suma.
        """
        return self.sumar(a, b)

    def potencia(self, base, exp):
        """
        Calcula la potencia de un número.

        Parámetros:
            base: Base de la potencia
            exp: Exponente

        Returns:
            float: base^exp
        """
        self.resultado = base**exp
        return self.resultado

    def raiz_cuadrada(self, n):
        """
        Calcula la raíz cuadrada usando números complejos.
        Permite calcular raíces de números negativos.

        Returns:
            complex: Raíz cuadrada (puede ser compleja)
        """
        self.resultado = cmath.sqrt(n)
        return self.resultado

    def logaritmo(self, n):
        """
        Calcula el logaritmo natural (base e).

        Returns:
            complex: ln(n)
        """
        self.resultado = cmath.log(n)
        return self.resultado

    def seno(self, angulo):
        """
        Calcula el seno de un ángulo (en radianes).
        """
        self.resultado = cmath.sin(angulo)
        return self.resultado

    def coseno(self, angulo):
        """
        Calcula el coseno de un ángulo (en radianes).
        """
        self.resultado = cmath.cos(angulo)
        return self.resultado


class CalculadoraFinanciera(CalculadoraBase):
    """
    Calculadora especializada en cálculos financieros.
    Hereda de CalculadoraBase e implementa funciones de interés.
    """

    def operar(self, a, b):
        """
        Implementación del método abstracto.
        En este caso, realiza una multiplicación.
        """
        return self.multiplicar(a, b)

    def interes_simple(self, capital, tasa, tiempo):
        """
        Calcula el interés simple.

        Fórmula: I = C * (r/100) * t

        Parámetros:
            capital: Capital inicial
            tasa: Tasa de interés anual (porcentaje)
            tiempo: Tiempo en años

        Returns:
            float: Interés generado
        """
        self.resultado = capital * (tasa / 100) * tiempo
        return self.resultado

    def interes_compuesto(self, capital, tasa, tiempo):
        """
        Calcula el monto final con interés compuesto.

        Fórmula: M = C * (1 + r/100)^t

        Parámetros:
            capital: Capital inicial
            tasa: Tasa de interés anual (porcentaje)
            tiempo: Tiempo en años

        Returns:
            float: Monto final (capital + interés)
        """
        self.resultado = capital * (1 + tasa / 100) ** tiempo
        return self.resultado


# ============================================
# BLOQUE DE EJECUCIÓN PRINCIPAL
# ============================================
if __name__ == "__main__":
    # Prueba de CalculadoraCientifica
    cc = CalculadoraCientifica()
    print(f"Suma: {cc.sumar(10, 5)}")  # Método heredado
    print(f"Potencia 2^8: {cc.potencia(2, 8)}")  # Método propio
    print(f"Raiz de 144: {cc.raiz_cuadrada(144)}")
    print(f"Logaritmo de 100: {cc.logaritmo(100)}")

    # Prueba de CalculadoraFinanciera
    cf = CalculadoraFinanciera()
    print(
        f"Interes simple: {cf.interes_simple(10000, 5, 2)}"
    )  # $10,000 al 5% por 2 años
