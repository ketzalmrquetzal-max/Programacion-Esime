class CalculadoraRecursiva:
    def __init__(self):
        self.resultado = 0

    def factorial(self, n):
        if n <= 1:
            return 1
        return n * self.factorial(n - 1)

    def fibonacci(self, n):
        if n <= 0:
            return 0
        if n == 1:
            return 1
        return self.fibonacci(n - 1) + self.fibonacci(n - 2)

    def sumar(self, a, b):
        if b == 0:
            return a
        return self.sumar(a + 1, b - 1) if b > 0 else self.sumar(a - 1, b + 1)

    def multiplicar(self, a, b):
        if b == 0:
            return 0
        if b > 0:
            return a + self.multiplicar(a, b - 1)
        return -self.multiplicar(a, -b)

    def potencia(self, base, exp):
        if exp == 0:
            return 1
        return base * self.potencia(base, exp - 1)


if __name__ == "__main__":
    c = CalculadoraRecursiva()
    print(f"5! = {c.factorial(5)}")
    print(f"F(10) = {c.fibonacci(10)}")
    print(f"5 + 3 = {c.sumar(5, 3)}")
    print(f"4 * 5 = {c.multiplicar(4, 5)}")
    print(f"2^8 = {c.potencia(2, 8)}")
