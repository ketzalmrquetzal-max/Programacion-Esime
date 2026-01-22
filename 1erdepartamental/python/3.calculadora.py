class Calculadora:
    def __init__(self):
        self.resultado = 0

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


if __name__ == "__main__":
    c = Calculadora()
    print(f"10 + 5 = {c.sumar(10, 5)}")
    print(f"10 - 5 = {c.restar(10, 5)}")
    print(f"10 * 5 = {c.multiplicar(10, 5)}")
    print(f"10 / 5 = {c.dividir(10, 5)}")
