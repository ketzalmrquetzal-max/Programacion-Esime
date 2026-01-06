class CalculadoraSobrecarga:
    def __init__(self):
        self.resultado = 0

    def sumar(self, a=0, b=0, c=0):
        self.resultado = a + b + c
        return self.resultado

    def restar(self, a=0, b=0, c=0):
        self.resultado = a - b - c
        return self.resultado

    def multiplicar(self, a=1, b=1, c=1):
        self.resultado = a * b * c
        return self.resultado

    def dividir(self, a=1, b=1, c=1):
        if b != 0 and c != 0:
            self.resultado = a / b / c
            return self.resultado
        return None


if __name__ == "__main__":
    c = CalculadoraSobrecarga()
    print(f"sumar() = {c.sumar()}")
    print(f"sumar(5, 3) = {c.sumar(5, 3)}")
    print(f"sumar(5, 3, 2) = {c.sumar(5, 3, 2)}")
    print(f"multiplicar(4, 5) = {c.multiplicar(4, 5)}")
    print(f"multiplicar(4, 5, 2) = {c.multiplicar(4, 5, 2)}")
