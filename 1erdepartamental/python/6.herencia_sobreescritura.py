from abc import ABC, abstractmethod
import cmath


class CalculadoraBase(ABC):
    def __init__(self):
        self.resultado = 0

    @abstractmethod
    def multiplicar(self, a, b):
        pass

    @abstractmethod
    def potencia(self, base, exp):
        pass

    @abstractmethod
    def dividir(self, a, b):
        pass


class CalculadoraDirecta(CalculadoraBase):
    def multiplicar(self, a, b):
        self.resultado = a * b
        return self.resultado

    def potencia(self, base, exp):
        self.resultado = cmath.exp(exp * cmath.log(base)) if base > 0 else base**exp
        return self.resultado

    def dividir(self, a, b):
        self.resultado = a / b if b != 0 else None
        return self.resultado


class CalculadoraSucesiva(CalculadoraBase):
    def multiplicar(self, a, b):
        self.resultado = 0
        for _ in range(abs(int(b))):
            self.resultado += abs(a)
        if (a < 0) != (b < 0):
            self.resultado = -self.resultado
        return self.resultado

    def potencia(self, base, exp):
        self.resultado = 1
        for _ in range(abs(int(exp))):
            temp = 0
            for _ in range(abs(int(base))):
                temp += abs(self.resultado)
            self.resultado = temp
        return self.resultado

    def dividir(self, a, b):
        if b == 0:
            return None
        cociente = 0
        residuo = abs(a)
        while residuo >= abs(b):
            residuo -= abs(b)
            cociente += 1
        self.resultado = cociente if (a >= 0) == (b >= 0) else -cociente
        return self.resultado, residuo


if __name__ == "__main__":
    cd = CalculadoraDirecta()
    print(f"Directa: 4*5 = {cd.multiplicar(4, 5)}")
    print(f"Directa: 2^4 = {cd.potencia(2, 4)}")

    cs = CalculadoraSucesiva()
    print(f"Sucesiva: 4*5 = {cs.multiplicar(4, 5)}")
    print(f"Sucesiva: 17/5 = {cs.dividir(17, 5)}")
