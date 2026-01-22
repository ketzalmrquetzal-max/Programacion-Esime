from abc import ABC, abstractmethod
import cmath


class CalculadoraBase(ABC):
    def __init__(self):
        self.resultado = 0

    @abstractmethod
    def operar(self, a, b):
        pass

    def sumar(self, a, b):
        self.resultado = a + b
        return self.resultado

    def restar(self, a, b):
        self.resultado = a - b
        return self.resultado

    def multiplicar(self, a, b):
        self.resultado = a * b
        return self.resultado

    def dividir(self, a, b):
        if b != 0:
            self.resultado = a / b
            return self.resultado
        return None


class CalculadoraCientifica(CalculadoraBase):
    def __init__(self):
        super().__init__()
        self.memoria = 0

    def operar(self, a, b):
        return self.sumar(a, b)

    def potencia(self, base, exp):
        self.resultado = base**exp
        return self.resultado

    def raiz_cuadrada(self, n):
        self.resultado = cmath.sqrt(n)
        return self.resultado

    def logaritmo(self, n):
        self.resultado = cmath.log(n)
        return self.resultado

    def seno(self, angulo):
        self.resultado = cmath.sin(angulo)
        return self.resultado

    def coseno(self, angulo):
        self.resultado = cmath.cos(angulo)
        return self.resultado


class CalculadoraFinanciera(CalculadoraBase):
    def operar(self, a, b):
        return self.multiplicar(a, b)

    def interes_simple(self, capital, tasa, tiempo):
        self.resultado = capital * (tasa / 100) * tiempo
        return self.resultado

    def interes_compuesto(self, capital, tasa, tiempo):
        self.resultado = capital * (1 + tasa / 100) ** tiempo
        return self.resultado


if __name__ == "__main__":
    cc = CalculadoraCientifica()
    print(f"Suma: {cc.sumar(10, 5)}")
    print(f"Potencia 2^8: {cc.potencia(2, 8)}")
    print(f"Raiz de 144: {cc.raiz_cuadrada(144)}")
    print(f"Logaritmo de 100: {cc.logaritmo(100)}")

    cf = CalculadoraFinanciera()
    print(f"Interes simple: {cf.interes_simple(10000, 5, 2)}")
