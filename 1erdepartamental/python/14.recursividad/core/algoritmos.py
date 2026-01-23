# Algoritmos recursivos


class AlgoritmosRecursivos:
    def factorial(self, n):
        if n < 0:
            raise ValueError("n debe ser >= 0")
        if n == 0:  # Caso base: detiene la recursión
            return 1
        return n * self.factorial(n - 1)  # Caso recursivo: se llama a sí mismo

    def fibonacci(self, n):
        if n < 0:
            raise ValueError("n debe ser >= 0")
        if n <= 1:
            return n
        return self.fibonacci(n - 1) + self.fibonacci(n - 2)

    def suma_hasta(self, n):
        if n < 1:
            raise ValueError("n debe ser >= 1")
        if n == 1:
            return 1
        return n + self.suma_hasta(n - 1)

    def potencia(self, base, exp):
        if exp < 0:
            raise ValueError("exp debe ser >= 0")
        if exp == 0:
            return 1
        return base * self.potencia(base, exp - 1)
